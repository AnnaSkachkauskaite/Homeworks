#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "list.h"
;


int main ()
{
	printf("Input number of elements ");
	int numb = 0;
	scanf("%d", &numb);
	printf("Enter elements\n");
	List *list = new List;
	ListElement *head = new ListElement;
	list->first = head;
	head->next = nullptr;
	int element = 0;
	for (int i = 1; i <=numb; ++i)
	{
		scanf("%d", &element);
		addValue(list, element);
	}
	sort(list);
	printf("Sorted list\n");
	printList(list);
	deleteList(list);
	delete(list);
	scanf("%d", &element);
}
