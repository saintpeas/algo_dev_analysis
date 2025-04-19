#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Node for the queue
struct Patient {
    string name;
    Patient* next;
    Patient(string n) : name(n), next(nullptr) {}
};

// Queue for hospital patients
class HospitalQueue {
private:
    Patient* front;
    Patient* rear;

public:
    HospitalQueue() : front(nullptr), rear(nullptr) {}

    // Add patient to queue
    void enqueue(string name) {
        Patient* newPatient = new Patient(name);
        if (!rear) {
            front = rear = newPatient;
        } else {
            rear->next = newPatient;
            rear = newPatient;
        }
        cout << "Added patient: " << name << "\n";
    }

    // Remove patient from queue
    void dequeue() {
        if (!front) {
            cout << "Queue is empty!\n";
            return;
        }
        Patient* temp = front;
        cout << "Treating patient: " << temp->name << "\n";
        front = front->next;
        if (!front) {
            rear = nullptr;
        }
        delete temp;
    }

    // Display queue
    void displayQueue() {
        if (!front) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "\n===== Patient Queue =====\n";
        Patient* current = front;
        int position = 1;
        while (current) {
            cout << position++ << ". " << current->name;
            if (current == front) {
                cout << " (next to be treated)";
            }
            cout << "\n";
            current = current->next;
        }
        cout << "========================\n\n";
    }

    // Destructor to free memory
    ~HospitalQueue() {
        while (front) {
            Patient* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

// Display menu
void displayMenu() {
    cout << "\n===== Hospital Queue Menu =====\n";
    cout << "1. Add new patient\n";
    cout << "2. Treat next patient\n";
    cout << "3. Display queue\n";
    cout << "4. Exit\n";
    cout << "Enter your choice (1-4): ";
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    HospitalQueue queue;
    int choice;
    string name;
    bool running = true;

    cout << "Welcome to the Hospital Queue System!\n";

    while (running) {
        displayMenu();
        
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:  // Add patient
                cout << "Enter patient name: ";
                getline(cin, name);
                queue.enqueue(name);
                break;
                
            case 2:  // Treat patient
                queue.dequeue();
                break;
                
            case 3:  // Display queue
                queue.displayQueue();
                break;
                
            case 4:  // Exit
                cout << "Exiting Hospital Queue System. Goodbye!\n";
                running = false;
                break;
                
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }

    return 0;
}