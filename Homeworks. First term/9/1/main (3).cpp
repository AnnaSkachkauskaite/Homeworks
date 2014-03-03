#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stringUnit.h"
#include "file.h"


int main ()
{
	FILE *file1 = open();
	FILE *file2 = open();
	String *strFile1[maxLinesNumber];
	String *strFile2[maxLinesNumber];
	for (int i = 0; i < maxLinesNumber; ++i)
	{
		strFile1[i] = createString();
		strFile2[i] = createString();
	}
	int strNumb1 = fileToStringArray (file1, strFile1);
	int strNumb2 = fileToStringArray (file2, strFile2);
	fclose(file1);
	fclose(file2);
	FILE *fileOut;
	fileOut = fopen("result.txt", "w");
	char *add = new char[maxStrLength];
	for (int i = 0; i <= strNumb1; ++i)
	{
		bool isFind = false;
		int j = 0;
		while ((!isFind) && (j <= strNumb2))
		{
			if (areEquial(strFile1[i], strFile2[j]))
			{
				for (int i = 0; i < maxStrLength; ++i)
					add[i] = 0;
				strToChar(strFile1[i], add);
				for (int i = 0; i < strLength(add) - 1; ++i)
				{
					fprintf(fileOut, "%c", add[i]);
				}
				fprintf(fileOut, "\n");
				isFind = true;
			}
			++j;
		}
	}

	fclose(fileOut);
	for (int i = 0; i < maxLinesNumber; ++i)
	{
		deleteString(strFile1[i]);
		deleteString(strFile2[i]);
		delete strFile1[i];
		delete strFile2[i];
	}
	//delete strFile1;
	//delete strFile2;
	delete []add;
}