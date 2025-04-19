#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Node for the doubly linked list
struct Task {
    string description;
    Task* prev;
    Task* next;
    Task(string desc) : description(desc), prev(nullptr), next(nullptr) {}
};

// Doubly Linked List for to-do list
class TaskManager {
private:
    Task* current;
    Task* head;

public:
    TaskManager() : current(nullptr), head(nullptr) {}

    // Add a new task
    void addTask(string description) {
        Task* newTask = new Task(description);
        if (!head) {
            head = current = newTask;
        } else {
            newTask->prev = current;
            newTask->next = current->next;
            if (current->next) {
                current->next->prev = newTask;
            }
            current->next = newTask;
            current = newTask;
        }
        cout << "Added task: " << description << "\n";
    }

    // Remove task by description
    void removeTask(string description) {
        Task* temp = head;
        while (temp && temp->description != description) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Task not found!\n";
            return;
        }
        if (temp == current) {
            current = temp->prev ? temp->prev : temp->next;
        }
        if (temp == head) {
            head = temp->next;
        }
        if (temp->prev) {
            temp->prev->next = temp->next;
        }
        if (temp->next) {
            temp->next->prev = temp->prev;
        }
        cout << "Removed task: " << description << "\n";
        delete temp;
    }

    // Navigate to previous task
    void goBack() {
        if (!current || !current->prev) {
            cout << "No previous task!\n";
            return;
        }
        current = current->prev;
        cout << "Current task: " << current->description << "\n";
    }

    // Navigate to next task
    void goForward() {
        if (!current || !current->next) {
            cout << "No next task!\n";
            return;
        }
        current = current->next;
        cout << "Current task: " << current->description << "\n";
    }

    // Display all tasks
    void displayTasks() {
        if (!head) {
            cout << "To-Do List is empty!\n";
            return;
        }
        cout << "\n===== To-Do List =====\n";
        Task* temp = head;
        int count = 1;
        while (temp) {
            cout << count++ << ". " << temp->description;
            if (temp == current) {
                cout << " (current)";
            }
            cout << "\n";
            temp = temp->next;
        }
        cout << "=====================\n\n";
    }

    // Show current task
    void showCurrentTask() {
        if (!current) {
            cout << "No tasks in the list!\n";
            return;
        }
        cout << "Current task: " << current->description << "\n";
    }

    ~TaskManager() {
        Task* temp = head;
        while (temp) {
            Task* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

// Function to display the menu
void displayMenu() {
    cout << "\n===== Task Manager Menu =====\n";
    cout << "1. Add a new task\n";
    cout << "2. Remove a task\n";
    cout << "3. Navigate to previous task\n";
    cout << "4. Navigate to next task\n";
    cout << "5. Display all tasks\n";
    cout << "6. Show current task\n";
    cout << "7. Exit\n";
    cout << "Enter your choice (1-7): ";
}

// Function to clear input buffer
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    TaskManager todo;
    int choice;
    string taskDescription;
    bool running = true;

    cout << "Welcome to the Task Manager!\n";

    while (running) {
        displayMenu();
        
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();  // Clear any remaining input

        switch (choice) {
            case 1:  // Add task
                cout << "Enter task description: ";
                getline(cin, taskDescription);
                todo.addTask(taskDescription);
                break;
                
            case 2:  // Remove task
                cout << "Enter task description to remove: ";
                getline(cin, taskDescription);
                todo.removeTask(taskDescription);
                break;
                
            case 3:  // Go to previous task
                todo.goBack();
                break;
                
            case 4:  // Go to next task
                todo.goForward();
                break;
                
            case 5:  // Display all tasks
                todo.displayTasks();
                break;
                
            case 6:  // Show current task
                todo.showCurrentTask();
                break;
                
            case 7:  // Exit
                cout << "Exiting Task Manager. Goodbye!\n";
                running = false;
                break;
                
            default:
                cout << "Invalid choice. Please enter a number between 1 and 7.\n";
        }
    }

    return 0;
}