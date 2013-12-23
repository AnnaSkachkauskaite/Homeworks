#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "phonebook.h"
;

enum UserCommand
	{
		exit,
		add,
		findNum,
		findNam,
	};

int main ()
{
	printf("Enter phonebook adress\n");
	FILE *file;
	char fileAdress[maxFileAdressLength];
	for (int i = 0; i < maxFileAdressLength; ++i)
		fileAdress[i] = 0;
	gets(fileAdress);
	file = fopen(fileAdress, "r");
	List *list = new List;
	ListElement *head = new ListElement;
	list->first = head;
	head->next = nullptr;
	int phone;
	char name[maxNameLength];
	for (int i = 0; i < maxNameLength; ++i)
		name[i] = '0';
	if (file != NULL)
	{
		while(!feof(file))
			{
				fscanf(file, "%d %s\n", &phone, &name);
					addValue(list, phone, name);
			}
		fclose(file);
	}
	printList(list);
	printf("0 - exit \n 1 - add record \n 2 - find number \n 3 - find name\n");
	UserCommand command;
	scanf("%d", &command);
	while (command != exit)
	{
		if (command == add)
		{
			printf("Enter name and phone number(Ex.:Name 0000000) ");
			char name[maxNameLength];
			for (int i = 0; i < maxNameLength; ++i)
				name[i] = '0';
			int number;
			scanf("%s %d", &name, &number);
			addValue(list, number, name);
		}
		if (command == findNum)
		{
			if(list->first->next == nullptr)
			{
				printf("Phonebook is empty!\n");
			}
			else
			{
				printf("Enter name ");
				char name[maxNameLength];
				for (int i = 0; i < maxNameLength; ++i)
					name[i] = '0';
				int number;
				scanf("%s", &name);
				findNumber(list, name);
			}
		}
		if (command == findNam)
		{
			if(list->first->next == nullptr)
			{
				printf("Phonebook is empty!\n");
			}
			else
			{
				printf("Enter number ");
				int number;
				scanf("%d", &number);
				findName(list, number);
			}
		}
		scanf("%d", &command);
	}
	file = fopen(fileAdress, "w");
	printListToFile(file, list);
	fclose(file);
	deleteList(list);
	delete(list);
}
