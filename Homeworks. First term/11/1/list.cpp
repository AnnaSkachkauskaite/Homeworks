#include <stdio.h>
#include "list.h"

List *createList ()
{
	List *result = new List;
	result->first = new ListElement;
	result->first->next = nullptr;
	return result;
}

void addValue (List *list, int numb, int count)
{
	ListElement *tmp = list->first;
	bool isFind = false;
	while ((tmp != nullptr) && (!isFind))
	{
		if (tmp->value == numb)
		{
			isFind = true;
			tmp->count += count;
		}
		else
			tmp = tmp->next;
	}
	if (!isFind)
	{
		tmp = list->first;
		while ((tmp->next != nullptr) && (tmp->next->value > numb))
		{ 
			tmp = tmp->next;
		}
	
		ListElement *addValue = new ListElement;
		addValue->value = numb;
		addValue->count = count;
		addValue->next = tmp->next;
		tmp->next = addValue;
	}
}

void deleteValue (List *list, int numb)
{
	ListElement *tmp = list->first;
	bool delEl = false;
	while ((tmp->next->value != numb) && (tmp->next->next != nullptr))
	{
		tmp = tmp->next;
		if (tmp->next->value == numb)
		{
			delEl = true;
		}
	}
	if (!delEl)
	{
		printf("Element not found\n");
	}
	else
	{
		ListElement *delValue = tmp->next;
		tmp->next = tmp->next->next;
		delete(delValue);
	}
}

void printList (List *list)
{
	ListElement *tmp = list->first->next;
	while (tmp != nullptr)
	{
		printf("%dX^%d ", tmp->count, tmp->value);
		if (tmp->next != nullptr) 
			if (tmp->next->count > 0)
				printf("+ ");
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



void makeList (FILE *file, List *list)
{
	int numb = 0;
	int count = 0;
	while (!feof(file))
	{
		fscanf(file, "%d %d", &numb, &count);
		addValue(list, numb, count);
	}
}

bool equals (List *list1, List *list2)
{
	ListElement *tmp1 = list1->first->next;
	ListElement *tmp2 = list2->first->next;
	while ((tmp1 != nullptr) && (tmp2 != nullptr))
	{
		if ((tmp1->count != tmp2->count) || (tmp1->value != tmp2->value))
			return false;
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	if ((tmp1 != nullptr) || (tmp2 != nullptr))
		return false;
	return true;
}

long int pow(int numb, int deg)
{
    long int a = numb, result = 1;
    while (deg > 0)
    {
        if ((deg & 1) != 0)
            result *= a;
        a *= a;
        deg >>= 1;
    }
    return result;
}

int value (List *list, int numb)
{
	int result = 0;
	ListElement *tmp = list->first->next;
	while (tmp != nullptr)
	{
		result = result + tmp->count * pow(numb, tmp->value);
		tmp = tmp->next;
	}
	return result;
}

List *add (List *list1, List *list2)
{
	List *result = createList();
	ListElement *tmp1 = list1->first->next;
	ListElement *tmp2 = list2->first->next;
	while (tmp1 != nullptr)
	{
		addValue(result, tmp1->value, tmp1->count);
		tmp1 = tmp1->next;
	}
	while (tmp2 != nullptr)
	{
		addValue(result, tmp2->value, tmp2->count);
		tmp2 = tmp2->next;
	}
	return result;
}
