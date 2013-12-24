#include <stdio.h>
#include "list.h"


void addValue (List *list, String *word)
{
	ListElement *tmp = list->first; 
	while (tmp->next != nullptr)
	{ 
		tmp = tmp->next;
	}
	ListElement *addValue = new ListElement;
	addValue->word = clone(word);                                  
	addValue->numb = 1;
	addValue->next = nullptr;
	tmp->next = addValue;
}

bool isNew (List *list, String *word)
{
	ListElement *tmp = list->first;
	while (tmp != nullptr)
	{
		bool isFind = false;
		int i = 0;
		if (areEquial(tmp->word, word))
			isFind = true;
		if (isFind)
		{
			++tmp->numb;
			return false;
		}
		tmp = tmp->next;
	}
	return true;
}

void printList (List *list)
{
	ListElement *tmp = list->first->next;
	while (tmp != nullptr)
	{
		printString(tmp->word);
		printf(" %d ", tmp->numb);
		tmp = tmp->next;
	}
	printf("\n");
}

List *createList ()
{
	List *result = new List;
	result->first = new ListElement;
	result->first->word = createString();
	result->first->next = nullptr;
	return result;
}


void deleteList (List *list)
{
	ListElement *tmp = list->first;
	ListElement *delValue = tmp;
	while (tmp)
	{
		deleteString(tmp->word);
		delete tmp->word;
		delValue = tmp;
		tmp = tmp->next;
		delete(delValue);
	}
}

bool isEmpty (List *list)
{
	return list->first->next == nullptr;
}