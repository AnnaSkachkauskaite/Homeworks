#include <stdio.h>
#include <stdlib.h>
#include "intstack.h"

IntStack *push(IntStack *head, int a)
{
	IntStack *ptr = new IntStack;
	ptr->symbol = a;                                
	ptr->next = head;           
	return ptr;                               
}

int top(IntStack **head)
{
	IntStack *ptr = *head;
	return ptr->symbol;
}

int pop(IntStack **head)
{
	if (*head == nullptr) 
	{
		return '\0'; 
	}
	IntStack *ptr = *head;
	char a;           
	a = ptr->symbol;
	*head = ptr->next;         
	delete(ptr);        
	return a;                   
}

void deleteStack(IntStack **head)
{
	IntStack *ptr = *head;
	while (*head != nullptr)
	{
		ptr = *head;                   
		*head = ptr->next;         
		delete(ptr);  
	}
}

int numb(char a)
{
	return a - '0';
}

int calculate(int a, int b, char sighn)
{
	switch(sighn)
	{
		case '*':
			return a * b;
		case '/':
			return a / b;
		case '+':
			return a + b;
		case '-':
			return a - b;
	}

}

