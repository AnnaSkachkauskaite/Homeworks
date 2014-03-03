#pragma once
#include "stringUnit.h"

const int maxFileAdressLength = 100;
const int maxVertexNumber = 50;
const int maxWay = 10000;

void capture (int adjMatrix[maxVertexNumber][maxVertexNumber], int isVisited[maxVertexNumber], int numb, int minToFirst[maxVertexNumber], String *ways[maxVertexNumber]);
