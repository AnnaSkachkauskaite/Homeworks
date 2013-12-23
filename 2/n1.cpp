#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fibonacci (int n)
{
	int result = 0;
	if (n == 1)
	{
		result = 1;
		return result;
	}
	else    if (n == 2)
	{
		result = 1;
		return result;
	}
	else   
	{
		result = fibonacci(n - 1) + fibonacci(n - 2);
		return result;
	}
}

void main ()
{
	printf("enter number ");
	int numb;
	scanf("%d", &numb);
	printf("Fibonacci number = %d\n", fibonacci(numb));
	printf("enter n ");
	scanf("%d", &numb);
	int fib[100];
	fib[1] = 1;
	fib[2] = 1;
	int i;
	for (i = 3; i <= numb; ++i)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	printf("Fibonacci number = %d\n", fib[numb]);
	scanf("%d", &numb);
}



