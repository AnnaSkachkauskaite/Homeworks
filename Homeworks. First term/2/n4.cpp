#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;


int nod (int a, int b) 
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return nod (b, a % b);
    }
}


//void swap(int i, int j)
//{
//	i = i + j;
//	j = i - j;
//	i = i - j;
//}

int main ()
{
	printf("enter number ");
	int numb = 0;
	scanf("%d", &numb);
	int num[1000], denom[1000], k = 0;
	for (int i = 2; i <= numb; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			if (nod(i, j) == 1)
			{
				num[k] = j;
				denom[k] = i;
				++k;
			}
		}
	}
	int j = 0;
	for (int i = 0; i < k - 1; ++i)
	{
		for (j = i + 1; j < k; ++j)
		{
			if ((float)num[i]/denom[i] > (float)num[j]/denom[j])
			{
				swap(num[i],num[j]);
				swap(denom[i],denom[j]);
			}
		}
	}
	for (int i = 0; i< k; ++i)
	{
		printf("%d/%d ", num[i], denom[i]);
	}
	scanf("%d", &numb);
}
