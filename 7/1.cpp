#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const int maxStudNumb = 50;

int main ()
{
	printf("Enter number of students  ");
	int numb = 0;
	scanf("%d", &numb);
	int stud[maxStudNumb];
	for (int i = 0; i < maxStudNumb; ++i)
		stud[i] = -1;
	for (int i = 1; i < 4; ++i)
		stud[i] = 0;
	printf("Enter list of students (with 0 0 in the end)\n");
	int cheatStud = 1;
	int studNumb = 1;
	while (cheatStud > 0)
	{
		scanf("%d %d", &cheatStud, &studNumb);
		stud[cheatStud] = studNumb;
	}
	printf("Cheated student - Version\n");
	for (int i = 4; i < maxStudNumb; ++i)
	{
		if (stud[i] > 0)
		{
			int j = i;
			while (stud[j] != 0)
				j = stud[j];
			printf("%d                 %d\n", i, j);
		}
	}
	printf("Lazy students\n");
	for (int i = 3; i < numb; ++i)
	{
		if (stud[i] == -1)
			printf("%d ", i);
	}
	scanf("%d", &numb);
}
