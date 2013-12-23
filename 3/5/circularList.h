#pragma once

struct ListElement 
{
	int value;
	ListElement *next;
};

struct List
{
	ListElement *first;
};

void makeList (List *list, int numb);

int findNumb (List *list, int numb, int m);

void printList (List *list, int numb);
