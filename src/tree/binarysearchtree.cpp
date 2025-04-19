#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    int year;
    Book* left;
    Book* right;

    Book(int i, string t, string a, int y) : id(i), title(t), author(a), year(y), left(nullptr), right(nullptr) {}
};

// Book Catalog class implemented as a Binary Search Tree
class BookCatalog {
private:
    Book* root;

    Book* insertBook(Book* node, int id, string title, string author, int year);
    void displayInOrder(Book* node);
    void displayPreOrder(Book* node);
    Book* findBook(Book* node, int id);
    Book* removeBook(Book* node, int id);
    Book* findMinValueNode(Book* node);
    void destroyTree(Book* node);

public:
    BookCatalog() : root(nullptr) {}
    ~BookCatalog() { destroyTree(root); }

    void addBook(int id, string title, string author, int year);
    void displayAllBooks();
    void displayAllBooksPreOrder();
    bool searchBook(int id);
    void deleteBook(int id);
    void displayBook(int id);
};

// Add a book to the catalog
void BookCatalog::addBook(int id, string title, string author, int year) {
    root = insertBook(root, id, title, author, year);
    cout << "Book added: " << title << " by " << author << " (ID: " << id << ")\n";
}

// Recursive helper for inserting a book
Book* BookCatalog::insertBook(Book* node, int id, string title, string author, int year) {
    if (node == nullptr) {
        return new Book(id, title, author, year);
    }

    if (id < node->id) {
        node->left = insertBook(node->left, id, title, author, year);
    } else if (id > node->id) {
        node->right = insertBook(node->right, id, title, author, year);
    } else {
        cout << "Error: Book with ID " << id << " already exists!\n";
    }

    return node;
}

// Display all books in-order (sorted by ID)
void BookCatalog::displayAllBooks() {
    cout << "\n===== Book Catalog (In-Order) =====\n";
    if (root == nullptr) {
        cout << "Catalog is empty!\n";
    } else {
        cout << left << setw(6) << "ID" << setw(30) << "Title" << setw(20) << "Author" << "Year\n";
        cout << string(60, '-') << endl;
        displayInOrder(root);
    }
    cout << "===================================\n\n";
}

// Recursive helper for in-order traversal
void BookCatalog::displayInOrder(Book* node) {
    if (node != nullptr) {
        displayInOrder(node->left);
        cout << left << setw(6) << node->id << setw(30) << node->title << setw(20) << node->author << node->year << endl;
        displayInOrder(node->right);
    }
}

// Display all books in pre-order (root, left, right)
void BookCatalog::displayAllBooksPreOrder() {
    cout << "\n===== Book Catalog (Pre-Order) =====\n";
    if (root == nullptr) {
        cout << "Catalog is empty!\n";
    } else {
        cout << left << setw(6) << "ID" << setw(30) << "Title" << setw(20) << "Author" << "Year\n";
        cout << string(60, '-') << endl;
        displayPreOrder(root);
    }
    cout << "===================================\n\n";
}

// Recursive helper for pre-order traversal
void BookCatalog::displayPreOrder(Book* node) {
    if (node != nullptr) {
        cout << left << setw(6) << node->id << setw(30) << node->title << setw(20) << node->author << node->year << endl;
        displayPreOrder(node->left);
        displayPreOrder(node->right);
    }
}

bool BookCatalog::searchBook(int id) {
    Book* result = findBook(root, id);
    return (result != nullptr);
}

void BookCatalog::displayBook(int id) {
    Book* book = findBook(root, id);

    if (book == nullptr) {
        cout << "Book with ID " << id << " not found!\n";
        return;
    }

    cout << "\n===== Book Details =====\n";
    cout << "ID: " << book->id << endl;
    cout << "Title: " << book->title << endl;
    cout << "Author: " << book->author << endl;
    cout << "Year: " << book->year << endl;
    cout << "========================\n\n";
}

// Recursive helper for finding a book
Book* BookCatalog::findBook(Book* node, int id) {
    if (node == nullptr || node->id == id) {
        return node;
    }

    if (id < node->id) {
        return findBook(node->left, id);
    } else {
        return findBook(node->right, id);
    }
}

