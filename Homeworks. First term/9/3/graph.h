#pragma once

#include "list.h"

const int maxFileAdressLength =100;
const int maxNumb = 50;
const int maxWay = 1000;

void makeAdjMatrix (FILE *file, int arr[maxNumb][maxNumb], int n);

void printMatrix (int arr[maxNumb][maxNumb], int n);

void makeTree (List *list, int arr[maxNumb][maxNumb], int n, int isVisited[maxNumb]);