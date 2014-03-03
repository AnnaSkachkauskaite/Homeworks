#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void units (int a)
{
	if (a == 1)
		printf("one");
	if (a == 2)
		printf("two");
	if (a == 3)
		printf("three");
	if (a == 4)
		printf("four");
	if (a == 5)
		printf("five");
	if (a == 6)
		printf("six");
	if (a == 7)
		printf("seven");
	if (a == 8)
		printf("eight");
	if (a == 9)
		printf("nine");
}

void teens (int a)
{
	if (a == 10)
		printf("ten");
	if (a == 11)
		printf("eleven");
	if (a == 12)
		printf("twelve");
	if (a == 13)
		printf("thirteen");
	if (a == 14)
		printf("fourteen");
	if (a == 15)
		printf("fifteen");
	if (a == 16)
		printf("sixteen");
	if (a == 17)
		printf("seventeen");
	if (a == 18)
		printf("eightteen");
	if (a == 19)
		printf("nineteen");
}

void tens (int a)
{
	if (a == 2)
		printf("twenty");
	if (a == 3)
		printf("thirty");
	if (a == 4)
		printf("forty");
	if (a == 5)
		printf("fifty");
	if (a == 6)
		printf("sixty");
	if (a == 7)
		printf("seventy");
	if (a == 8)
		printf("eighty");
	if (a == 9)
		printf("ninety");
}

void numbToName (int numb[3])
{
	if (numb[0] > 0)
	{
		units(numb[0]);
		printf(" hundred ");
		if ((numb[1] > 0) || (numb[2] > 0))
			printf("and ");
	}
	if (numb[1] > 1)
	{
		tens(numb[1]);
		if (numb[2] > 0)
			printf("-");
	}
	if (numb[1] == 1)
	{
		teens(numb[1] * 10 + numb[2]);
	}
	else if (numb[2] > 0)
	{
		units(numb[2]);
	}
}
