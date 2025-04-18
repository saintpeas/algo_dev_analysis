![C++ Logo](c++(1).png)

# Data Structures and Demo

This repository contains implementations of various data structures in C++, each applied to a real-world scenario across entertainment, productivity, and health domains. All source code is located in the src/ directory, with each data structure implemented in a separate .cpp file.

## Table of Contents
- [Data Structures Implemented](#data-structures-implemented)
  - [SinglyLinkedList](#singly-linked-list-playlist-manager)
  - [DoublyLinkedList](#doublylinkedlist)
  - [CircularLinkedList](#circularlinkedlist)
  - [Queues](#queues)
  - [Stacks](#stacks)
  - [Heaps](#heaps)
  - [Trees](#trees)
  - [Searching](#searching)
  - [Sorting](#sorting)
- [Folder Structure](#folder-structure)
- [Prerequisites](#prerequisites)
- [How to Compile and Run](#how-to-compile-and-run)

## Data Structures Implemented

## Singly Linked List: Playlist Manager

A C++ application that uses a singly linked list data structure to manage a music playlist, similar to the functionality of music streaming services.

## Overview

The singly linked list is implemented with a Song struct, containing title, artist, and a next pointer. The Playlist class manages the list with:
- addSong: Adds a new song to the end by traversing to the last node.
- removeSong: Removes a song by title, adjusting pointers and freeing memory.
- displayPlaylist: Iterates through the list to print song details.
- Destructor: Frees all nodes to prevent memory leaks.

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

[View Demo](insert-asciinema-link-here)

## Doubly Linked List: Task Manager for To-Do List

This program uses a doubly linked list to manage a to-do list. Users can add tasks, remove tasks by description, navigate forward or backward through the list, and display all tasks, facilitating task organization.

## Overview

The doubly linked list is implemented with a Task struct containing a description, prev, and next pointers.
- addTask: Inserts a new task after the current task, updating pointers bidirectionally.
- removeTask: Removes a task by description, adjusting prev and next pointers and updating the current task if needed.
- goBack/goForward: Navigates to the previous or next task, updating the current pointer.
- displayTasks: Traverses from the head to print all tasks.
- Destructor: Frees all nodes to prevent memory leaks.

The main function adds sample tasks, displays the list, navigates backward, removes a task, and shows the updated list. The doubly linked list is suitable here because it allows efficient navigation in both directions, useful for reviewing or reordering tasks.

## Demo

[View Demo]()


