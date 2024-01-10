#pragma once
#include "Node.h"

template<typename T>
class Iterator {
	
	Node<T>* _CurrentNode;

public:
	
	Iterator() :_CurrentNode(nullptr) {};
	
	Iterator(Node<T>* CurrentNode) :_CurrentNode(CurrentNode){};

	Node<T>* GetCurrenctNode() {
		return _CurrentNode;
	}

	T GetData()
	{
		return _CurrentNode->data;
	}

	void SetData(T Data) {
		_CurrentNode->data = Data;
	}

	Node<T>* Next() {
		if (_CurrentNode != nullptr)
		{
			_CurrentNode = _CurrentNode->next;
			return _CurrentNode;
		}
		return nullptr;
	}

	bool operator!=(const Iterator& other) const { // operator overloading
		return _CurrentNode != other._CurrentNode;
	}

	__declspec(property(get = GetData, put = SetData)) T data;
	__declspec(property(get = GetCurrentNode)) Node<T>* current_node;

};