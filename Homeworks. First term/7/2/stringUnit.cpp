#include <stdio.h>
#include "stringUnit.h"

String *createString ()
{
	String *string = new String;
	string->first = new StringElement;
	string->first->next = nullptr;
	return string;
}

bool isEmpty (String *string)
{
	return string->first->next == nullptr;
}

void addSymbol (String *string, char symb)
{
	if (isEmpty(string))
	{
		StringElement *tmp = string->first;
		StringElement *addElem = new StringElement;
		addElem->symb = symb;
		addElem->next = nullptr;
		tmp->next = addElem;
		string->last = addElem;
	}
	else
	{
		StringElement *tmp = string->last;
		StringElement *addElem = new StringElement;
		addElem->symb = symb;
		addElem->next = nullptr;
		tmp->next = addElem;
		string->last = string->last->next;
	}
}

void printString (String *string)
{
	StringElement *tmp = string->first->next;
	while (tmp != nullptr)
	{
		printf("%c", tmp->symb);
		tmp = tmp->next;
	}
	printf("\n");
}

void deleteString (String *string)
{
	StringElement *tmp = string->first;
	StringElement *delValue = tmp;
	while (tmp)
	{
		delValue = tmp;
		tmp = tmp->next;
		delete(delValue);
	}
}

String *clone (String *string)
{
	String *result = createString();
	StringElement *tmp = string->first->next;
	while (tmp != nullptr)
	{
		addSymbol(result, tmp->symb);
		tmp = tmp->next;
	}
	return result;
}

String *concatenation (String *string1, String *string2)
{
	String *result = createString();
	StringElement *tmp = string1->first->next;
	while(tmp != nullptr)
	{
		addSymbol(result, tmp->symb);
		tmp = tmp->next;
	}
	tmp = string2->first->next;
	while(tmp != nullptr)
	{
		addSymbol(result, tmp->symb);
		tmp = tmp->next;
	}
	return result;
}

int strLength (String *string)
{
	StringElement *tmp = string->first;
	int result = 0;
	while (tmp->next != nullptr) 
	{
		tmp = tmp->next;
		++result;
	}
	return result;
}

bool areEquial (String *string1, String *string2)
{
	bool result = true;
	if (strLength(string1) != strLength(string2))
		return false;
	StringElement *tmp1 = string1->first;
	StringElement *tmp2 = string2->first; 
	while ((tmp1->next != nullptr) && (tmp2->next != nullptr) && (result))
	{
		if (tmp1->symb != tmp2->symb)
			result = false;
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	return result;
}

String *copy (String *string, int pos1, int pos2)
{
	StringElement *tmp = string->first->next;
	for (int i = 0; i < pos1; ++i)
		tmp = tmp-> next;
	String *result = createString();
	for (int i = pos1; i <= pos2; ++i)
	{
		addSymbol(result, tmp->symb);
		tmp = tmp-> next;
	}
	return result;
}

void strToChar (String *string, char *newStr)
{
	StringElement *tmp = string->first->next;
	for (int i = 0; i < strLength(string); ++i)
	{
		newStr[i] = tmp->symb;
		tmp = tmp->next;
	}
}