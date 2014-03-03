#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void next (int part[1000], int &length)
{
	int i = 0, sum = 0;
	i = length - 1;
	sum = part[length];
	while ((i > 1) && (part[i - 1] <= part[i]))
	{
		sum = sum + part[i];
		--i;
	}
	++part[i];
	length = i + sum - 1;
	int j = 0;
	for (j = i + 1; j <= length; ++j)
	{
		part[j] = 1;
	}
}


 
int main()
{ 
	printf("enter number ");
	int numb = 0;
	scanf("%d", &numb);
	int length = numb;
	int part[1000];
	for (int i = 1; i <= numb; ++i)
	{
		part[i] = 1;
		printf("%d ", part[i]);
	}
	printf("\n");
	while (length > 1)
	{
		next(part, length);
		for (int i = 1; i <= length; ++i)
		{
			printf("%d ", part[i]);
		}
		printf("\n");
	}
	scanf("%d", &numb);
}
