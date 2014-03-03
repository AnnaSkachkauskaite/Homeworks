#include <iostream>
#include "pointlist.h"
#include "arrlist.h"

int main()
{
	PoinerList *list = new PoinerList;
	list->addValue(7);
	list->addValue(3);
	list->addValue(11);
	list->printList();
	list->deleteValue(3);
	list->printList();
	delete list;


	ArrayList *list2 = new ArrayList;
	list2->addValue(12);
	list2->addValue(2);
	list2->addValue(8);
	list2->printList();
	list2->deleteValue(2);
	list2->deleteValue(5);
	list2->printList();
}