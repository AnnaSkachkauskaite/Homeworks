#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "list.h"
;


int main ()
{
	printf("0 - exit \n 1 - add a value to sorted list \n 2 - remove a value from sorted list \n 3 - print list\n");
	enum UserCommand 
	{
		exit,
		add,
		del,
		print,
	};
	UserCommand command;
	scanf("%d", &command);
	List *list = new List;
	ListElement *head = new ListElement;
	ListElement *newEl = new ListElement;
	list->first = head;
	head->next = newEl;
	newEl->next = nullptr;
	while (command != exit)
	{
		if (command == add)
		{
			int numb = 0;
			printf("Enter number ");
			scanf("%d", &numb);
			addValue(list, numb);
		}
		if (command == del)
		{
			int numb = 0;
			printf("Enter number ");
			scanf("%d", &numb);
			deleteValue(list, numb);
		}
		if (command == print)
		{
			printList(list);
		}
		scanf("%d", &command);
	}
	deleteList(list);
	delete(list);
}
