#include <stdio.h>
#include "list.h"

void addValue (List *list, int numb)
{
	ListElement *tmp = list->first->next;
	while ((tmp->next != nullptr) && (tmp->next->value < numb))
	{ 
		tmp = tmp->next;
	}
	ListElement *addValue = new ListElement;
	addValue->value = numb;
	addValue->next = tmp->next;
	tmp->next = addValue;
}

void deleteValue (List *list, int numb)
{
	ListElement *tmp = list->first;
	bool delEl = false;
	while ((tmp->next->value != numb) && (tmp->next->next != nullptr))
	{
		tmp = tmp->next;
		if (tmp->next->value == numb)
		{
			delEl = true;
		}
	}
	if (!delEl)
	{
		printf("Element not found\n");
	}
	else
	{
		ListElement *delValue = tmp->next;
		tmp->next = tmp->next->next;
		delete(delValue);
	}
}

void printList (List *list)
{
	ListElement *tmp = list->first->next->next;
	while (tmp != nullptr)
	{
		printf("%d  ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

void deleteList (List *list)
{
	ListElement *tmp = list->first;
	ListElement *delValue = tmp;
	while (tmp)
	{
		delValue = tmp;
		tmp = tmp->next;
		delete(delValue);
	}
}
