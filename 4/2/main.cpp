#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "stack.h"

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
	outstring[point] = '\0';                    
	printf("\n%s\n", outstring); 
	deleteStack(&opers);
	delete(opers);
	scanf("%d", &k);
}
