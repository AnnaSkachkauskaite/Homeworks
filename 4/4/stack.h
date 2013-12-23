#pragma once

struct Stack                
{ 
	char symbol;
	Stack *next;
};

Stack *push(Stack *head, char a);

char top(Stack **head);

char pop(Stack **head);

int priority(char a);

void deleteStack(Stack **head);

bool isNumb (char a);

bool isSighn (char a);
