
#include "DoublyLinkedList.h"


int main()
{
	DoublyLinkedList<int> dLinkedList;
	
	dLinkedList.InsertEnd(1);
	dLinkedList.InsertEnd(2);
	dLinkedList.InsertEnd(3);
	dLinkedList.InsertEnd(1);
	dLinkedList.InsertEnd(1);
	dLinkedList.PrintFromFront();
	cout << boolalpha<<dLinkedList.IsPalindrome() << endl;

}
