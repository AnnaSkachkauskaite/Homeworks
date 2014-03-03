#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "circularList.h"
;
int main ()
{
	printf ("Enter number of people ");
	int numb = 0;
	scanf("%d", &numb);
	printf("Enter step ");
	int step = 0;
	scanf("%d", &step);
	List *list = new List;
	ListElement *head = new ListElement;
	list->first = head;
	makeList(list, numb);
	printList(list, numb);
	printf("%d", findNumb(list, numb, step));
	/*if (step == 1)
	{
		delete(list->first->next);
	}
	else
	{
		delete
	}*/
	delete(list);
	delete(head);
	scanf("%d", &step);
}
