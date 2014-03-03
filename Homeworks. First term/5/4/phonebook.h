#pragma once

const int maxNameLength = 50;
const int maxFileAdressLength = 100;
struct ListElement
{
	int phone;
	char name[maxNameLength];
	ListElement *next;
};

struct List
{
	ListElement *first;
};

void addValue (List *list, int numb, char name[maxNameLength]);

void printList (List *list);

void deleteList (List *list);

void findName (List *list, int numb);

void findNumber (List *list, char name[maxNameLength]);

void printListToFile (FILE *file, List *list);