#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Node for the circular linked list
struct Task {
    string taskName;
    Task* next;
    Task(string name) : taskName(name), next(nullptr) {}
};

// Circular Linked List for task scheduler
class TaskScheduler {
private:
    Task* current;

public:
    TaskScheduler() : current(nullptr) {}

    // Add task to the scheduler
    void addTask(string taskName) {
        Task* newTask = new Task(taskName);
        if (!current) {
            current = newTask;
            current->next = current;
        } else {
            newTask->next = current->next;
            current->next = newTask;
            current = newTask;
        }
        cout << "Added task: " << taskName << "\n";
    }

    // Execute next task
    void executeNextTask() {
        if (!current) {
            cout << "No tasks!\n";
            return;
        }
        current = current->next;
        cout << "Executing task: " << current->taskName << "\n";
    }

    // Display all tasks
    void displayTasks() {
        if (!current) {
            cout << "No tasks!\n";
            return;
        }
        cout << "\n===== Tasks =====\n";
        Task* temp = current->next;
        int count = 1;
        do {
            cout << count++ << ". " << temp->taskName;
            if (temp == current) {
                cout << " (current)";
            }
            cout << "\n";
            temp = temp->next;
        } while (temp != current->next);
        cout << "================\n\n";
    }

    ~TaskScheduler() {
        if (current) {
            Task* head = current->next;
            Task* temp = head;
            while (temp != current) {
                Task* next = temp->next;
                delete temp;
                temp = next;
            }
            delete current;
        }
    }
};

// Display menu options
void displayMenu() {
    cout << "\n===== Task Scheduler Menu =====\n";
    cout << "1. Add new task\n";
    cout << "2. Execute next task\n";
    cout << "3. Display all tasks\n";
    cout << "4. Exit\n";
    cout << "Enter your choice (1-4): ";
}

// Clear input buffer
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    TaskScheduler scheduler;
    int choice;
    string taskName;
    bool running = true;

    cout << "Welcome to the Circular Task Scheduler!\n";

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
                cout << "Enter task name: ";
                getline(cin, taskName);
                scheduler.addTask(taskName);
                break;
                
            case 2:  
                scheduler.executeNextTask();
                break;
                
            case 3:  
                scheduler.displayTasks();
                break;
                
            case 4:  
                cout << "Exiting Task Scheduler. Goodbye!\n";
                running = false;
                break;
                
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }

    return 0;
}