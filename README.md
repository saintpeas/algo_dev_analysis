   ![C++ Logo](c++(1).png)

# Data Structures and Demo

This repository contains implementations of various data structures in C++, each applied to a real-world scenario across entertainment, productivity, and health domains. All source code is located in the src/ directory, with each data structure implemented in a separate .cpp file.

## Getting Started

Each data structure folder in `src/` contains:
- A `.cpp` file with the implementation and example usage.

### Requirements
- A C++ compiler (e.g., `g++`, `clang++`, or MSVC).
- A terminal or command prompt for compilation and execution.

___
## Table of Contents
- [Data Structures Implemented](#data-structures-implemented)
  - [SinglyLinkedList](#singly-linked-list-playlist-manager)
  - [DoublyLinkedList](#doubly-linked-list-task-manager-for-to-do-list)
  - [CircularLinkedList](#circular-linked-list-round-robin-task-scheduler)
  - [Queues](#queues-hospital-patient-queue)
  - [Stacks](#stacks-undo-feature-in-text-editor)
  - [Heap](#heap-er-priority-queue-system)
  - [Trees](#binary-search-tree-book-catalog)
  - [Graphs](#graphs-metro-manila-navigation-system-for-ride-sharing-services)
  - [Searching](#searching)
  - [Sorting](#sorting)
- [Folder Structure](#folder-structure)
- [How to Compile and Run](#how-to-compile-and-run)

___

## Data Structures Implemented

## Singly Linked List: Playlist Manager

A C++ application that uses a singly linked list data structure to manage a music playlist, similar to the functionality of music streaming services.

## Explanation

The singly linked list is implemented with a Song struct, containing title, artist, and a next pointer. The Playlist class manages the list with:
- addSong: Adds a new song to the end by traversing to the last node.
- removeSong: Removes a song by title, adjusting pointers and freeing memory.
- displayPlaylist: Iterates through the list to print song details.

The main function demonstrates usage by adding sample songs, displaying the playlist, removing a song, and showing the updated list. The singly linked list is ideal for this application because songs are typically played sequentially, and insertions/deletions are straightforward without needing bidirectional navigation.

## Code Sample

```cpp
// Adding a song to the playlist
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
```


## Demo

[View Demo](https://asciinema.org/a/F9UkcZHIlGwfJgd4yXw6FPQ9R)

___
## Doubly Linked List: Task Manager for To-Do List

This program uses a doubly linked list to manage a to-do list. Users can add tasks, remove tasks by description, navigate forward or backward through the list, and display all tasks, facilitating task organization.

## Explanation

The doubly linked list is implemented with a Task struct containing a description, prev, and next pointers.
- addTask: Inserts a new task after the current task, updating pointers bidirectionally.
- removeTask: Removes a task by description, adjusting prev and next pointers and updating the current task if needed.
- goBack/goForward: Navigates to the previous or next task, updating the current pointer.
- displayTasks: Traverses from the head to print all tasks.

The main function adds sample tasks, displays the list, navigates backward, removes a task, and shows the updated list. The doubly linked list is suitable here because it allows efficient navigation in both directions, useful for reviewing or reordering tasks.

## Code Sample

```cpp
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
```

## Demo

[View Demo](https://asciinema.org/a/QoPEX8iBJsw2mFfEn5ktX4enQ)

___
## Circular Linked List: Round-Robin Task Scheduler

This program implements a circular linked list to schedule tasks in a round-robin fashion. Users can add tasks, execute the next task in a cycle, and display all tasks, ensuring fair task allocation.

## Explanation

This project implements a task scheduler using a circular linked list. Each task is represented by a Task struct, containing a taskName and a next pointer. The TaskScheduler class provides the following functionalities:

   - addTask: Adds a new task to the circular list.
   - executeNextTask: Moves to and executes the next task in the cycle.
   - displayTasks: Prints all tasks in the list, starting from the next one.

The main function demonstrates the scheduler by adding sample tasks and executing them in a round-robin fashion. The circular linked list is well-suited for round-robin scheduling due to its inherent ability to cycle through tasks continuously.

## Code Sample

```cpp
 void executeNextTask() {
        if (!current) {
            cout << "No tasks!\n";
            return;
        }
        current = current->next;
        cout << "Executing task: " << current->taskName << "\n";
    }
```

## Demo

[View Demo](https://asciinema.org/a/OEXAP5Udf0ddapXc5ZLqBsyHd)

___
## Queues: Hospital Patient Queue

This program implements a queue to manage a hospital patient waiting list. Users can add patients to the queue, remove the next patient for treatment, and display the current queue.

## Explanation

The queue is implemented with a Patient struct containing a name and next pointer. The HospitalQueue class manages:

- enqueue: Adds a patient to the rear of the queue.
- dequeue: Removes the patient at the front for treatment.
- displayQueue: Prints all patients from front to rear.

The main function adds sample patients, displays the queue, removes a patient, and shows the updated queue. The queue’s First-In-First-Out (FIFO) structure is ideal for managing patients based on arrival order.

## Code Sample

```cpp
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
```

## Demo

[View Demo](https://asciinema.org/a/FWwRNfsBX1golmEkdaYc47r8j)

___
## Stacks: Undo Feature in Text Editor

This program uses a stack to implement an undo feature in a text editor. Users can save text states, undo changes to revert to previous states, and display the current state.

## Explanation

The stack is implemented as an array (states) with a top index in the TextEditor class. Key operations include:

- saveState: Pushes a new text state onto the stack if not full.
- undo: Pops the top state to revert to the previous state.
- displayCurrent: Shows the current top state.

The main function saves sample text states, displays the current state, and performs undo operations. The stack is perfect for this application because it follows a Last-In-First-Out (LIFO) order, ideal for reverting changes in the reverse order they were made.

## Code Sample

```cpp
void saveState(string text) {
        if (top < MAX_SIZE - 1) {
            states[++top] = text;
            cout << "Saved: \"" << text << "\"\n";
        } else {
            cout << "Stack full, cannot save state!\n";
        }
    }
```

## Demo

[View Demo](https://asciinema.org/a/gooI6701aYZlM9tCFezHeqrTa)

___

# Heap: ER Priority Queue System

This program uses a min-heap to prioritize patients in an emergency room based on condition severity. Users can add patients with a priority level (1-5), treat the highest-priority patient, and display the current priority queue.

## Priority System

The priority system follows standard emergency room triage principles:
- Priority 1: Immediate care needed (most critical)
- Priority 2: Very urgent
- Priority 3: Urgent
- Priority 4: Standard care
- Priority 5: Non-urgent (least critical)

Lower numbers represent higher medical priority, ensuring the most critical patients are treated first.

## Explanation

The min-heap is implemented using a `vector<Patient>` where `Patient` has a name and priority level. The `ERPriority` class provides:

- insert: Adds a patient and heapifies up to maintain the min-heap property.
- extractMin: Removes and returns the highest-priority patient (lowest number), heapifying down afterward.
- displayHeap: Prints all patients and their priorities with descriptive labels.
- heapifyUp/heapifyDown: Maintain the heap structure after insertions and deletions.

## Code Sample

```cpp
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
```

## Demo
[View Demo](https://asciinema.org/a/EB2D189YFEueaofUizSGF2nye)

___
# Graphs: Metro Manila Navigation System for Ride-Sharing Services

This program implements a graph using an adjacency list to plan routes for ride-sharing drivers in Metro Manila. Users can add roads between city locations, find the shortest or longest routes, and check if destinations are reachable using Breadth-First Search (BFS) and Depth-First Search (DFS), optimizing navigation.

## Explanation

The graph is implemented using an `unordered_map<int, vector<pair<int, int>>>` for an adjacency list, where each location (represented by an integer ID) maps to a list of its neighbors. Each neighbor in the list is a `pair<int, int>`, containing the neighbor's ID and the travel time (weight) of the road connecting to it.

Location names (e.g., "Makati", "NAIA") are internally mapped to integer IDs for efficient graph representation and processing.

The `MetroManilaNavigation` class provides the following functionalities:

-   **`addLocation(const string& locationName)` / `addRoad(const string& startLocation, const string& endLocation, int travelTime)`:** Methods to add new locations to the map and establish roads (edges) between them, along with their associated travel times.
-   **`printMap()`:** Displays the current city map, showing the connections between locations and their respective travel times.
-   **`shortestRoute(const string& startLocation, const string& endLocation)`:** Utilizes Dijkstra’s algorithm to find the route with the minimum total travel time between two specified locations.
-   **`longestRoute(const string& startLocation, const string& endLocation)`:** Employs dynamic programming to determine the route with the maximum total travel time between two specified locations.
-   **`bfs(const string& startLocation, const string& endLocation)` / `dfs(const string& startLocation, const string& endLocation)`:** Methods to check if a destination location is reachable from a starting location using Breadth-First Search (BFS) and Depth-First Search (DFS) algorithms, respectively.
-   **`dfsUtil(int v, unordered_map<int, bool>& visited, int target)`:** A helper method used internally by the `dfs` function for recursive Depth-First Search traversal.

The main function provides a command-line interface with a menu-driven system. This allows users to:

- Set up and manage a simulated Metro Manila map by adding locations and roads.
- Find the shortest and longest routes between any two locations on the map.
- Check the reachability of a destination from a starting point using BFS and DFS.

The underlying graph structure effectively models the locations in Metro Manila as nodes and the roads connecting them as edges, with travel times acting as weights on these edges.

## Code Sample

```cpp
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
```

[View Demo](https://asciinema.org/a/K0HNBbL03ypR1pW2jlxm26eut)
___

## Binary Search Tree: Book Catalog

A C++ application that uses a binary search tree data structure to manage a book catalog, similar to how a library or bookstore might catalog their inventory.

## Explanation

The binary search tree is implemented with a Book struct, containing id, title, author, year, and left/right pointers. The BookCatalog class manages the tree with:

- addBook: Adds a new book to the tree based on its ID, maintaining the BST property.
- displayAllBooks: Performs an in-order traversal to print books in sorted order by ID.
- displayAllBooksPreOrder: Performs a pre-order traversal to show the actual tree structure.
- searchBook & displayBook: Efficiently search for a book by ID using the BST property.
- deleteBook: Removes a book by ID, handling all cases (leaf, one child, two children).

The main function demonstrates usage by adding sample books, displaying the catalog in different traversal orders, searching for specific books, and removing books from the catalog.

The binary search tree is ideal for this application because it provides O(log n) search, insertion, and deletion operations, making it efficient for managing a large catalog of books. The tree structure automatically maintains books in sorted order by ID, allowing for quick lookup and range queries.

## Code Sample

```cpp
// Adding a book to the catalog
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
```

[View Demo](https://asciinema.org/a/P4gj7Wtp8xT2A8f2AIbwVD3GT)

___
## Folder Structure
```
algo_dev_analysis/
├── src/
│   ├── singlylinkedlist/
│   │   └── singlylinkedlist.cpp
│   ├── doublylinkedlist/
│   │   └── doublylinkedlist.cpp
│   ├── circularlinkedlist/
│   │   └── circularlinkedlist.cpp
│   ├── stack/
│   │   └── stack.cpp
│   ├── queues/
│   │   └── queues.cpp
│   ├── heaps/
│   │   ├── minheap.cpp
│   │   └── maxheap.cpp
│   ├── graphs/
│   │   └── graphs.cpp
│   ├── trees/
│   │   └── binarysearchtree.cpp
│   ├── search/
│   │   └── search.cpp
└── README.md
```

## How to Compile and Run

To compile and run a data structure program in this project, follow these steps:

1. **Navigate to the desired folder**:
   - Open a terminal or command prompt.
   - Change to the folder containing the `.cpp` file, e.g.:
     ```bash
     cd src/singlylinkedlist
     ```

2. **Compile the program**:
   - Use a C++ compiler (e.g., `g++`) to compile the `.cpp` file. For example:
     ```bash
     g++ -o myprogram singlylinkedlist.cpp
     ```
   - This creates an executable file named `myprogram`.

3. **Run the program**:
   - Execute the compiled program by running:
     ```bash
     ./myprogram
     ```

### Notes
- Replace `singlylinkedlist.cpp` with the specific `.cpp` file name in the folder (e.g., `doublylinkedlist.cpp`, `graphs.cpp`).
- Ensure a C++ compiler (e.g., `g++`, `clang++`, or MSVC) is installed.
- If errors occur, check the `.cpp` file for specific compilation requirements or dependencies.
