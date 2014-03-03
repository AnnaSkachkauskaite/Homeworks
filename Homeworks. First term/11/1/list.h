#pragma once;

const int maxFileAdressLength = 100;

struct ListElement
{
	int value;
	int count;
	ListElement *next;
};

struct List
{
	ListElement *first;
};

List *createList ();

void addValue (List *list, int numb, int count);

void deleteValue (List *list, int numb);

void printList (List *list);

void deleteList (List *list);

void makeList (FILE *file, List *list);

bool equals (List *list1, List *list2);

int value (List *list, int numb);

List *add (List *list1, List *list2);