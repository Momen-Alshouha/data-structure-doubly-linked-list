
#include "DoublyLinkedList.h"


int main()
{
	DoublyLinkedList<int> dLinkedList, dLinkedList2;
	
	dLinkedList.InsertEnd(1);
	dLinkedList.InsertEnd(2);
	dLinkedList.InsertEnd(3);
	dLinkedList.InsertEnd(4);
	dLinkedList.InsertBefore(2, 99);
	dLinkedList.InsertAfter(1, 100);
	dLinkedList.InsertAfter(99, 999);
	dLinkedList.InsertAfter(4, 555); 
	dLinkedList.InsertAtIndex(1, 213);
	dLinkedList.UpdateAtIndex(12, 888);
	dLinkedList.UpdateAtIndex(3, 777);
	dLinkedList.PrintFromBack();
	dLinkedList.DeleteFront();
	dLinkedList.DeleteBack();
	dLinkedList.PrintFromFront();
	dLinkedList.DeleteBack();
	dLinkedList.DeleteFront();
	dLinkedList.PrintFromFront();
	dLinkedList.DeleteAtIndex(4);
	cout << dLinkedList.length << endl;
	//dLinkedList.DeleteBack();
	dLinkedList.PrintFromFront();
	cout << dLinkedList.length << endl;
	// cout << dLinkedList.length << endl;
	dLinkedList2.InsertEnd(1);
	dLinkedList2.InsertEnd(2);
	dLinkedList2.InsertEnd(3);
	dLinkedList2.InsertEnd(4);
	dLinkedList2.InsertBefore(2, 99);
	dLinkedList2.InsertAfter(1, 100);
	dLinkedList2.InsertAfter(99, 999);
	dLinkedList2.InsertAfter(4, 555);

	cout << endl<< endl;
	dLinkedList.Concat(dLinkedList2);
	dLinkedList.PrintFromFront();
	dLinkedList.PrintFromBack();

}
