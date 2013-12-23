#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int fact (int n)
{
	int result;
	if (n == 0)
	{ 
		result = 1;
		return result;
	}
	result = fact(n - 1) * n;
	return result;
}



int main() 
{
	printf("input number ");
	int n;
	scanf("%d", &n);
	int factorial;
	factorial = fact(n);
	printf("n! = %d\n", factorial);
	printf("input number ");
	scanf("%d", &n);
	factorial = 1;
	int i = 1;
	for (i; i <= n; ++i)
	{
		factorial = factorial * i;
	}
	printf("n! = %d\n", factorial);	
	scanf("%d", &n);
}