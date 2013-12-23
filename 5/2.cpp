#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main ()
{
	union 
	{
	unsigned char bytesLilEnd[8];
	double value;
	};
	printf("Enter number:\n");
	scanf("%lf", &value);
	unsigned char bytes[8];
	for (int i = 0; i < 8; ++i)
	{
		bytes[i] = bytesLilEnd[7 - i];
	}
	int bit[64];
	int count = 0;
	for (int i = 0; i < 8; ++i)
	{
		int mask = 128;
		for (int j = 0; j < 8; j++)
		{
			if (bytes[i] & mask) 
				bit[count] = 1;
			else
				bit[count] = 0;
			++count;
			mask = mask >> 1;
		}
	}
	long exp = 0;
	int expPos = 1;
	for (int i = 11; i > 0; --i)
	{
		exp = exp + bit[i]*expPos;
		expPos = expPos * 2;
	}
	exp = exp - 1023;
	double mantissa = 1;
	long long mantissaPos = 2;
	for (int i = 12; i < 64; ++i)
	{
		mantissa = mantissa + (double) bit[i] / mantissaPos;
		mantissaPos = mantissaPos * 2;
	}
	if (bit[0] == 0)
		printf("+");
	else
		printf("-");
	int precision = 50;
	char mantissaStr[100];
	gcvt(mantissa, precision, mantissaStr);
	printf("%s * 2 ^ %ld\n", mantissaStr, exp);
	scanf("%lf", &value);
}