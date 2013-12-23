#include <stdio.h>
#include "circularList.h"
;
void makeList (List *list, int numb)
{
	ListElement *tmp = list->first;
	for (int i = 1; i <= numb; ++i)
	{
		ListElement *addEl = new ListElement;
		addEl->value = i;
		tmp->next = addEl;
		tmp = addEl;
	}
	tmp->next = list->first->next;
}

int findNumb (List *list, int numb, int step)
{
	int result;
	ListElement *tmp = list->first;
	for (int i = 1; i < numb; ++i)
	{
		for (int j = 1; j < step; ++j)
		{
			tmp = tmp->next;
		}
		ListElement *delValue = tmp->next;
		tmp->next = tmp->next->next;
		delete(delValue);
	}
	if (step == 1)
	{
		result = list->first->next->value;
		delete(list->first->next);
	}
	else
	{
		result = tmp->value;
		delete(tmp);
	}
	return result;
}

void printList (List *list, int numb)
{
	ListElement *tmp = list->first->next;
	for (int i = 1; i <= numb; ++i)
	{
		printf("%d  ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}


