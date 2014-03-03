#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "stack.h"
#include "intstack.h"

int main ()
{
	Stack *opers = nullptr;
	char input[80], outstring[80];
	int k = 0;
	int point = 0;
	printf("Enter task (with = in the end):\n");
	gets(input);                                 
	while ((input[k] != '\0') && (input[k] != '='))           
	{
		if (input[k] == ')')             
		{                                     
			while ((top(&opers)) != '(')         
			{
				outstring[point++] = pop(&opers);  
			}
			pop(&opers);
		}
		if (isNumb(input[k]))     
		{
			outstring[point++] = input[k];   
		}
		if (input[k] == '(')                         
		{
			opers = push(opers, '(');      
		}
		if (isSighn(input[k]))
		{                             
			if (opers == nullptr)                     
			{
				opers = push(opers, input[k]);  
			}
			else  if (priority(top(&opers)) < priority(input[k]))      
			{           
				opers = push(opers, input[k]);  
			}
			else                              
			{
				while ((opers != nullptr) && (priority(top(&opers)) >= priority(input[k])))
				{
					outstring[point++] = pop(&opers); 
				}
				opers = push(opers, input[k]);           
			} 
		}
		k++;                                    
	}
	while (opers != nullptr)                     
	{
		outstring[point++] = pop(&opers);    
	}
	outstring[point] = '\n';                    
	for (int i = 0; i <= point; ++i)
		printf("%c", outstring[i]);
	deleteStack(&opers);
	delete(opers);


	IntStack *numbers = nullptr;
	k = 0;                               
	while (outstring[k] != '\n')           
	{
		if (isNumb(outstring[k]))
		{
			numbers = push(numbers, numb(outstring[k]));
		}
		if (isSighn(outstring[k]))
		{
			int a = pop(&numbers);
			int b = pop(&numbers);
			numbers = push(numbers, calculate(a, b, outstring[k]));

		}
		++k;
	}
	printf("result: %d\n", pop(&numbers));
	deleteStack(&numbers);
	delete(numbers);
	scanf("%d", &k);
}
