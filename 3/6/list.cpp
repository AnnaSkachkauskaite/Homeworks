#include <stdio.h>
#include "list.h"

void addValue (List *list, int numb)
{
	ListElement *tmp = list->first;
	while (tmp->next != nullptr)
	{ 
		tmp = tmp->next;
	}
	ListElement *addValue = new ListElement;
	addValue->value = numb;
	addValue->next = tmp->next;
	tmp->next = addValue;
}

void sort (List *list)
{
	ListElement *preSortEl = list->first->next;
	int value = 0;
	while (preSortEl->next != nullptr)
	{
		value = preSortEl->next->value;
		ListElement *tmp = list->first;
		while ((tmp != preSortEl->next) && (tmp->next->value <= value))
		{ 
			tmp = tmp->next;
		}
		if (tmp != preSortEl->next)
		{
		     ListElement *addValue = preSortEl->next;
	    	 preSortEl->next=preSortEl->next->next;
		     addValue->next = tmp->next;
		     tmp->next = addValue;
		}
		else
		{
		preSortEl = preSortEl->next;
		}
	}
}

void printList (List *list)
{
	ListElement *tmp = list->first->next;
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
