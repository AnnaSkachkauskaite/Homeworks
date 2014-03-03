#pragma once
#include <stdio.h>

int const maxFileAdressLength = 100;

struct TreeNode
{
	char value;
	TreeNode *left;
	TreeNode *right;
};

struct Tree
{
	TreeNode *root;
};

void fileToTree (FILE *file, TreeNode **root);

void printTreeInc (TreeNode *root);

void getValue (TreeNode *root);

int numb(char a);

void freeTree(TreeNode *tree);

