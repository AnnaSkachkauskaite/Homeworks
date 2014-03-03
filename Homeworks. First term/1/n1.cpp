#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
 


int main() 
{ 
    int x = 0;
    printf("Enter x: "); 
    scanf("%d", &x);  
    int sqr = x * x;
	int c = (sqr + 1) * (sqr + x);
    printf("x^4 + x^3 + x^2 + x = %d\n", c); 
	scanf("%d", &x);
	return 0;
}