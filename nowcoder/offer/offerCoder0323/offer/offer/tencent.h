#pragma once
#include<iostream>
#include<string>
using namespace std;
int deleteChar(const string &s)
{
	if (s.empty())return 0;
	int left = 0;
	int right = s.size() - 1;
	int res = 0;
	while (left<right)
	{
		if (s[left] == s[right])
		{
			left++;
			right--;
		}
		else {
			right--;
			res++;
		}
	}
	return  res;
}
int testSolution()
{
	string test;
	while (cin >> test)
	{
		cout << deleteChar(test)<<endl;
	}
	return 0;

}
