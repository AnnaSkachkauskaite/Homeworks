#pragma once

/// Class which can print matrix using spiral bypass
class Writer
{
public:
	/// Method which print an array
	virtual void printMatrix (int **arr, int size) = 0;
	
	/// Method which makes array using spiral bypass
	int *makeSpiralArray (int **arr, int size);

};
