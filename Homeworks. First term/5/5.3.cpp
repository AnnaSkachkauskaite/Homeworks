#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main ()
{
	FILE *fin;
	char fileName[100];
	printf("Enter file adress\n");
	gets(fileName);
	fin = fopen(fileName, "r");
	char str[100];
	while (!feof(fin)) 
	{
		fgets(str, 100, fin);
		int numbSymb = 0;
		while (str[numbSymb] != '\n')
		{
			if (str[numbSymb] == '"')
			{
				while(str[numbSymb + 1] != '"')
				{
					++numbSymb;
				}
				numbSymb = numbSymb + 2;
			}
			if ((str[numbSymb] == '/') && (str[numbSymb + 1] == '*'))
			{
				while ((str[numbSymb + 3] != '/') && (str[numbSymb + 2] != '*'))
				{
					++numbSymb;
				}
				numbSymb = numbSymb + 4;
			}
			else if ((str[numbSymb] == '/') && (str[numbSymb + 1] == '/'))
			{
				while (str[numbSymb] != '\n')
				{
					printf("%c",str[numbSymb]);
					++numbSymb;
				}
				printf("\n");
			}
			else
			{
				++numbSymb;
			}
		}
	}
	scanf("%c", &fileName[0]);
	fclose(fin);
}