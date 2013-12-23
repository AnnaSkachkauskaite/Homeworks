#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

 int main ()
 {
	 ifstream file;
	 char fileName[100];
	 cout << "Enter file adress" << endl;
	 gets(fileName);
	 file.open(fileName, ios::out);
	 char word[100];
	 while (!file.eof())
	{
		   file >> word;
		   int i = 0;
		   while ((word[i] >= 'a') && (word[i] <= 'z')) 
		   {
			   bool isSymb = true;
			   int j = 0;
			   while ((j < i) && (isSymb))
			   {
				   if (word[i] == word[j])
					   isSymb = false;
				   ++j;
			   }
			   if (isSymb)
				   cout << word[i];
			   ++i;
		   }
		   cout << ' ';
	}
	 file.close();
	 cin >> word[0];
 }