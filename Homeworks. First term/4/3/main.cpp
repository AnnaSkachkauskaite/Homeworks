#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "intstack.h"

int main ()
{
	IntStack *numbers = nullptr;
	char input[80];
	int k = 0;
	printf("Enter task (with = in the end):\n");
	gets(input);                                 
	while ((input[k] != '\0') && (input[k] != '='))           
	{
		if (isNumb(input[k]))
		{
			numbers = push(numbers, numb(input[k]));
		}
		if (isSighn(input[k]))
		{
			int a = pop(&numbers);
			int b = pop(&numbers);
			numbers = push(numbers, calculate(a, b, input[k]));

		}
		++k;
	}
	printf("result: %d\n", pop(&numbers));
	deleteStack(&numbers);
	delete(numbers);
	scanf("%d", &k);
}