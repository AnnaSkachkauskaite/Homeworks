#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap (int a[100], int i, int n)
{
	int j = 0;
	int k = i;
	for (i ; i < ((k + n) / 2); i++)
	{
		a[i] = a[i] + a[n - 1 - j];
		a[n -1 - j] = a[i] - a[n - 1 - j];
		a[i] = a[i] - a[n - 1 - j];
		++j;
	}
}


int main() 
{ 
	int n = 0;
    printf("Enter n: \n");
    scanf("%d", &n); 
    int m = 0;
    printf("Enter m: \n");
	scanf("%d", &m); 
	int const length = n + m;
	int a[100];
	int i = 0;
	printf("Enter array: \n");
	for (i; i < length; i++)
	{
		scanf("%d", &a[i]);
	}
	i = 0;
	swap(a, i, n);
	swap(a, n, length);
	i = 0;
	swap(a, i, length);

	for (i = 0; i < length; i++)
	{
		printf("%3d", a[i]);
	}
	printf("\n");
	scanf("%d", &n);
}







