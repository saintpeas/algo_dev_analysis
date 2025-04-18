#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Node for the singly linked list
struct Song {
    string title;
    string artist;
    Song* next;
    Song(string t, string a) : title(t), artist(a), next(nullptr) {}
};

// Singly Linked List for playlist
class Playlist {
private:
    Song* head;

public:
    Playlist() : head(nullptr) {}

    // Add song to the end of the playlist
    void addSong(string title, string artist) {
        Song* newSong = new Song(title, artist);
        if (!head) {
            head = newSong;
            return;
        }
        Song* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newSong;
        cout << "Added song: \"" << title << "\" by " << artist << "\n";
    }

    // Remove song by title
    void removeSong(string title) {
        if (!head) {
            cout << "Playlist is empty!\n";
            return;
        }
        if (head->title == title) {
            Song* temp = head;
            head = head->next;
            delete temp;
            cout << "Removed: \"" << title << "\"\n";
            return;
        }
        Song* current = head;
        while (current->next && current->next->title != title) {
            current = current->next;
        }
        if (current->next) {
            Song* temp = current->next;
            current->next = temp->next;
            delete temp;
            cout << "Removed: \"" << title << "\"\n";
        } else {
            cout << "Song not found!\n";
        }
    }

    // Display playlist
    void displayPlaylist() {
        if (!head) {
            cout << "Playlist is empty!\n";
            return;
        }
        Song* current = head;
        cout << "\n===== Playlist =====\n";
        int songNum = 1;
        while (current) {
            cout << songNum++ << ". \"" << current->title << "\" by " << current->artist << "\n";
            current = current->next;
        }
        cout << "===================\n\n";
    }

    ~Playlist() {
        Song* current = head;
        while (current) {
            Song* next = current->next;
            delete current;
            current = next;
        }
    }
};

// Display menu
void displayMenu() {
    cout << "\n===== Playlist Manager Menu =====\n";
    cout << "1. Add new song\n";
    cout << "2. Remove song\n";
    cout << "3. Display playlist\n";
    cout << "4. Exit\n";
    cout << "Enter your choice (1-4): ";
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    Playlist playlist;
    int choice;
    string title, artist;
    bool running = true;

    cout << "Welcome to the Playlist Manager!\n";

    while (running) {
        displayMenu();
        
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:  // Add song
                cout << "Enter song title: ";
                getline(cin, title);
                cout << "Enter artist name: ";
                getline(cin, artist);
                playlist.addSong(title, artist);
                break;
                
            case 2:  // Remove song
                cout << "Enter song title to remove: ";
                getline(cin, title);
                playlist.removeSong(title);
                break;
                
            case 3:  // Display playlist
                playlist.displayPlaylist();
                break;
                
            case 4:  // Exit
                cout << "Exiting Playlist Manager. Goodbye!\n";
                running = false;
                break;
                
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }

    return 0;
}