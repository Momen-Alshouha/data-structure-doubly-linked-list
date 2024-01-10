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

	short GetLength() {
		short counter = 0;
		for (Iterator<T> itr = _begin(); itr != _end(); itr.Next())
		{
			counter++;
		}
		return counter;
	}

	__declspec(property(get = GetLength)) short length;

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
	for (Iterator<T> itr = _begin(); itr != _end(); itr.Next())
	{
		delete itr;
	}
	_Head = nullptr;
	_Tail = nullptr;
	length= 0;
}