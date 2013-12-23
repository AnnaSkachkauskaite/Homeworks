#include <stdio.h>

const int maxStringLength = 100;

enum State
{
	beginning,
	numSign,
	intPart,
	point,
	fractPart,
	exp,
	expSign,
	expPart,
	error
};

int main ()
{
	char *temp = new char[maxStringLength];
	char *str = temp;
	printf("Enter string\n");
	gets(str);
	State state = beginning;
	char buf = 0;
	while ((state != error) && (*str))
	{
		switch (state)
		{
			case beginning:
				buf = str[0];
				str++;
				if (((buf == '-') || (buf == '+')) && (*str))
					state = numSign;
				else if ((buf >= '0') && (buf <= '9'))
					state = intPart;
				else
					state = error;
				break;

			case numSign:
				buf = str[0];
				str++;
				if ((buf >= '0') && (buf <= '9'))
					state = intPart;
				else
					state = error;
				break;

			case intPart:
				buf = str[0];
				str++;
				if ((buf >= '0') && (buf <= '9'))
					state = intPart;
				else if (buf == '.')
					state = point;
				else if ((buf == 'E') && (*str))
					state = exp;
				else
					state = error;
				break;

			case point:
				buf = str[0];
				str++;
				if (((buf >= '0') && (buf <= '9')) && (*str))
					state = fractPart;
				else
					state = error;
				break;

			case fractPart:
				buf = str[0];
				str++;
				if ((buf >= '0') && (buf <= '9'))
					state = fractPart;
				else if ((buf == 'E') && (*str))
					state = exp;
				else
					state = error;
				break;

			case exp:
				buf = str[0];
				str++;
				if ((buf >= '0') && (buf <= '9'))
					state = expPart;
				else if (((buf == '-') || (buf == '+')) && (*str))
					state = expSign;
				else
					state = error;
				break;

			case expSign:
				buf = str[0];
				str++;
				if ((buf >= '0') && (buf <= '9'))
					state = expPart;
				else
					state = error;
				break;

			case expPart:
				buf = str[0];
				str++;
				if ((buf >= '0') && (buf <= '9'))
					state = expPart;
				else
					state = error;
				break;
		}
	}
				
	if (state == error)
		printf("String is not correct\n");
	else
		printf("String is correct\n");		
	gets(str);
	delete []temp;
}