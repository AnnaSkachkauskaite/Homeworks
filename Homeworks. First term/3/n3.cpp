#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main ()
{
	printf("Enter number ");
	int numb;
	scanf("%d", &numb);
	int num [100];
	int amount = 0;
	while (numb > 0)
	{
		num[amount] = numb % 10;
		numb = numb / 10;
		++amount;
	}
	for (int i = 0; i < amount - 1; ++i)
	{
		for (int j = i + 1; j < amount; ++j)
		{
			if (num[i] > num[j])
			{
				num[i] = num[i] + num[j];
				num[j] = num[i] - num[j];
				num[i] = num[i] - num[j];
			}
		}
	}
	if (num[0] != 0)
	{
		for (int i = 0; i < amount; ++i)
		{
			printf("%d", num[i]);
		}
	}
	else
	{
		int amount0 = 0;
		while (num[amount0] == 0)
		{
			++amount0;
		}
		printf("%d", num[amount0]);
		for (int i = 0; i < amount0; ++i)
		{
			printf("0");
		}
		for (int i = amount0 + 1; i < amount; ++i)
		{
			printf("%d", num[i]);
		}
	}
	printf("\n");
	scanf("%d", &numb);
}