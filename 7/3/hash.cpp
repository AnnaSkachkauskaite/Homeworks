#include "hash.h"
#include <stdio.h>

void createHashArr (HashElem *hashArr[hashMax])
{
	for (int i = 0; i < hashMax; ++i)
	{
		hashArr[i] = new HashElem;
		hashArr[i]->list = createList();
	}
}

long hashFunction (char *s)
{
	int h = 0;
	while (s[0] > 0) 
		h = (h * 13 + *s++) % hashMax;
	return h;
}

void getWord (FILE *file, String *word)
{
	char c;
	while (((c = fgetc(file)) != ' ') && (c != '\n') && (c != EOF))
	{
		if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')) || ((c >= '0') && (c <= '9')))
		{
			addSymbol(word, c);
		}
	}
}

void makeHashArr (HashElem *hashArr[hashMax], FILE *file, int length[hashMax])
{
	String *word;
	for (int i = 0; i < hashMax; ++i)
		length[i] = 0;
	while(!feof(file))
	{
		word = createString();
		char *buf = new char[maxWordLength];
		getWord(file, word);
		strToChar(word, buf);
		int numb = hashFunction(buf);
		if(isNew(hashArr[numb]->list, word))
		{
			addValue(hashArr[numb]->list, word);
			++length[numb];
		}
		delete []buf;
		deleteString(word);
	}
}