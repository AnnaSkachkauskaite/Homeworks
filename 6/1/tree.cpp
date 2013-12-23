#include <stdio.h>
#include "tree.h"

void addValue (TreeNode **root, int value)
{
	if (*root == nullptr)
	{
		*root = new TreeNode;
		(*root)->value = value;
		(*root)->left = nullptr;
		(*root)->right = nullptr;
		return;
	}
	if ((*root)->value == value)
	{
		return;
	}
	if ((*root)->value < value)
	{
		addValue(&(*root)->right, value);
	}
	else 
	{
		addValue(&(*root)->left, value);
	}
}

bool isNode (TreeNode *root, int value)
{
	TreeNode *tmp = root;
	if (tmp == nullptr)
	{
		return false;
	}
	if (tmp->value == value)
	{
		return true;
	}
	if (tmp->value < value)
	{
		isNode(tmp->right, value);
	}
	else 
	{
		isNode(tmp->left, value);
	}
}

void printTreeInc (TreeNode *root)
{
	if(root->left != nullptr)
		printTreeInc(root->left);
	printf("%d  ", root->value);
	if(root->right != nullptr)
		printTreeInc(root->right);
}

void printTreeDec (TreeNode *root)
{
	if(root->right != nullptr)
		printTreeDec(root->right);

	printf("%d  ", root->value);
	if(root->left != nullptr)
		printTreeDec(root->left);
}

bool isLeaf(TreeNode *root)
{
	return (root->left == nullptr) && (root->right == nullptr);
}

TreeNode *findNode(TreeNode *root, int value)
{
	/*if (root->value == value)
		return root;
	if (root->value < value)
		findNode(root->right, value);
	if (root->value > value)
		findNode(root->left, value);*/
	TreeNode *result = nullptr;
	while (result == nullptr)
	{
		if (root->value == value)
			result = root;
		else if (root->value > value)
			root = root->left;
		else
			root = root->right;
	}
	return result;
}

TreeNode *findLeftMax(TreeNode *root)
{
	root = root->left;
	if (root->right == nullptr)
		return root;
	root = root->right;
}

void removeNode (TreeNode *root, int value)
{
	TreeNode * pointer = root;
	TreeNode * parent  = nullptr;
	while (pointer != nullptr && pointer->value != value)
	{
		parent = pointer;
		if (value < pointer->value)
			pointer = pointer->left;
		else
			pointer = pointer->right;
	}
	if (pointer != nullptr)
	{
		TreeNode * removed = nullptr;
		if (isLeaf(pointer))
		{   
			TreeNode * child = nullptr;
			removed = pointer;
			if (pointer->left != nullptr)
				child = pointer->left;
			else if (pointer->right != nullptr)
				child = pointer->right;
			if (parent == nullptr)
				root = child;
			else
			{
				if (parent->left == pointer)
					parent->left = child;
				else
					parent->right = child;
			}
		}
		else 
		{
			TreeNode * mostLeft = pointer->right;
			TreeNode * mostLeftParent = pointer;
			while (mostLeft->left != nullptr)
			{
				mostLeftParent = mostLeft;
				mostLeft = mostLeft->left;
			} 
			pointer->value = mostLeft->value;
			removed = mostLeft;
			if (mostLeftParent->left == mostLeft)
				mostLeftParent->left = nullptr;
			else
				mostLeftParent->right = mostLeft->right;
		}
		delete removed;
	}
}

void printDebug(TreeNode* node)
    {
        if (node == nullptr)
        {
            printf("null");
        }
        else
        {
            printf("(%d ", node->value);
            printDebug(node->left);
            printf(" ");
            printDebug(node->right);
            printf(")");
        }
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