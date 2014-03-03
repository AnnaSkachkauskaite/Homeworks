#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int involution (int a, int n)
{
	int result = 1;
	if (n == 0)
	{
		result = 1;
		return result;
	}
	result = involution(a,(n - 1)) * a;
	return result;
}


int main() 
{
	printf("input a ");
	int a = 0;
	scanf("%d", &a);
	printf("input n ");
	int n = 0;
	scanf("%d", &n);
	printf("a ^ n = %d\n", involution(a, n));
	scanf("%d", &a);
}

