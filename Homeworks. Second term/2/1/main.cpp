#include "bubblesort.h"
#include "qsort.h"
#include "insertionsort.h"
#include <iostream>
using namespace std;

const int maxArrSize = 500;

void printArray (int arr[], int size)
{
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	cout << "Enter array size\n";
	int size;
	cin >> size;
	cout << "Enter array\n";
	int arr1[maxArrSize];
	int arr2[maxArrSize];
	int arr3[maxArrSize];
	for (int i = 0; i < size; ++i)
	{
		cin >> arr1[i];
		arr2[i] = arr1[i];
		arr3[i] = arr1[i];
	}

	BubbleSort *bubble = new BubbleSort;
	QSort *qsort = new QSort;
	InsertionSort *insort = new InsertionSort;
	bubble->sort(arr1, size);
	qsort->sort(arr2, size);
	insort->sort(arr3, size);
	cout << "Result of bubble sort\n";
	printArray(arr1, size);
	cout << "Result of quick sort\n";
	printArray(arr2, size);
	cout << "Result of insertion sort\n";
	printArray(arr3, size);
	cin >> size;
}