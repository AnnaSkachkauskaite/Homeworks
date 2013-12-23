#pragma once

struct ListElement
{
	int value;
	int weight;
	ListElement *next;
};

struct List
{
	ListElement *first;
};

List *createList ();

void addValue (List *list, int numb, int weight);

void printList (List *list);

void deleteList (List *list);

void sort (List *list);
