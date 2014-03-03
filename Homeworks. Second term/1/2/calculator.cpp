int numb(char a)
{
	return a - '0';
}

int calculate(int a, int b, char sighn)
{
	switch(sighn)
	{
		case '*':
			return a * b;
		case '/':
			return a / b;
		case '+':
			return a + b;
		case '-':
			return a - b;
	}
	return 0;

}
int priority(char a)
{
	switch(a)
	{
		case '*':
		case '/':
			return 3;

		case '-':
		case '+':
			return 2;

		case '(':
			return 1;
	}
	return 0;
}

bool isNumb(char a)
{
	return (a >= '0') && (a <= '9');
}

bool isSighn(char a)
{
	return (a == '+') || (a == '-') || (a == '/') || (a == '*');
}
