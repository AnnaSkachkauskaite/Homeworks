#include "filewriter.h"
#include <fstream>
using namespace std;

void FileWriter::printMatrix (int **arr, int size)
{
	int *spiralArr = makeSpiralArray(arr, size);
	fstream output("output.txt", ios::out);
	for (int i = size * size - 1; i >= 0; i--)
	{
		output << spiralArr[i] << " ";
	}
	//delete []spiralArr;
	output.close();
}