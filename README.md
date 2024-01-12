# Doubly Linked List Implementation in C++

This repository contains an implementation of a doubly linked list using C++ and Object-Oriented Programming principles.

## Overview

### Classes
- **Node**: Represents individual nodes in the doubly linked list.
- **Iterator**: Provides iteration capabilities over the linked list.
- **DoublyLinkedList**: Implements the doubly linked list and its functionalities.

## Classes and Functionality

### Node Class
The `Node` class represents individual elements in the singly linked list. Each node holds:
- `_Data`: Data of type `T`.
- `_ptrToNext`: Pointer to the next node.
- `_ptrToPrev`: Pointer to the previous node.

### Iterator Class
The `Iterator` class provides functionality for iterating through the singly linked list. It includes methods to:
- Access node data.
- Set node data.
- Move to the next node.
- Access the current node.

### DoublyLinkedList Class
The `DoublyLinkedList` class represents a doubly linked list with various functionalities:

- **Properties:**
  - `head`: Returns the head of the list.
  - `tail`: Returns the tail of the list.
  - `length`: Returns the number of nodes in the list.

- **Search and Access:**
  - `Find(data)`: Finds the node with the specified data.
  - `FindByIndex(index)`: Finds the node at the specified index.
  - `isExist(data)`: Checks if a node with the given data exists.

- **Insertion:**
  - `InsertBegin(data)`: Inserts a new node at the beginning.
  - `InsertEnd(data)`: Inserts a new node at the end.
  - `InsertBefore(dataBefore, newData)`: Inserts a new node before a specified node.
  - `InsertAfter(dataAfter, newData)`: Inserts a new node after a specified node.
  - `InsertAtIndex(index, value)`: Inserts a new node at a specified index.

- **Deletion:**
  - `DeleteFront()`: Deletes the first node.
  - `DeleteBack()`: Deletes the last node.
  - `DeleteAtIndex(index)`: Deletes the node at a specified index.

- **Update:**
  - `UpdateAtIndex(index, newValue)`: Updates the value of the node at a specified index.

- **Concatenation:**
  - `Concat(other)`: Concatenates the current list with another list.

- **Additional Features:**
  - `IsPalindrome()`: Checks if the list is a palindrome.
  - `GetNthNodeValue(N)`: Returns the value of the node at the Nth position.
  - `Reverse()`: Reverses the order of nodes in the list.
  - `Clear()`: Clears the entire list.

- **Printing:**
  - `PrintFromFront()`: Prints the list from the head to the tail.
  - `PrintFromBack()`: Prints the list from the tail to the head.

## Usage

To use this singly linked list implementation, follow these steps:
1. Clone the repository.
2. Include the necessary header files in your C++ code: `Node.h`, `Iterator.h`, and `LinkedList.h`.
3. Create a `LinkedList` object and utilize its functionalities as per your requirements.

## Example

```cpp
// Example usage of the LinkedList class
#include "DoublyLinkedList.h"

int main() {
    DoublyLinkedList<int> myIntsList; // list of integers
    DoublyLinkedList<string> myStringsList; // list of strings
    
    // Perform operations like insertion, deletion, and retrieval here
    
    return 0;
}
