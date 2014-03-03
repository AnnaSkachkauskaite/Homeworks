#pragma once

const int maxFileAdressLength = 100;
const int maxVertexNumber = 26;

void dfs (int adjMatrix[maxVertexNumber][maxVertexNumber], int startVertex, int isVisited[maxVertexNumber], int numb, int &count);