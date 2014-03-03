#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
	printf("enter 1st string\n");
	char s[1000];
	int length = 0;
	s[length] = getchar();
	while (s[length] != '\n')
	{
		++length;
		s[length] = getchar();
	}
	printf("enter 2nd string\n");
	char s1[100];
	int length1 = 0;
	s1[length1] = getchar();
	while (s1[length1] != '\n')
	{
		++length1;
		s1[length1] = getchar();
	}
	int i = 0, j = 0;
	int numbOccurrences = 0;
	bool occurrence = true;
	for (i; i <= (length - length1); ++i)
	{
		if (s[i] == s1[0])
		{
			 occurrence = true;
			j = i;
			for (j; j <= (i + length1 - 1); ++j)
			{
				if (s[j] != s1[j - i]) 
				{
					 occurrence = false;
				}
			}
			if (occurrence)
			{
				numbOccurrences++;
			}
		}
	}
	printf("number of occurrences %d\n", numbOccurrences);
	scanf("%d", i);
		
}



