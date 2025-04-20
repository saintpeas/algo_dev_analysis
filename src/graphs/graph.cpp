#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <string>
#include <climits>
#include <algorithm>
#include <iomanip>

using namespace std;

class MetroManilaNavigation {
private:
    // Maps location ID to location name
    map<int, string> locationNames;

    // Maps location name to location ID
    map<string, int> locationIds;

    // Adjacency list: location ID -> [(neighbor ID, travel_time)]
    unordered_map<int, vector<pair<int, int>>> adjList;

    bool isDirected;
    int nextLocationId;

public:
    MetroManilaNavigation(bool directed = true) : isDirected(directed), nextLocationId(0) {
        // Initialize default Metro Manila locations
        addLocation("Makati");        // 0
        addLocation("BGC");           // 1
        addLocation("Ortigas");       // 2
        addLocation("Quezon City");   // 3
        addLocation("Manila");        // 4
        addLocation("Pasay");         // 5
        addLocation("Mandaluyong");   // 6
        addLocation("San Juan");      // 7
        addLocation("Caloocan");      // 8
        addLocation("Parañaque");     // 9
        addLocation("NAIA");          // 10
    }

    int addLocation(const string& name) {
        // Check if location already exists
        if (locationIds.find(name) != locationIds.end()) {
            cout << "Location '" << name << "' already exists with ID " << locationIds[name] << endl;
            return locationIds[name];
        }

        int id = nextLocationId++;
        locationNames[id] = name;
        locationIds[name] = id;
        cout << "Added location: " << name << " (ID: " << id << ")\n";
        return id;
    }

    void addRoad(int from, int to, int travel_time = 1) {
        if (locationNames.find(from) == locationNames.end() ||
            locationNames.find(to) == locationNames.end()) {
            cout << "Invalid location IDs. Please try again." << endl;
        return;
            }

            adjList[from].push_back({to, travel_time});
            if (!isDirected) {
                adjList[to].push_back({from, travel_time});
            }
            cout << "Added road: " << locationNames[from] << " to " << locationNames[to]
            << " (" << travel_time << " min)\n";
    }

    void addRoadByName(const string& from, const string& to, int travel_time = 1) {
        if (locationIds.find(from) == locationIds.end() ||
            locationIds.find(to) == locationIds.end()) {
            cout << "One or both locations don't exist. Please add them first." << endl;
        return;
            }

            addRoad(locationIds[from], locationIds[to], travel_time);
    }

    void printMap() {
        cout << "\n===== METRO MANILA NAVIGATION MAP =====\n";
        cout << string(40, '-') << endl;
        cout << left << setw(15) << "LOCATION" << " | "
        << left << setw(30) << "CONNECTIONS (Destination, Time)" << endl;
        cout << string(40, '-') << endl;

        for (const auto& location : locationNames) {
            cout << left << setw(15) << location.second << " | ";

            if (adjList.find(location.first) != adjList.end()) {
                bool first = true;
                for (const auto& neighbor : adjList[location.first]) {
                    if (!first) cout << ", ";
                    cout << locationNames[neighbor.first] << " (" << neighbor.second << "m)";
                    first = false;
                }
            } else {
                cout << "No connections";
            }
            cout << endl;
        }
        cout << string(40, '-') << endl;
    }

    vector<int> shortestRoute(int start, int end) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> dist;
        unordered_map<int, int> prev;

        for (const auto& location : locationNames) {
            dist[location.first] = INT_MAX;
            prev[location.first] = -1;
        }

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (u == end) break;

