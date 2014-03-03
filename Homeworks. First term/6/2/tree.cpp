#include "tree.h"
#include <stdio.h>

void fileToTree (FILE *file, TreeNode **root)
{
	*root = new TreeNode;
	(*root)->left = nullptr;
	(*root)->right = nullptr;
	char symb = 0;
	fscanf(file, "%c", &symb);
	(*root)->value = symb;
	fscanf(file, "%c", &symb);
	if (symb == '(')
		fileToTree(file, &(*root)->left);
	else
	{
		(*root)->left = new TreeNode;
		(*root)->left->value = symb;
		(*root)->left->right = nullptr;
		(*root)->left->left = nullptr;
	}
	fscanf(file, "%c", &symb);
	if (symb == '(')
		fileToTree(file, &(*root)->right);
	else
	{
		(*root)->right = new TreeNode;
		(*root)->right->value = symb;
		(*root)->right->left = nullptr;
		(*root)->right->right = nullptr;
	}
	fscanf(file, "%c", &symb);
}

bool isSign (char a)
{
	return ((a == '+') || (a == '-') || (a == '*') || (a == '/'));
}

void printTreeInc (TreeNode *root)
{
	if(root->left != nullptr)
	{
		printf("(");
		printTreeInc(root->left);
	}
	if (isSign(root->value))
		printf("%c", root->value);
	else
		printf("%d", root->value - '0');
	if(root->right != nullptr)
	{
		printTreeInc(root->right);
		printf(")");
	}
}

int numb(char a)
{
	return a - '0';
}

int calculate(int a, int b, char sighn)
{
	switch(sighn)
	{
		case '*':
			return (a * b) + '0';
		case '/':
			return (a / b) + '0';
		case '+':
			return (a + b) + '0';
		case '-':
			return (a - b) + '0';
	}

}

bool isLeaf(TreeNode *root)
{
	return (root->left == nullptr) && (root->right == nullptr);
}

void getValue (TreeNode *root)
{
	if (!isLeaf(root->left))
		getValue(root->left);
	if (!isLeaf(root->right))
		getValue(root->right);
	root->value = calculate(numb(root->left->value),numb(root->right->value), root->value);
	delete root->left;
	delete root->right;
	root->left = nullptr;
	root->right = nullptr;
}

void freeTree(TreeNode *tree)
{
	if (tree->left)   
		freeTree(tree->left); 
    if (tree->right)  
		freeTree(tree->right); 
    delete tree;
}