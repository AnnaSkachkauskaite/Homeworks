#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;


int main() 
{ 
	string st;
	printf("enter string:\n");
	getline(cin, st);
	int const length = st.size();
	int bal = 0, i = 0;
	bool t = true;
	while ((i < length ) && (t))
	{ 
		switch(st[i])
		{
		case '(' :
		{
			++bal;
			break;
		}
		case ')' :
		{
			--bal;
			if (bal < 0)
			{
				t = false;
			}
		}
		}
		++i;
	}
	if (t) 
	{
		printf("balance observed\n");
	}
	else
	{
		printf("balance is not observed\n");
	}
	scanf("%d", i);
}


