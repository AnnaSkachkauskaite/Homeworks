#include <iostream>
#include "matrixsort.h"
using namespace std;

int main()
{
	cout << "Enter matrix size\n";
	int size = 0;
	cin >> size;
	cout << "Enter matrix\n";
	int **arr = new int*[size];
	for (int i = 0; i < size; ++i)
		arr[i] = new int[size];
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			cin >> arr[i][j];
	int *firsLine = new int[size];
	for (int i = 0; i < size; ++i)
		firsLine[i] = arr[0][i];
	quickSort(firsLine, 0, size -1, arr, size);
	cout << "Sorted matrix\n";
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	for (int i = 0; i < size;++i)
        delete []arr[i];
    delete []arr;
	delete []firsLine;
	cin >> size;
}