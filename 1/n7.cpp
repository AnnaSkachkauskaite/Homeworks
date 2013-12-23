#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
	printf("input number ");
	int numb = 0;
	scanf("%d", &numb);
	int a[1000];
	int i;
	for (i = 0; i <= numb; ++i)
	{
		a[i] = 1;
	}
	int j = 0;
	for (i = 2; i <= numb; ++i)
	{
		if (a[i] == 1)
		{ 
			for (j = i * 2; j <= numb; j += i)
			{
				a[j] = 0;
			}
		}
	}
	printf("prime numbers");
	for (i = 2; i <= numb; ++i)
	{
		if (a[i] == 1)
		{
			printf("%3d", i);
		}
	}
	scanf("%d", &i);
}

