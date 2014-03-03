#pragma once

struct IntStack                
{ 
	int symbol;
	IntStack *next;
};

IntStack *push(IntStack *head, int a);

int top(IntStack **head);

int pop(IntStack **head);

int priority(char a);

void deleteStack(IntStack **head);

bool isNumb (char a);

bool isSighn (char a);

int numb(char a);

int calculate(int a, int b, char sighn);