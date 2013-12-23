#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stringUnit.h"

int main ()
{
	String *string;
	string = createString();
	String *sub;
	sub = createString();
	makeString(string);
	makeString(sub);
	printf("Position of occures  ");
	findOccures(string, sub);
	deleteString(string);
	deleteString(sub);
	delete string;
	delete sub;
	int i = 0;
	scanf("%d", &i);
}