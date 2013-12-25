#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int maxStrLength = 100;

int hashFunction(char *str)
{
        int result = 0;
        for (int i = 0; i < strlen(str); ++i)
        {
                result = (str[i] + result * 13) % 157;
        }
        return result;
}

int maxPow(int numb)
{
        int result = 1;
        for (int i = 0; i < numb; ++i)
        {
                result = (result * 13) % 157;
        }
        return result;
}

int charToNumb (char c)
{
	return (int) c;
}

int main()
{
	printf("Enter main string:   ");
	char *str = new char[maxStrLength];
	gets(str);
	printf("Enter search string:   ");
	char *sub = new char[maxStrLength];
	gets(sub);
	printf("Position of occures:   ");
	int hashSub = hashFunction(sub);
	int hash = 0;
	bool isFind = false;
	int degree = maxPow(strlen(sub) - 1);
	for (int i = 0; i < strlen(str); ++i)
	{
		if (i < strlen(sub))
		{
			hash = (str[i] + hash * 13) % 157;
		}
		else
		{
			if (hash == hashSub)
			{
				isFind = true;
				int occPos = i - strlen(sub);
				printf("%d ", occPos);
			}
			hash = (hash - ((charToNumb(str[i - strlen(sub)])) * degree) % 157) % 157;
			if (hash < 0) 
				hash = 157 + hash;
			hash = ((hash * 13) % 157 + str[i]) % 157;
		}
	}
        
	if (hash == hashSub)
	{
		isFind = true;
		int occPos = strlen(str) - strlen(sub);
		printf("%d ",occPos);
	}        

	if (!isFind)
		printf("Occures not found\n");
	else
		printf("\n");
	gets(str);
	delete []str;
	delete []sub;
}
