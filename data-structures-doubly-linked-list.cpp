
#include "DoublyLinkedList.h"


int main()
{
	DoublyLinkedList<int> dLinkedList;
	
	dLinkedList.InsertEnd(1);
	dLinkedList.InsertEnd(2);
	dLinkedList.InsertEnd(3);
	dLinkedList.InsertEnd(4);
	dLinkedList.InsertEnd(5);
	dLinkedList.InsertEnd(6);
	
	dLinkedList.PrintFromFront();
	dLinkedList.Reverse();
	dLinkedList.PrintFromFront();


}
