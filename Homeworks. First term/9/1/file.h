#pragma once

const int maxFileAdressLength = 100;
const int maxStrLength = 1000;
const int maxLinesNumber = 1000;

FILE *open ();

int fileToStringArray (FILE *file1, String *strFile1[maxLinesNumber]);