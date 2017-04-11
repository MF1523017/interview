#pragma once

#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;

int func(string &str)
{
	int size = str.size();
	bool size_valid = true;
	if (size < 6 || size>20)
		size_valid = false;
	bool upper_valid = false;
	for (int i = 0; i < size; ++i)
	{
		if (str[i] >= 'A'&&str[i] <= 'Z')
			upper_valid = true;
	}
	int res = 0;
	for (int i = 0; i <=size - 3;)
	{
		char tmp = str[i];
		int count = 0;
		while (tmp == str[i])
		{
			count++;
			
			if (count == 3)
			{
				res++;
				break;
			}i++;
		}
		
		i++;
	}
	if (size_valid&&upper_valid)
		return res;
	if (size_valid&&!upper_valid)
		return res + 1;
	if (size < 6)
		return res + 6 - size;
	if (size > 20)
		return size - 20 > res ? size - 20 : res;
	return res;
}

void testSolution()
{
	
	string input;
	while (cin >> input) {
		cout << func(input) << endl;
	}
	
}