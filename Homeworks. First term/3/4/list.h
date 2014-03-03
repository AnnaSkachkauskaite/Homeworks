#pragma once;

struct ListElement
{
	int value;
	ListElement *next;
};

struct List
{
	ListElement *first;
};

void addValue (List *list, int numb);

void deleteValue (List *list, int numb);

void printList (List *list);

void deleteList (List *list);