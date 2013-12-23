#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "numbtoname.h"

int main ()
{
	printf("Enter number\n");
	char numbChar[7];
	int num = 0;
	numbChar[num] = getchar();
	while (numbChar[num] != '\n')
	{
		++num;
		numbChar[num] = getchar();
	}
	int hundred[3] = {0, 0, 0};
	int thousand[3] = {0, 0, 0};
	int numb[6] = {0, 0, 0, 0, 0, 0};
	for(int i = 0; i < num; ++i)
	{
		numb[i + 6 - num] = numbChar[i] - '0';
	}
	for(int i = 0; i < 3; ++i)
	{
		thousand[i] = numb[i];
		hundred[i] = numb[i + 3];
	}
	numbToName(thousand);
	if ((thousand[0] > 0) || (thousand[1] > 0) || (thousand[2] > 0))
	{
		printf (" thousand ");
		if ((hundred[0] == 0) && ((hundred[1] > 0) || (hundred[2] > 0)))
			printf ("and ");
	}
	numbToName(hundred);
	scanf("%d", &numb[0]);
}
