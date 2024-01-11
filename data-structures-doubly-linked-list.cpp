
#include "DoublyLinkedList.h"


int main()
{
	DoublyLinkedList<int> dLinkedList;
	
	dLinkedList.InsertEnd(1);
	dLinkedList.InsertEnd(2);
	dLinkedList.InsertEnd(3);
	dLinkedList.InsertEnd(4);
	dLinkedList.InsertBefore(2, 99);
	cout << boolalpha << dLinkedList.isExisit(99) << endl;
	cout << boolalpha << dLinkedList.isExisit(999) << endl;
	dLinkedList.Print();
	cout << dLinkedList.length << endl;
	cout << dLinkedList.head->data << endl;
	cout << dLinkedList.tail->data << endl;
}
