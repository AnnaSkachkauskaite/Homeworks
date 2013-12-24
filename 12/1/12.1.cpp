#include <stdio.h>

const int maxFileAdressLength = 100;

bool isCorrect(FILE *file);
bool sum(FILE* file, char& c);
bool sum_(FILE* file, char& c);
bool mul(FILE* file, char& c);
bool mul_(FILE* file, char& c);
bool bracketsAndTokens(FILE* file, char& c);
bool isDouble(FILE* file, char& c);

bool isNumb (char c)
{
	return (c >= '0') && (c <= '9');
}

bool isSignOrBrackrts (char c)
{
	return (c == '/') || (c == '*') || (c == '(') || (c == ')') || (c == '+') || (c == '-');
}

bool isExp (char c)
{
	return c == 'E';
}

bool isPoint (char c)
{
	return c == '.';
}

bool isCorrect(FILE *file)
{
    char c = fgetc(file);
    return (sum(file, c) && ((c == '\n') || ((int)c == -1)));
}

bool isFirstOrderOperation (char c)
{
	return (c == '/') || (c == '*');
}

bool isSecondOrderOperation (char c)
{
	return (c == '+') || (c == '-');
}


bool sum(FILE* file, char& c)
{
	return (mul(file, c) && sum_(file, c));
}

bool sum_(FILE* file, char& c)
{
	if (isSecondOrderOperation(c))
	{
		c = fgetc(file);
		if (mul(file, c) && (sum_(file, c)))
			return true;
		else
		{
			ungetc(c, file);
			return false;
		}
	}
	else
		return true;
}


bool mul(FILE* file, char& c)
{
	return(bracketsAndTokens(file, c) && mul_(file, c));
}

bool mul_(FILE* file, char& c)
{
	if (isFirstOrderOperation(c))
	{
		c = fgetc(file);
		if (bracketsAndTokens(file, c) && (mul_(file, c)))
			return true;
		else
		{
			ungetc(c,file);
			return false;
		}
	}
	else
		return true; 
}

bool bracketsAndTokens(FILE* file, char& c)
{
	if (c == '(')
	{
		c = fgetc(file);

		if (sum(file, c) && c == ')')
		{
			c = fgetc(file);
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return isDouble(file, c);
	}
}

bool isDouble(FILE* file, char& c)
{
	if (c == '-')
		c = fgetc(file);
	if (!(isNumb(c)))
		return false;

	enum Position
	{
		intPart, 
		point, 
		exp, 
		FractPart, 
		signAfterExp, 
		degree,
	};
	Position position = intPart;

	while((!feof(file) && !isSignOrBrackrts(c)) || ((position == signAfterExp) && ((c == '+')||(c == '-'))))
	{
		c = fgetc(file);
		switch(position)
		{
			case intPart:
			{
				if (isNumb(c))
					position = intPart;
				else if (isExp(c))
					position = exp;
				else if (isPoint(c))
					position = point;
				else if ((c != '\n') && ((int)c != -1) && !isSignOrBrackrts(c))
					return false;
				break;
			}
			case point:
			{
				if (isNumb(c))
					position = FractPart;
				else
					return false;
				break;
			}
			case FractPart:
			{
				if (isNumb(c))
					position = FractPart;
				else if (isExp(c))
					position = exp;
				else if ((c != '\n') && ((int)c != -1) && !isSignOrBrackrts(c))
					return false;
				break;
			}
			case exp:
			{
				if (isNumb(c))
					position = degree;
				else if (isSecondOrderOperation(c))
					position = signAfterExp;
				else
					return false;
				break;
			}
			case signAfterExp:
			{
				if (isNumb(c))
					position = degree;
				else
					return false;
				break;
			}
			case degree:
			{
				if (!(isNumb(c)) && (c != '\n') && ((int)c != -1) &&!isSignOrBrackrts(c))
					return false;
				break;
			}
		}
	}

	return true;
}

int main()
{

    FILE *file;
	file = NULL;
	printf("Enter file adress\n");
	char *fileAdress = new char[maxFileAdressLength];
	while (file == NULL)
	{
	gets(fileAdress);
	file = fopen(fileAdress, "r");
	if (file == NULL)
		printf("File not found!\n");
	}

    if (isCorrect(file))
        printf("String is correct\n");
    else
        printf("String is not correct\n");

    fclose(file);
	gets(fileAdress);
	delete []fileAdress;
}