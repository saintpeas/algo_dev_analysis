![Another image](https://en.wikipedia.org/wiki/C%2B%2B)

# Data Structures and Demo

This repository contains implementations of various data structures in C++, each applied to a real-world scenario across entertainment, productivity, and health domains. All source code is located in the src/ directory, with each data structure implemented in a separate .cpp file.

## Table of Contents

- [Data Structures Implemented](#data-structures-implemented)
  - [SinglyLinkedList](#singlylinkedlist)
  - [DoublyLinkedList](#doublylinkedlist)
  - [CircularLinkedList](#circularlinkedlist)
  - [Queues](#queues)
  - [Stacks](#stacks)
  - [Heaps](#heaps)
  - [Trees](#trees)
  - [Searching](#search)
  - [Soring](#sorting)
- [Folder Structure](#folder-structure)
- [Prerequisites](#prerequisites)
- [How to Compile and Run](#how-to-compile-and-run)

# Singly Linked List: Playlist Manager

A C++ application that uses a singly linked list data structure to manage a music playlist, similar to the functionality of music streaming services.

## Overview

This application implements a playlist manager using a singly linked list data structure. Users can:
- Add songs to the end of the playlist
- Remove songs by their title
- Display the entire playlist in sequence

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

### Data Structure

The playlist is implemented as a singly linked list with:
- A `Song` struct containing:
  - `title` (string)
  - `artist` (string) 
  - `next` pointer to the next Song

## Real-World Application

This project simulates the core functionality of music streaming services like Spotify, Apple Music, or YouTube Music, where users create and manage playlists by adding or removing songs in a specific order.

## Demo

[View Demo](insert-asciinema-link-here)
