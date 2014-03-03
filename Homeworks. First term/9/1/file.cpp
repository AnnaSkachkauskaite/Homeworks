#include <stdio.h>
#include "stringUnit.h"
#include "file.h"

FILE *open ()
{
	printf("Enter file adress   ");
	char fileAdress[maxFileAdressLength];
	gets(fileAdress);
	return fopen(fileAdress, "r");
}

int fileToStringArray (FILE *file1, String *strFile1[maxLinesNumber])
{
	int strNumb1 = 0;
	char buf = 0;
	while (!feof(file1))
	{
		fscanf(file1, "%c", &buf);
		addSymbol(strFile1[strNumb1], buf);
		if (buf == '\n')
			++strNumb1;
	}
	return strNumb1;
}
