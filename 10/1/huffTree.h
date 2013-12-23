#pragma once
#define SIZE 256

const int maxFileAdressLength = 100;

struct Symbol 
{
	char sym;
	float freq;
	long count;
	char code[SIZE];
	Symbol *left;
	Symbol *right;
};

Symbol *huffTree (Symbol *symbs[], int numb);

void makeCodes(Symbol *root);

void printTreeInc (Symbol *root);

void freeTree(Symbol **root);

void makeCode (FILE *fin, char* fileAdress, Symbol arr[SIZE]);

void makeKey (Symbol arr[SIZE], int count);