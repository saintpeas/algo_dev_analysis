#include <iostream>
#include <string>

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
            cout << "Removed: " << title << "\n";
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
            cout << "Removed: " << title << "\n";
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
        cout << "Playlist:\n";
        while (current) {
            cout << "Title: " << current->title << ", Artist: " << current->artist << "\n";
            current = current->next;
        }
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

int main() {
    Playlist playlist;
    playlist.addSong("Bohemian Rhapsody", "Queen");
    playlist.addSong("Shape of You", "Ed Sheeran");
    playlist.addSong("Imagine", "John Lennon");
    playlist.displayPlaylist();
    playlist.removeSong("Shape of You");
    playlist.displayPlaylist();
    return 0;
}