// Delete a book by ID
void BookCatalog::deleteBook(int id) {
    if (!searchBook(id)) {
        cout << "Book with ID " << id << " not found!\n";
        return;
    }

    root = removeBook(root, id);
    cout << "Book with ID " << id << " has been removed from catalog.\n";
}

// Recursive helper for removing a book
Book* BookCatalog::removeBook(Book* node, int id) {
    if (node == nullptr) {
        return nullptr;
    }

    // Navigate to the node to delete
    if (id < node->id) {
        node->left = removeBook(node->left, id);
    } else if (id > node->id) {
        node->right = removeBook(node->right, id);
    } else {
        // Node with only one child or no child
        if (node->left == nullptr) {
            Book* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Book* temp = node->left;
            delete node;
            return temp;
        }

        // Node with two children
        Book* temp = findMinValueNode(node->right);
        node->id = temp->id;
        node->title = temp->title;
        node->author = temp->author;
        node->year = temp->year;
        node->right = removeBook(node->right, temp->id);
    }

    return node;
}

Book* BookCatalog::findMinValueNode(Book* node) {
    Book* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Clean up the tree
void BookCatalog::destroyTree(Book* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

// Clear the input buffer
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Display menu
void displayMenu() {
    cout << "\n===== Book Catalog Menu =====\n";
    cout << "1. Add new book\n";
    cout << "2. Display all books (in-order)\n";
    cout << "3. Display all books (pre-order)\n";
    cout << "4. Search for a book\n";
    cout << "5. Remove a book\n";
    cout << "6. Exit\n";
    cout << "Enter your choice (1-6): ";
}

int main() {
    BookCatalog catalog;
    int choice, id, year;
    string title, author;
    bool running = true;

    cout << "Welcome to the Book Catalog (Binary Search Tree Implementation)!\n";
    cout << "Books are organized by their unique ID numbers.\n";

    // Add some sample books
    catalog.addBook(1003, "To Kill a Mockingbird", "Harper Lee", 1960);
    catalog.addBook(1001, "1984", "George Orwell", 1949);
    catalog.addBook(1005, "The Great Gatsby", "F. Scott Fitzgerald", 1925);
    catalog.addBook(1002, "Pride and Prejudice", "Jane Austen", 1813);
    catalog.addBook(1004, "The Catcher in the Rye", "J.D. Salinger", 1951);

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
                cout << "Enter book ID: ";
                if (!(cin >> id)) {
                    cout << "Invalid ID. Please enter a number.\n";
                    clearInputBuffer();
                    break;
                }
                clearInputBuffer();

                cout << "Enter book title: ";
                getline(cin, title);

                cout << "Enter book author: ";
                getline(cin, author);

                cout << "Enter publication year: ";
                if (!(cin >> year)) {
                    cout << "Invalid year. Using current year.\n";
                    clearInputBuffer();
                    year = 2025;  // Current year
                } else {
                    clearInputBuffer();
                }

                catalog.addBook(id, title, author, year);
                break;

            case 2:
                catalog.displayAllBooks();
                break;

            case 3:
                catalog.displayAllBooksPreOrder();
                break;

            case 4:
                cout << "Enter book ID to search: ";
                if (!(cin >> id)) {
                    cout << "Invalid ID. Please enter a number.\n";
                    clearInputBuffer();
                    break;
                }
                clearInputBuffer();

                if (catalog.searchBook(id)) {
                    catalog.displayBook(id);
                } else {
                    cout << "Book with ID " << id << " not found!\n";
                }
                break;

            case 5:
                cout << "Enter book ID to remove: ";
                if (!(cin >> id)) {
                    cout << "Invalid ID. Please enter a number.\n";
                    clearInputBuffer();
                    break;
                }
                clearInputBuffer();

                catalog.deleteBook(id);
                break;

            case 6:
                cout << "Exiting Book Catalog. Goodbye!\n";
                running = false;
                break;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 6.\n";
        }
    }

    return 0;
}
