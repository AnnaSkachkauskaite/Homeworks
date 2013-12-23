#pragma once
#include "stringUnit.h"


const int maxWordLength = 1000;
const int maxFileAdressLength = 100;
const int hashMax = 1000;

struct ListElement
{
	String *word;
	int numb;
	ListElement *next;
};

struct List
{
	ListElement *first;
};

void addValue (List *list, String *word);

bool isNew (List *list, String *word);

void printList (List *list);

List *createList ();

void deleteList (List *list);

bool isEmpty (List *list);