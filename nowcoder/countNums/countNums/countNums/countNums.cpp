// countNums.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int power_base10(int length)
{
	int res = 1;
	for (int i = 0; i < length; ++i)
		res *= 10;
	return res;
}
int numberOf_X(string &strN, int num, int begin, int length)
{
	if (begin == length || strN[begin]<'0' || strN[begin]>'9')
		return 0;
	int first = strN[begin] - '0';
	if (begin == length - 1 && num > first)
		return 0;
	if (begin == length - 1 && num <= first&&num!=0)
		return 1;
	int num_of_first = 0;
	if (num != 0) {
		if (first > num)
			num_of_first = power_base10(length - begin - 1);
		else if (first == num)
			num_of_first = stoi(strN.substr(begin + 1, length - begin - 1)) + 1;
	}

	int num_of_other = first*(length - begin - 1)*power_base10(length - begin - 2);
	int num_recursive = numberOf_X(strN, num, begin + 1, length);
	return num_of_first + num_of_other + num_recursive;
}

int main()
{
	int n;
	cin >> n;
	string tmp = to_string(n);
	cout << numberOf_X(tmp, 0, 0, tmp.size());
    return 0;
}

