#include <iostream>
#include <string>
#include <limits>

using namespace std;

class TextEditor {
private:
    static const int MAX_SIZE = 100;
    string states[MAX_SIZE];
    int top;

public:
    TextEditor() : top(-1) {}

    // Save current text state
    void saveState(string text) {
        if (top < MAX_SIZE - 1) {
            states[++top] = text;
            cout << "Saved: \"" << text << "\"\n";
        } else {
            cout << "Stack full, cannot save state!\n";
        }
    }

    // Undo last change
    void undo() {
        if (top == -1) {
            cout << "No changes to undo!\n";
            return;
        }
        cout << "Restored: \"" << states[top--] << "\"\n";
    }

    // Display current state
    void displayCurrent() {
        if (top == -1) {
            cout << "No text state!\n";
            return;
        }
        cout << "Current state: \"" << states[top] << "\"\n";
    }

    // Display all history
    void displayHistory() {
        if (top == -1) {
            cout << "No history available!\n";
            return;
        }
        cout << "\n===== Text History =====\n";
        for (int i = 0; i <= top; i++) {
            cout << i+1 << ". \"" << states[i] << "\"";
            if (i == top) {
                cout << " (current)";
            }
            cout << "\n";
        }
        cout << "======================\n\n";
    }
};

// Display menu
void displayMenu() {
    cout << "\n===== Text Editor Menu =====\n";
    cout << "1. Add/edit text\n";
    cout << "2. Undo\n";
    cout << "3. Display current text\n";
    cout << "4. Display history\n";
    cout << "5. Exit\n";
    cout << "Enter your choice (1-5): ";
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    TextEditor editor;
    int choice;
    string text;
    bool running = true;

    cout << "Welcome to the Text Editor!\n";
    cout << "This editor saves states of text and allows undoing changes.\n";

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
                cout << "Enter text: ";
                getline(cin, text);
                editor.saveState(text);
                break;

            case 2:
                editor.undo();
                break;

            case 3:
                editor.displayCurrent();
                break;

            case 4:
                editor.displayHistory();
                break;

            case 5:
                cout << "Exiting Text Editor. Goodbye!\n";
                running = false;
                break;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    }

    return 0;
}