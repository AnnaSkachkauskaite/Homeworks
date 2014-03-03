#pragma once
#define SIZE 256

const int maxFileAdressLength = 100;

struct TreeNode
{
	char symb;
	TreeNode *left;
	TreeNode *right;
};

struct Tree
{
	TreeNode *root;
};


void addToTree(char symb, char* code, TreeNode **node);

void printTreeInc (TreeNode *root);

void decode (FILE *file, Tree *tree);

void freeTree(TreeNode *tree);