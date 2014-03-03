#include <stdio.h>
#include "list.h"

List *createList ()
{
	List *result = new List;
	result->first = new ListElement;
	result->first->next = nullptr;
	return result;
}

void addValue (List *list, int numb, int weight)
{
	ListElement *tmp = list->first;
	while (tmp->next != nullptr)
	{ 
		tmp = tmp->next;
	}
	ListElement *addValue = new ListElement;
	addValue->value = numb;
	addValue->weight = weight;
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
	int weight = 0;
	ListElement *tmp = list->first->next;
	while (tmp != nullptr)
	{
		printf("%d", tmp->value);
		if (tmp->next != nullptr)
			printf("-->");
		weight = weight + tmp->weight;
		tmp = tmp->next;
	}
	printf("\nWeight = %d \n", weight);
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
