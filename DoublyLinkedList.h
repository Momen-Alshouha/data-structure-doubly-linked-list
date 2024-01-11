#pragma once
#include <iostream>
#include "Node.h"
#include "Iterator.h"
using namespace std;

template<typename T>
class DoublyLinkedList
{
	Node<T>* _Head = nullptr;

	Node<T>* _Tail = nullptr;

	short _Length = 0;

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

	Node<T>* Find(T DataToFind) {
		for (Iterator<T> itr = _begin(); itr != _end(); itr.Next())
		{
			if (itr.data == DataToFind)
			{
				return itr.current_node;
			}
		}
		return nullptr;
	}


	bool isExisit(T DataToFind) {
		Node<T>* NodeToFind = Find(DataToFind);

		if (NodeToFind != nullptr)
		{
			return true;
		}
		return false;
	}

	void InsertBegin(T DataToInsert) {

		Node<T>* NewNode = new(nothrow) Node<T>(DataToInsert);
		if (NewNode==nullptr)
		{
			cout << "Error Memory Allocation\n";
			return;
		}

		if (_Head==nullptr)
		{
			_Head = _Tail = NewNode;
			return;
		}

		NewNode->next = _Head;
		_Head->prev = NewNode;
		_Head = NewNode;
	
	};

	void InsertEnd(T DataToInsert) {
		Node<T>* NewNode = new(nothrow) Node<T>(DataToInsert);

		if (NewNode == nullptr)
		{
			cout << "Error Memory Allocation\n";
			return;
		}

		if (_Head==nullptr)
		{
			_Head = _Tail = NewNode;
			return;
		}

		_Tail->next = NewNode;
		NewNode->prev = _Tail;
		_Tail = NewNode;
	}

	void InsertBefore(T DataToInsertBefore,T NewData) {
		
		Node<T>* NodeToInsertBefore = Find(DataToInsertBefore);
		
		if (NodeToInsertBefore==nullptr) // if node not found
		{
			return;
		}

		Node<T>* NewNode = new Node<T>(NewData);

		if (NodeToInsertBefore==_Head)
		{
			NewNode->next = _Head;
			_Head->prev = NewNode;
			_Head = NewNode;
			return;

		}
	
		NewNode->next = NodeToInsertBefore;
		NewNode->prev = NodeToInsertBefore->prev;

		if (NodeToInsertBefore->prev != nullptr) {
			NodeToInsertBefore->prev->next = NewNode;
		}

		NodeToInsertBefore->prev = NewNode;

	}

	void InsertAfter(T DataToInsertAfter) {


	}

	void InsertAtIndex(short index) {

	}

	
	void Print() {
		for (Iterator<T> itr = _begin(); itr != _end(); itr.Next())
		{
			cout << itr.data;
			if (itr.current_node!=_Tail)
			{
				cout << " -> ";
			}
		}
		cout << endl;
	}
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