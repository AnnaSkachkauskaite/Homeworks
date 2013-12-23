#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void enterStr (char str1[1000], int st1 [500])
{
	int  length1 = 0;
	for (int i = 0; i < 500; ++i)
	{
		st1[i] = 0;
	}
	str1[length1] = getchar();
	int numb = (int)str1[length1];
		++st1[numb];
	while (str1[length1] != '\n')
	{
		++length1;
		str1[length1] = getchar();
		numb = (int)str1[length1];
		++st1[numb];
	}
}


int main ()
{
	printf ("input 1st string:\n");
	char str1[1000];
	int st1 [500];
	enterStr(str1, st1);
	printf ("input 2nd string:\n");
	char str2[1000];
	int st2 [500];
	enterStr(str2, st2);
	bool coincidence = true;
	int i = 0;
	while ((coincidence) && (i < 500))
	{
		if (st1[i] != st2[i])
		{
			coincidence = false;
		}
		else
		{
			++i;
		}
	}
	if (coincidence)
	{
		printf("The first string can be alerted in the second");
	}
	else
	{
		printf("The first string can't be alerted in the second");
	}
	scanf("%d", &st1[0]);
}



