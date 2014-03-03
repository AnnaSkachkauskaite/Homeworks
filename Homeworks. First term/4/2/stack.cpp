#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack *push(Stack *head, char a)
{
	struct Stack *ptr = new Stack;
	ptr->symbol = a;                                
	ptr->next = head;           
	return ptr;                               
}

char top(Stack **head)
{
	Stack *ptr = *head;
	return ptr->symbol;
}

char pop(Stack **head)
{
	if (*head == nullptr) 
	{
		return '\0'; 
	}
	Stack *ptr = *head;
	char a;                   
	a = ptr->symbol;
	*head = ptr->next;         
	delete(ptr);        
	return a;                   
}

int priority(char a)
{
	switch(a)
	{
		case '*':
		case '/':
			return 3;

		case '-':
		case '+':
			return 2;

		case '(':
			return 1;
	}
}

void deleteStack(Stack **head)
{
	Stack *ptr = *head;
	while (*head != nullptr)
	{
		ptr = *head;                   
		*head = ptr->next;         
		delete(ptr);  
	}
}

bool isNumb(char a)
{
	return (a >= '0') && (a <= '9');
}

bool isSighn(char a)
{
	return (a == '+') || (a == '-') || (a == '/') || (a == '*');
}
