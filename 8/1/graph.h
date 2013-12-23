#pragma once

const int maxFileAdressLength = 100;
const int maxVertexNumber = 26;

void dfs (int adjMatrix[maxVertexNumber][maxVertexNumber], int startVertex, char arrLetters[maxVertexNumber], int numb, char letters[maxVertexNumber], int count);