            if (adjList.find(u) != adjList.end()) {
                for (const auto& neighbor : adjList[u]) {
                    int v = neighbor.first;
                    int travel_time = neighbor.second;

                    if (dist[u] + travel_time < dist[v]) {
                        dist[v] = dist[u] + travel_time;
                        prev[v] = u;
                        pq.push({dist[v], v});
                    }
                }
            }
        }

        vector<int> route;
        for (int at = end; at != -1; at = prev[at]) {
            route.push_back(at);
        }
        reverse(route.begin(), route.end());

        if (route.size() <= 1) {
            return {};
        }

        cout << "\nShortest route travel time: " << dist[end] << " minutes\n";
        return route;
    }

    vector<int> shortestRouteByName(const string& start, const string& end) {
        if (locationIds.find(start) == locationIds.end() ||
            locationIds.find(end) == locationIds.end()) {
            cout << "One or both locations don't exist." << endl;
        return {};
            }

            return shortestRoute(locationIds[start], locationIds[end]);
    }

    // Fixed longestRoute method
    vector<int> longestRoute(int start, int end) {
        const int MAX_PATH_LENGTH = 20; // Limit to prevent infinite cycles

        // Use DP to find longest path with limited steps
        // dp[v][k] = longest path to v using at most k edges
        vector<vector<int>> dp(locationNames.size(), vector<int>(MAX_PATH_LENGTH + 1, INT_MIN));
        vector<vector<int>> parent(locationNames.size(), vector<int>(MAX_PATH_LENGTH + 1, -1));

        // Base case: distance to start is 0
        dp[start][0] = 0;

        // Fill DP table
        for (int k = 1; k <= MAX_PATH_LENGTH; k++) {
            for (const auto& u_entry : locationNames) {
                int u = u_entry.first;

                // Skip if we couldn't reach u in k-1 steps
                if (dp[u][k-1] == INT_MIN) continue;

                // Try extending path from u to its neighbors
                if (adjList.find(u) != adjList.end()) {
                    for (const auto& edge : adjList[u]) {
                        int v = edge.first;
                        int weight = edge.second;

                        // If taking edge (u,v) gives longer path to v
                        if (dp[u][k-1] != INT_MIN && dp[u][k-1] + weight > dp[v][k]) {
                            dp[v][k] = dp[u][k-1] + weight;
                            parent[v][k] = u;
                        }
                    }
                }
            }
        }

        // Find best path length
        int best_k = 0;
        for (int k = 0; k <= MAX_PATH_LENGTH; k++) {
            if (dp[end][k] > dp[end][best_k]) {
                best_k = k;
            }
        }

        // If no path found
        if (dp[end][best_k] == INT_MIN) {
            cout << "No path exists from " << locationNames[start] << " to " << locationNames[end] << endl;
            return {};
        }

        // Reconstruct the path
        vector<int> route;
        int current = end;
        int k = best_k;

        while (current != -1 && k >= 0) {
            route.push_back(current);
            if (current == start) break;
            current = parent[current][k];
            k--;
        }

        reverse(route.begin(), route.end());

        // If path is incomplete or doesn't start at the starting point
        if (route.empty() || route[0] != start) {
            return {};
        }

        cout << "\nLongest route travel time: " << dp[end][best_k] << " minutes\n";
        return route;
    }

    vector<int> longestRouteByName(const string& start, const string& end) {
        if (locationIds.find(start) == locationIds.end() ||
            locationIds.find(end) == locationIds.end()) {
            cout << "One or both locations don't exist." << endl;
        return {};
            }

            return longestRoute(locationIds[start], locationIds[end]);
    }

    bool bfs(int start, int target) {
        unordered_map<int, bool> visited;
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "\nBFS traversal path:\n";
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            cout << "Visiting: " << locationNames[u] << endl;

            if (u == target) {
                cout << "Destination " << locationNames[target] << " is reachable!\n";
                return true;
            }

            if (adjList.find(u) != adjList.end()) {
                for (const auto& neighbor : adjList[u]) {
                    int v = neighbor.first;

                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }

        cout << "Destination " << locationNames[target] << " is not reachable!\n";
        return false;
    }

    bool bfsByName(const string& start, const string& target) {
        if (locationIds.find(start) == locationIds.end() ||
            locationIds.find(target) == locationIds.end()) {
            cout << "One or both locations don't exist." << endl;
        return false;
            }

            return bfs(locationIds[start], locationIds[target]);
    }

    bool dfs(int start, int target) {
        unordered_map<int, bool> visited;
        cout << "\nDFS traversal path:\n";
        return dfsUtil(start, target, visited);
    }

    bool dfsByName(const string& start, const string& target) {
        if (locationIds.find(start) == locationIds.end() ||
            locationIds.find(target) == locationIds.end()) {
            cout << "One or both locations don't exist." << endl;
        return false;
            }

            return dfs(locationIds[start], locationIds[target]);
    }

    void printRoute(const vector<int>& route) {
        if (route.empty()) {
            cout << "No route exists\n";
            return;
        }

        cout << "Route: ";
        for (int i = 0; i < route.size(); i++) {
            cout << locationNames[route[i]];
            if (i < route.size() - 1) cout << " → ";
        }
        cout << endl;
    }

    void setupMetroManilaRoads() {
        // Setup realistic Metro Manila road connections
        // Major roads with approximate travel times in minutes
        addRoadByName("Makati", "BGC", 15);
        addRoadByName("Makati", "Mandaluyong", 20);
        addRoadByName("Makati", "Manila", 25);
        addRoadByName("Makati", "Pasay", 20);

        addRoadByName("BGC", "Makati", 15);
        addRoadByName("BGC", "Ortigas", 25);
        addRoadByName("BGC", "Pasay", 30);

        addRoadByName("Ortigas", "Mandaluyong", 10);
        addRoadByName("Ortigas", "San Juan", 15);
        addRoadByName("Ortigas", "Quezon City", 20);

        addRoadByName("Quezon City", "San Juan", 15);
        addRoadByName("Quezon City", "Manila", 30);
        addRoadByName("Quezon City", "Caloocan", 25);

        addRoadByName("Manila", "Makati", 25);
        addRoadByName("Manila", "San Juan", 20);
        addRoadByName("Manila", "Caloocan", 25);
        addRoadByName("Manila", "Pasay", 15);

        addRoadByName("Pasay", "Makati", 20);
        addRoadByName("Pasay", "Manila", 15);
        addRoadByName("Pasay", "Parañaque", 15);
        addRoadByName("Pasay", "NAIA", 10);

        addRoadByName("Parañaque", "Pasay", 15);
        addRoadByName("Parañaque", "NAIA", 10);

        addRoadByName("Mandaluyong", "Makati", 20);
        addRoadByName("Mandaluyong", "Ortigas", 10);
        addRoadByName("Mandaluyong", "San Juan", 15);

        addRoadByName("San Juan", "Mandaluyong", 15);
        addRoadByName("San Juan", "Ortigas", 15);
        addRoadByName("San Juan", "Quezon City", 15);

        addRoadByName("Caloocan", "Quezon City", 25);
        addRoadByName("Caloocan", "Manila", 25);

        addRoadByName("NAIA", "Pasay", 10);
        addRoadByName("NAIA", "Parañaque", 10);
    }

private:
    bool dfsUtil(int u, int target, unordered_map<int, bool>& visited) {
        visited[u] = true;
        cout << "Visiting: " << locationNames[u] << endl;

        if (u == target) {
            cout << "Destination " << locationNames[target] << " is reachable!\n";
            return true;
        }

        if (adjList.find(u) != adjList.end()) {
            for (const auto& neighbor : adjList[u]) {
                int v = neighbor.first;

                if (!visited[v]) {
                    if (dfsUtil(v, target, visited)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main() {
    MetroManilaNavigation metroManila;

    cout << "\n====== METRO MANILA NAVIGATION SYSTEM ======\n\n";
    cout << "Setting up Metro Manila road network...\n";
    metroManila.setupMetroManilaRoads();

    metroManila.printMap();

    string command;
    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Find shortest route\n";
        cout << "2. Find longest route\n";
        cout << "3. Check if destination is reachable (BFS)\n";
        cout << "4. Check if destination is reachable (DFS)\n";
        cout << "5. Add new location\n";
        cout << "6. Add new road\n";
        cout << "7. Display map\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";

        getline(cin, command);

        if (command == "1") {
            string start, end;
            cout << "Enter starting location: ";
            getline(cin, start);
            cout << "Enter destination: ";
            getline(cin, end);

            cout << "\nFinding shortest route from " << start << " to " << end << ":\n";
            vector<int> route = metroManila.shortestRouteByName(start, end);
            metroManila.printRoute(route);
        }
        else if (command == "2") {
            string start, end;
            cout << "Enter starting location: ";
            getline(cin, start);
            cout << "Enter destination: ";
            getline(cin, end);

            cout << "\nFinding longest route from " << start << " to " << end << ":\n";
            vector<int> route = metroManila.longestRouteByName(start, end);
            metroManila.printRoute(route);
        }
        else if (command == "3") {
            string start, end;
            cout << "Enter starting location: ";
            getline(cin, start);
            cout << "Enter destination to check: ";
            getline(cin, end);

            metroManila.bfsByName(start, end);
        }
        else if (command == "4") {
            string start, end;
            cout << "Enter starting location: ";
            getline(cin, start);
            cout << "Enter destination to check: ";
            getline(cin, end);

            metroManila.dfsByName(start, end);
        }
        else if (command == "5") {
            string name;
            cout << "Enter new location name: ";
            getline(cin, name);

            metroManila.addLocation(name);
        }
        else if (command == "6") {
            string from, to;
            int time;
            cout << "Enter starting location: ";
            getline(cin, from);
            cout << "Enter destination: ";
            getline(cin, to);
            cout << "Enter travel time (minutes): ";
            cin >> time;
            cin.ignore(); // Clear newline

            metroManila.addRoadByName(from, to, time);
        }
        else if (command == "7") {
            metroManila.printMap();
        }
        else if (command == "8") {
            cout << "Thank you for using Metro Manila Navigation System!\n";
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
