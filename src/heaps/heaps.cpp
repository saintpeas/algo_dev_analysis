#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Structure for patient
struct Patient {
    string name;
    int priority;  // Lower number means higher medical priority (1 = most urgent)
    Patient(string n, int p) : name(n), priority(p) {}
};

// Min-Heap for ER prioritization
class ERPriority {
private:
    vector<Patient> heap;

    // Get parent, left, and right child indices
    int parent(int index) { return (index - 1) / 2; }
    int leftChild(int index) { return 2 * index + 1; }
    int rightChild(int index) { return 2 * index + 2; }

    // Heapify up
    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)].priority > heap[index].priority) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    // Heapify down
    void heapifyDown(int index) {
        int minIndex = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < heap.size() && heap[left].priority < heap[minIndex].priority) {
            minIndex = left;
        }
        if (right < heap.size() && heap[right].priority < heap[minIndex].priority) {
            minIndex = right;
        }
        if (index != minIndex) {
            swap(heap[index], heap[minIndex]);
            heapifyDown(minIndex);
        }
    }

public:
    // Insert patient
    void insert(string name, int priority) {
        heap.push_back(Patient(name, priority));
        heapifyUp(heap.size() - 1);
        cout << "Added patient: " << name << " (Priority Level: " << priority << ") - ";
        
        // Provide context for the priority level
        if (priority == 1) {
            cout << "Immediate care needed\n";
        } else if (priority == 2) {
            cout << "Very urgent\n";
        } else if (priority == 3) {
            cout << "Urgent\n";
        } else if (priority == 4) {
            cout << "Standard care\n";
        } else {
            cout << "Non-urgent\n";
        }
    }

    // Extract highest priority patient (lowest number)
    void extractMin() {
        if (heap.empty()) {
            cout << "No patients in queue!\n";
            return;
        }
        cout << "Treating: " << heap[0].name << " (Priority Level: " << heap[0].priority << ")\n";
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
    }

    // Display heap
    void displayHeap() {
        if (heap.empty()) {
            cout << "No patients in queue!\n";
            return;
        }
        cout << "\n===== ER Priority Queue =====\n";
        cout << "Priority scale: 1 (most urgent) to 5 (least urgent)\n";
        for (size_t i = 0; i < heap.size(); i++) {
            cout << i+1 << ". Patient: " << heap[i].name << ", Priority Level: " << heap[i].priority;
            
            // Add context for each priority level
            if (heap[i].priority == 1) {
                cout << " (Immediate care)";
            } else if (heap[i].priority == 2) {
                cout << " (Very urgent)";
            } else if (heap[i].priority == 3) {
                cout << " (Urgent)";
            } else if (heap[i].priority == 4) {
                cout << " (Standard)";
            } else {
                cout << " (Non-urgent)";
            }
            cout << "\n";
        }
        cout << "========================\n\n";
    }
};

// Display menu
void displayMenu() {
    cout << "\n===== ER Priority Queue Menu =====\n";
    cout << "1. Add new patient\n";
    cout << "2. Treat highest priority patient\n";
    cout << "3. Display all patients\n";
    cout << "4. Exit\n";
    cout << "Enter your choice (1-4): ";
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    ERPriority er;
    int choice, priority;
    string name;
    bool running = true;

    cout << "Welcome to the ER Priority Queue System (Min-Heap Version)!\n";
    cout << "Priority scale: 1 (most urgent) to 5 (least urgent)\n";

    while (running) {
        displayMenu();
        
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:  
                cout << "Enter patient name: ";
                getline(cin, name);
                cout << "Enter priority level (1=critical, 2=very urgent, 3=urgent, 4=standard, 5=non-urgent): ";
                if (!(cin >> priority) || priority < 1 || priority > 5) {
                    cout << "Invalid priority. Using default priority 3 (urgent).\n";
                    clearInputBuffer();
                    priority = 3;
                } else {
                    clearInputBuffer();
                }
                er.insert(name, priority);
                break;
                
            case 2:  
                er.extractMin();
                break;
                
            case 3: 
                er.displayHeap();
                break;
                
            case 4:
                cout << "Exiting ER Priority System. Goodbye!\n";
                running = false;
                break;
                
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }

    return 0;
} 