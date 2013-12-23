#include <stdio.h>
#include "huffTree.h"

void addToTree(char symb, char* code, TreeNode **node)
{
	if (*node == nullptr)
	{
		*node = new TreeNode;
		(*node)->left = nullptr;
		(*node)->right = nullptr;
	}
	if (code[0] != '\n')
	{
		char buf = code[0];
		++code;
		if (buf == '0')
			addToTree(symb, code, &(*node)->left);
		if (buf == '1')
			addToTree(symb, code, &(*node)->right);
	}
	else
		(*node)->symb = symb;
}

void printTreeInc (TreeNode *root)
{
	if(root->left != nullptr)
		printTreeInc(root->left);
	if (root->symb > 0)
		printf("%c  ", root->symb);
	if(root->right != nullptr)
		printTreeInc(root->right);
}

bool isLeaf (TreeNode *node)
{
	return (node->left == nullptr) && (node->right == nullptr);
}

void decode (FILE *file, Tree *tree)
{
	TreeNode *tmp = tree->root;
	FILE *fout;
	fout = fopen("text.txt", "w");
	char buf = fgetc(file);
	while (buf != EOF)
	{
		if (buf == '0')
			tmp = tmp->left;
		if (buf == '1')
			tmp = tmp->right;
		if (isLeaf(tmp))
		{
			fprintf(fout, "%c", tmp->symb);
			tmp = tree->root;
		}
		buf = fgetc(file);
	}
	fclose(fout);
}

void freeTree(TreeNode *tree)
{
	if (tree == nullptr) 
		return;
	if (tree->left)   
		freeTree(tree->left); 
    if (tree->right)  
		freeTree(tree->right); 
    delete tree;
}