#include <stdio.h>
#include "list.h"

int main ()
{
	/*FILE *file1 = openFile();
	List *polynomal1 = createList();
	makeList(file1, polynomal1);
	printList(polynomal1);
	fclose(file1);
	//int result = value(polynomal1, 1);
	file1 = openFile();
	List *polynomal2 = createList();
	makeList(file1, polynomal2);
	printList(polynomal2);
	fclose(file1);
	List *result = add(polynomal1, polynomal2);
	printList(result);*/
	printf ("Choose option:\n1 - Test for equality\n2 - Find value\n3 - Calculation of the sum\n0 - exit\n");
	int state = 0;
	scanf("%d", &state);
	while (state != 0)
	{
		if (state == 1)
		{
			FILE *file = openFile();
			List *polynomal1 = createList();
			makeList(file, polynomal1);
			fclose(file);
			file = openFile();
			List *polynomal2 = createList();
			makeList(file, polynomal2);
			fclose(file);
			if (equals(polynomal1, polynomal2))
				printf("polynomals are equal\n");
			else
				printf("polynomals are not equal\n");
			deleteList(polynomal1);
			delete polynomal1;
			deleteList(polynomal2);
			delete polynomal2;

		}

		if (state == 2)
		{
			FILE *file = openFile();
			List *polynomal1 = createList();
			makeList(file, polynomal1);
			fclose(file);
			printf("Enter value ");
			int numb = 0;
			scanf("%d", &numb);
			printf("Result = %d\n", value(polynomal1, numb));
			deleteList(polynomal1);
			delete polynomal1;
		}

		if (state == 3)
		{
			FILE *file = openFile();
			List *polynomal1 = createList();
			makeList(file, polynomal1);
			fclose(file);
			file = openFile();
			List *polynomal2 = createList();
			makeList(file, polynomal2);
			fclose(file);
			List *result = add(polynomal1, polynomal2);
			printList(result);
			deleteList(result);
			delete result;
			deleteList(polynomal1);
			delete polynomal1;
			deleteList(polynomal2);
			delete polynomal2;
		}
		scanf("%d", &state);
	}
}