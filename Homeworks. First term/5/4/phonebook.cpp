#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "phonebook.h"

void addValue (List *list, int numb, char name[maxNameLength])
{
	ListElement *tmp = list->first;
	while (tmp->next != nullptr)
	{ 
		tmp = tmp->next;
	}
	ListElement *addValue = new ListElement;
	addValue->phone = numb;
	for (int i = 0; i < maxNameLength; ++i)
	 addValue->name[i] = name[i];
	addValue->next = tmp->next;
	tmp->next = addValue;
}

void printList (List *list)
{
	ListElement *tmp = list->first->next;
	while (tmp != nullptr)
	{
		printf("%d  %s\n", tmp->phone, tmp->name);
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

void findName (List *list, int numb)
{
	ListElement *tmp = list->first;
	bool isFind = false;
	while (tmp != nullptr)
	{
		if (tmp->phone == numb)
		{
			printf("%s\n", tmp->name);
			 isFind = true;
			return;
		}
		tmp = tmp->next;
	}
	if (!isFind)
	{
		printf("No matches found!\n");
	}
}

void findNumber (List *list, char name[maxNameLength])
{
	ListElement *tmp = list->first;
	bool isFind = false;
	while (tmp != nullptr)
	{
		bool isName = true;
		for(int i = 0; i < maxNameLength; ++i)
		{
			if (tmp->name[i] != name[i])
				isName = false;
		}
		if (isName)
		{
			printf("%d\n", tmp->phone);
			isFind = true;
			return;
		}
		tmp = tmp->next;
	}
	if (!isFind)
	{
		printf("No matches found!\n");
	}
}

void printListToFile (FILE *file, List *list)
{
	ListElement *tmp = list->first->next;
	while (tmp != nullptr)
	{
		fprintf(file, "%d  %s\n", tmp->phone, tmp->name);
		tmp = tmp->next;
	}
	printf("\n");
}