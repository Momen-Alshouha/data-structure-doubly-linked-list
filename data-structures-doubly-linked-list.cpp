
#include "DoublyLinkedList.h"


int main()
{
	DoublyLinkedList<int> dLinkedList;
	
	dLinkedList.InsertEnd(1);
	dLinkedList.InsertEnd(2);
	dLinkedList.InsertEnd(3);
	dLinkedList.InsertEnd(4);
	dLinkedList.InsertBefore(2, 99);
	dLinkedList.InsertAfter(1, 100);
	dLinkedList.InsertAfter(99, 999);
	dLinkedList.InsertAfter(4, 555); 
	dLinkedList.InsertAtIndex(1, 213);
	//dLinkedList.PrintFromBack();
	dLinkedList.UpdateAtIndex(12, 888);
	dLinkedList.UpdateAtIndex(3, 777);
	dLinkedList.PrintFromFront();
	cout<<dLinkedList.GetNthNodeValue(2);
}
