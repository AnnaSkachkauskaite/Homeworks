#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "tree.h"

enum UserCommand
{
	exit,
	add,
	del,
	print,
};

int main ()
{
	printf("Select operation:\n1 - add value to the tree\n2- remove value from the tree\n3 - print tree\n");
	Tree *tree = createTree();
	UserCommand command;
	scanf("%d", &command);
	while (command != exit)
	{
		if (command == add)
		{
			int numb = 0;
			printf("Enter value ");
			scanf("%d", &numb);
			tree->root = addValue(&tree->root, numb);
			printf("Completed!\n");
		}
		if (command == del)
		{
			int numb = 0;
			printf("Enter number ");
			scanf("%d", &numb);
			tree->root = removeNode(tree->root, numb);
			printf("Completed!\n");
		}
		if (command == print)
		{
			printf("Debug view:  ");
			printDebug(tree->root);
			printf("\nAscending view:  ");
			printTreeInc(tree->root);
			printf("\nDescending view:  ");
			printTreeDec(tree->root);
			printf("\n");
		}
		scanf("%d", &command);
	}
	freeTree(tree->root);
	delete(tree);
}
