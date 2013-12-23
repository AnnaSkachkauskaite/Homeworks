#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() 
{
	printf("input string\n");
	char str[1000];
	int numb = 0;
	str[numb] = getchar();
	while (str[numb] != '\n')
	{
		++numb;
		str[numb] = getchar();
	}
	--numb;
	int i = 0;
	bool palindrome = true;
	while ((i < (numb / 2)) && (palindrome))
	{
		if (str[i] != str[numb - i])
		{
			palindrome = false;
		}
		else
		{
			++i;
		}
	}
	if (palindrome)
	{
		printf("string is a palindrome\n");
	}
	else
	{
		printf("string is not a palindrome\n");
	}
	scanf("%d", &i);
}






