// ab.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
void func(char *str, int length)
{
	int pa = -1, pb = -1;
	bool isa = false, isb = false;
	for (int i = 0; i < strlen(str); ++i)
	{
		if (str[i] == 'a' && !isa&&!isb) {
			pa = i;
			isa = true;
		}
		else if (str[i] == 'b'&&isa&&!isb)
		{
			for (int j = pa; j < i; ++j)
				str[j] = str[j + 1];
			isa = false;
			i = pa;
		}
		else if (str[i] == 'b' && !isb&&!isa) {
			pb = i;
			isb = true;
		}
		else if (str[i] == 'a'&&isb&&!isa)
		{
			for (int j = i; j > pb; --j)
			{
				str[j] = str[j-1];
			}
			isb = false;
		}
	}
	if (isb){
	int countpb = 0;
	for (int i = pb; i < strlen(str); ++i)
	{
		if (str[i] == 'b')
			countpb++;
	}
	
	int newLen = strlen(str) + countpb;
	int oldLen = strlen(str);
	
	while (oldLen >=pb)
	{
		if (str[oldLen] == 'b')
		{
			str[newLen--] = 'b';
			str[newLen--] = 'b';
			--oldLen;
		}
		else
			str[newLen--] = str[oldLen--];
	}
	}
}

int main()
{
	char *str = new char[20];
	strcpy(str,"abbabsbbbssb");
	func(str, 20);
	cout << str << endl;
	delete []str;
    return 0;
}

