#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stringUnit.h"

int main ()
{
	String *string = createString();
	if (isEmpty(string))
		printf("1\n");
	addSymbol(string, 'h');
	addSymbol(string, 'i');
	addSymbol(string, 't');
	printString(string);
	String *string2 = clone(string);
	printString(string2);
	String *string3 = concatenation(string, string2);
	printString(string3);
	printString(string);
	printf("%d %d\n", strLength(string), strLength(string3));
	if (areEquial(string,string2))
		printf("string = string2\n");
	if (!areEquial(string,string3))
		printf("string != string3\n");
	String *copy1 = copy(string3, 0, 3);
	printString(copy1);
	deleteString(copy1);
	delete(copy1);
	char *str = new char[50];
	printString(string3);
	strToChar(string3, str);
	for (int i = 0; i < strLength(string3); ++i)
	{
		printf("%c", str[i]);
	}
	delete []str;
	deleteString(string);
	delete(string);
	deleteString(string2);
	delete(string2);
	deleteString(string3);
	delete(string3);
	int i = 0;
	scanf("%d", &i);
}