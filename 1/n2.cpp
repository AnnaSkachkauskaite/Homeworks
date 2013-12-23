#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{ 
    int a = 0;
    printf("Enter a: \n");
	scanf("%d", &a); 
	int b = 0;
    printf("Enter b: \n");
	scanf("%d", &b); 
	int i = 0;
	int result = 0;
	bool integral_part = false;
	while (!integral_part)
	{
		if ((a >= (b * i)) && (a < (b * (i + 1))))
		{
			result = i;
			integral_part = true;
		}
		else
		{ 
			++i;
		}
	}
	printf("a / b = %d\n", result);
	scanf("%d", &a); 
}



