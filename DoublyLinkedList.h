#pragma once
#include "Node.h"
#include "Iterator.h"

template<typename T>
class DoublyLinkedList
{
	Node<T>* _Head = nullptr;

	Node<T>* _Tail = nullptr;

	short _Length=0;

	Iterator<T> _begin() {
		return Iterator<T>(_Head);
	}

	Iterator<T> _end() {
		return Iterator<T>(nullptr);
	}

public:
	DoublyLinkedList();
	~DoublyLinkedList();


	Node<T>* GetHead() {
		return _Head;
	}

	Node<T>* GetTail() {
		return _Tail;
	}

	short GetLength() {
		short counter = 0;
		for (Iterator<T> itr = _begin(); itr != _end(); itr.Next())
		{
			counter++;
		}
		return counter;
	}

	// read only properties
	__declspec(property(get = GetLength)) short length;
	__declspec(property(get = GetHead)) Node<T>* head;
	__declspec(property(get = GetTail)) Node<T>* tail;

};


template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	_Head = nullptr;
	_Tail = nullptr;
	_Length = GetLength();
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	for (Iterator<T> itr = _begin(); itr != _end(); )
	{
		Node<T>* current = itr.current_node;
		// Move to the next node before deleting the current becouse if the current deleted before moving then we can't move
		itr.Next(); 
		delete current;
	}
	_Head = nullptr;
	_Tail = nullptr;
	_Length= 0;
}