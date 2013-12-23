#pragma once

struct StringElement
{
	char symb;
	StringElement *next;
};

struct String 
{
	StringElement *first;
	StringElement *last;
};

String *createString ();

bool isEmpty (String *string);

void addSymbol (String *string, char symb);

void printString (String *string);

void deleteString (String *string);

String *clone (String *string);

String *concatenation (String *string1, String *string2);

int strLength (String *string);

bool areEquial (String *string1, String *string2);

String *copy (String *string, int pos1, int pos2);

void strToChar (String *string, char *newStr);