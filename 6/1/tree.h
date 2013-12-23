#pragma once

struct TreeNode
{
	int value;
	TreeNode *left;
	TreeNode *right;
};

struct Tree
{
	TreeNode *root;
};

void addValue (TreeNode **root, int value);

bool isNode (TreeNode *root, int value);

void printTreeInc (TreeNode *root);

void printTreeDec (TreeNode *root);

void removeNode (TreeNode *root, int value);

TreeNode *findNode(TreeNode *root, int value);

void printDebug(TreeNode* node);

void freeTree(TreeNode *tree);