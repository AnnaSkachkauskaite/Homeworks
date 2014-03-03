#include <stdio.h>

int main() 
{ 
	int sum[28]; // 28 - количество вариантов сумм 3-х цифр
	int i;
	int const kol_sum = 28; 
	for (i = 0; i < kol_sum; ++i)
	{
		sum[i] = 0;
	}
	int const cif = 9;
	int j, k;
	for (i = 0; i <= cif; ++i)
		for (j = 0; j <= cif; ++j)
			for (k = 0; k <= cif; ++k)
			{
				++sum[i + j + k];
			}
	int happy = 0;
	for (i = 0; i < kol_sum; ++i)
	{
		happy = happy + sum[i] * sum[i];
	}
	printf("number of lucky tickets = %d\n", happy);
}