![C++ Logo](c++(1).png)

# Data Structures and Demo

This repository contains implementations of various data structures in C++, each applied to a real-world scenario across entertainment, productivity, and health domains. All source code is located in the src/ directory, with each data structure implemented in a separate .cpp file.

## Getting Started

Each data structure folder in `src/` contains:
- A `.cpp` file with the implementation and example usage.

### Requirements
- A C++ compiler (e.g., `g++`, `clang++`, or MSVC).
- A terminal or command prompt for compilation and execution.

## Table of Contents
- [Data Structures Implemented](#data-structures-implemented)
  - [SinglyLinkedList](#singly-linked-list-playlist-manager)
  - [DoublyLinkedList](#doubly-linked-list-task-manager-for-to-do-list)
  - [CircularLinkedList](#circular-linked-list-round-robin-task-scheduler)
  - [Queues](#queues-hospital-patient-queue)
  - [Stacks](#stacks-undo-feature-in-text-editor)
  - [Heaps](#heaps-emergency-room-prioritization)
  - [Trees](#trees)
  - [Graphs](#graphs-path-finding-and-traversal)
  - [Searching](#searching)
  - [Sorting](#sorting)
- [Folder Structure](#folder-structure)
- [How to Compile and Run](#how-to-compile-and-run)



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

[View Demo]()

# ER Priority Queue System Using Min-Heap

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

-insert: Adds a patient and heapifies up to maintain the min-heap property.
-extractMin: Removes and returns the highest-priority patient (lowest number), heapifying down afterward.
-displayHeap: Prints all patients and their priorities with descriptive labels.
-heapifyUp/heapifyDown: Maintain the heap structure after insertions and deletions.

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

## Graphs: Path Finding and Traversal

This program implements a graph data structure using an adjacency list representation and provides implementations of common graph algorithms including Dijkstra's shortest path, longest path approximation, breadth-first search (BFS), and depth-first search (DFS).

## Explanations: 

The graph is implemented as an adjacency list using an unordered map where each node maps to a vector of its neighbors and corresponding edge weights. The Graph class provides:

- addEdge: Adds a weighted edge between two nodes (handles both directed and undirected graphs).
- printGraph: Displays the adjacency list representation of the graph.
- shortestPath: Implements Dijkstra's algorithm to find the shortest path between two nodes.
- longestPath: Approximates the longest simple path between two nodes (NP-hard problem).
- bfs: Performs breadth-first search to find a target node from a starting node.
- dfs: Performs depth-first search to find a target node from a starting node.

The main function creates a directed graph, adds weighted edges, and demonstrates each algorithm. This implementation is ideal for solving pathfinding problems, network analysis, and various graph-related applications.

## Code Sample

```cpp
// Dijkstra's algorithm for shortest path
vector<int> shortestPath(int start, int end) {
    // Priority queue for (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Distance from start to all nodes
    unordered_map<int, int> dist;
    
    // Previous node in path
    unordered_map<int, int> prev;
    
    // Initialize distances
    for (const auto& node : adjList) {
        dist[node.first] = INT_MAX;
        prev[node.first] = -1;
    }
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if (u == end) break;
        
        for (const auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    
    // Reconstruct path
    vector<int> path;
    for (int at = end; at != -1; at = prev[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    
    if (path.size() == 1) {
        // No path found
        return {};
    }
    
    cout << "Shortest path distance: " << dist[end] << endl;
    return path;
}
```
## Demo
[View Demo]()


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
│   │   └── trees.cpp
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