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

	Node<T>* FindByIndex(short index) {
		short counter = 0;
		for (Iterator<T> itr = _begin(); itr != _end(); itr.Next())
		{
			if (counter==index)
			{
				return itr.current_node;
			}
			counter++;
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
			_Length++;
			return;
		}

		NewNode->next = _Head;
		_Head->prev = NewNode;
		_Head = NewNode;
		_Length++;
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
			_Length++;
			return;
		}

		_Tail->next = NewNode;
		NewNode->prev = _Tail;
		_Tail = NewNode;
		_Length++;
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
			InsertBegin(NewData);
			return;
		}
	
		NewNode->next = NodeToInsertBefore;
		NewNode->prev = NodeToInsertBefore->prev;

		if (NodeToInsertBefore->prev != nullptr) {
			NodeToInsertBefore->prev->next = NewNode;
		}

		NodeToInsertBefore->prev = NewNode;
		_Length++;
	}

	void InsertAfter(T DataToInsertAfter,T NewData) {
		Node<T>* NodeToInsertAfter = Find(DataToInsertAfter);
		
		if (NodeToInsertAfter==nullptr) // if node not found
		{
			return;
		}

		Node<T>* NewNode = new(nothrow) Node<T>(NewData);

		if (NewNode==nullptr)
		{
			cout << "Error throw memory allocation!\n";
		}

		NewNode->prev = NodeToInsertAfter;
		NewNode->next = NodeToInsertAfter->next;

		if (NodeToInsertAfter->next != nullptr) {
			// If the node to insert after is not the tail
			// Update the previous pointer of the node following the new node
			NodeToInsertAfter->next->prev = NewNode;
		}

		NodeToInsertAfter->next = NewNode;

		if (NodeToInsertAfter == _Tail) // if node to insert after is tail we need to set new tail with the new node
		{
			_Tail = NewNode; 
		}
		_Length++;
	}

	void InsertAtIndex(short index,T value) {

		Node<T>* NodeAtIndex = FindByIndex(index); // the node at the passed index
		
		if (NodeAtIndex ==nullptr)
		{
			return;
		}

		Node<T>* NewNodeToInsert = new Node<T>(value);
		

		if (NodeAtIndex == _Head) {

			InsertBegin(value);

			return;
		}

		
		NewNodeToInsert->prev = NodeAtIndex->prev;
		NewNodeToInsert->next = NodeAtIndex;
	
		if (NodeAtIndex->prev!=nullptr)
		{
			// If the node at the specified index has a previous node
			// Update the next pointer of the previous node to point to the new node
			
			NodeAtIndex->prev->next = NewNodeToInsert;
		}

		NodeAtIndex->prev = NewNodeToInsert;
		_Length++;
	}

	void DeleteBack() {
		if (_Tail != nullptr) {
			if (_Tail->prev==nullptr) // means that there is only one node 
			{
				_Head = nullptr;
				_Tail = nullptr;
			}
			else {
				Node<T>* TempTail = _Tail;
				_Tail = _Tail->prev;
				_Tail->next = nullptr;
				delete TempTail;
			}
			_Length--;
		}
	}


	void DeleteFront() {
		if (_Head != nullptr) {
			Node<T>* HeadTemp = _Head;
			_Head = HeadTemp->next;
			if (_Head!=nullptr) // after set new head check if it is not null 
			{
				_Head->prev = nullptr;
			}
			delete HeadTemp;
			_Length--;
		}
	}

	void DeleteAtIndex(short index) {
		if (_Head != nullptr && (index >= 0 && index < _Length)) {
			if (index == 0) {
				DeleteFront();
			}
			else if (index == _Length - 1) {
				DeleteBack();
			}
			else {
				Node<T>* NodeAtIndex = FindByIndex(index);

				NodeAtIndex->prev->next = NodeAtIndex->next;

				NodeAtIndex->next->prev = NodeAtIndex->prev;

				delete NodeAtIndex;
			}

			_Length--;
		}
	}


	void UpdateAtIndex(short index, T NewValue) {
		Node<T>* NodeToUpdate = FindByIndex(index);
		if (NodeToUpdate!=nullptr)
		{
			NodeToUpdate->data = NewValue;
			return;
		}
	}

	void Concat(DoublyLinkedList<T>& other) {
		
		// directly update the pointers of the tail of the first list and the head of the other list without loop
		
		if (_Tail != nullptr && other._Head != nullptr) {

			_Tail->next = other._Head;
			other._Head->prev = _Tail;
			_Tail = other._Tail;

			// Update the length of the current list
			_Length += other._Length;

			// Clear the other list
			other._Head = nullptr;
			other._Tail = nullptr;
			other._Length= 0;

		}
	}

	bool IsPalindrome() {
		if (_Head != nullptr)
		{
			Node<T>* TempTail = _Tail;
			for (Iterator<T> itr = _begin(); itr != _end(); itr.Next())
			{
				if (itr.current_node->data != TempTail->data)
				{
					return false;
				}
				TempTail = TempTail->prev;
			}

			return true;
		}
		return false;
	}

	T GetNthNodeValue(short N) {
		if (N>=1)
		{
			return FindByIndex(N - 1)->data;
		}
	}

	 void Reverse() {
		if (_Head!=nullptr)
		{
			Node<T>* TempHead = _Head;

			for (Iterator<T> itr = _begin(); itr != _end(); )
			{

				Node<T>* Temp = itr.current_node;
				Node<T>* TempNext = itr.current_node->next;
				itr.Next();
				Temp->next = Temp->prev;
				Temp->prev = TempNext;
			}
			_Head = _Tail;
			_Tail = TempHead;
		}
	}

	void Clear() {
		Iterator<T> itr = _begin();

		while (itr != _end()) {
			Node<T>* current = itr.current_node;
			itr.Next();
			delete current;
		}

		_Head = nullptr;
		_Tail = nullptr;
		_Length = 0;
	}


	void PrintFromFront() {
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

	void PrintFromBack() {
		Node<T> * TempTail= _Tail;
		while (TempTail !=nullptr)
		{
			cout << TempTail->data;
			if (TempTail!=_Head)
			{
				cout << " -> ";
			}
			TempTail=TempTail->prev;
		}
		cout << endl;
		delete TempTail;
	}

};


template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	_Head = nullptr;
	_Tail = nullptr;
	_Length = 0;
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