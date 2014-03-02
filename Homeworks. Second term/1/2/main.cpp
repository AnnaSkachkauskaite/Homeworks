#include <iostream>
#include "arrstack.h"
#include "pointstack.h"

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

bool isNumb(char a)
{
	return (a >= '0') && (a <= '9');
}

bool isSighn(char a)
{
	return (a == '+') || (a == '-') || (a == '/') || (a == '*');
}

int main ()
{
	PointerStack *opers = new PointerStack;
	char input[80], outstring[80];
	int k = 0;
	int point = 0;
	printf("Enter task (with = in the end):\n");
	gets(input);                                 
	while ((input[k] != '\0') && (input[k] != '='))           
	{
		if (input[k] == ')')             
		{                                     
			while ((opers->getTop()) != '(')         
			{
				outstring[point++] = opers->pop();  
			}
			opers->pop();
		}
		if (isNumb(input[k]))     
		{
			outstring[point++] = input[k];   
		}
		if (input[k] == '(')                         
		{ 
			opers->push('(');
		}
		if (isSighn(input[k]))
		{                             
			if (opers->isEmpty())                     
			{
				opers->push(input[k]);
			}
			else  if (priority(opers->getTop()) < priority(input[k]))      
			{            
				opers->push(input[k]);
			}
			else                              
			{
				while ((opers != nullptr) && (priority(opers->getTop()) >= priority(input[k])))
				{
					outstring[point++] = opers->pop(); 
				}
				opers->push(input[k]);
			} 
		}
		k++;                                    
	}
	while (!(opers->isEmpty()))                     
	{
		outstring[point++] = opers->pop();    
	}
	outstring[point] = '\n';                    
	for (int i = 0; i <= point; ++i)
		printf("%c", outstring[i]);
	delete(opers);


	ArrayStack *numbers = new ArrayStack;
	k = 0;                               
	while (outstring[k] != '\n')           
	{
		if (isNumb(outstring[k]))
		{
			numbers->push(numb(outstring[k]));
		}
		if (isSighn(outstring[k]))
		{
			int a = numbers->pop();
			int b = numbers->pop();
			numbers->push(calculate(a, b, outstring[k]));

		}
		++k;
	}
	printf("result: %d\n", numbers->pop());
	delete(numbers);
	scanf("%d", &k);
}