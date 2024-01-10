#pragma once

template<typename T>
class Node {

	T _Data;
	Node<T>* _ptrToNext, * _ptrToPrev;

public:

	Node(T Data) :_Data(Data), _ptrToPrev(nullptr), _ptrToNext(nullptr) {};

	T GetData() {
		return _Data;
	}

	void SetData(T Data) {
		_Data = Data;
	}

	Node<T>* GetNext() {
		if (_ptrToNext != nullptr)
		{
			return _ptrToNext;
		}
		return nullptr;
	}

	void SetNext(Node<T>* ptrNode) {
		_ptrToNext = ptrNode;
	}

	Node<T>* GetPrev() {
		if (_ptrToPrev != nullptr)
		{
			return _ptrToPrev;
		}
		return nullptr;
	}

	void SetPrev(Node<T>* ptrNode) {
		_ptrToPrev = ptrNode;
	}

	__declspec(property(get = GetData, put = SetData)) T data;
	__declspec(property(get = GetNext, put = SetNext)) Node<T>* next;
	__declspec(property(get = GetPrev, put = SetPrev)) Node<T>* prev;

};


