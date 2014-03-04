#include "filewriter.h"
#include "consolewriter.h"
#include <iostream>
using namespace std;

const int maxArrSize = 500;


enum userCommand
{ 
	console = 1, 
	file 
};


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
	cout << "Select output mode\n1 -- console\n2 -- file\n";
	int tmp = 0;
	cin >> tmp;
	userCommand command = static_cast<userCommand>(tmp);
	switch (command)
	{

	case console:
		{
			ConsoleWriter *writer = new ConsoleWriter;
			writer->printMatrix(arr, size);
			delete writer;
		}

	case file:
		{
			FileWriter *writer = new FileWriter;
			writer->printMatrix(arr, size);
			cout << "Checkout output.txt file\n";
			delete writer;
		}
	}
	cin >> size;
}