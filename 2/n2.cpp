#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long int pow(int numb, int deg)
{
    long int a = numb, result = 1;
    while (deg > 0)
    {
        if ((deg & 1) != 0)
            result *= a;
        a *= a;
        deg >>= 1;
    }
    return result;
}

void main ()
{
	printf("Enter number ");
	int a;
	scanf("%d", &a);
	printf("Enter degree ");
	int n;
	scanf("%d", &n);
	printf("a ^ n = %d\n", pow(a,n));
	scanf("%d", &n);
}


