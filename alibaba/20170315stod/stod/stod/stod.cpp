// stod.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

double _stod(char *str)
{
	int sign = 0;
	if (str[0] == '+') {
		str++;
		sign = 1;
	}
	if (str[0] == '-')
	{
		str++;
		sign = -1;
	}
	int  res = 0;
	int multiple = 0;
	int dot_index = -1;
	double dot = 0.0;
	double little = 0.0;
	double base = 0.0;
	int start = 0;
	if (str[0] == '0'&&(str[1] == 'x'||str[1]=='X'))
	{
		base = 1 / 16.0;
		little = 1 / 16.0;
		multiple = 16;
		start = 2;
	}
	else {
		little = 0.1;
		multiple = 10;
	}
	int num = 0;
	for (int i = start; i < strlen(str); ++i)
	{
		if (str[i] == '.') {
			dot_index = i;
			continue;
		}
		if (str[i] >= 'A'&&str[i] <= 'F')
			num = str[i] - 'A' + 10;
		else if (str[i] >= 'a'&&str[i] <= 'f')
			num = str[i] - 'a' + 10;
		else if (str[i] >= '0' && str[i] <= '9')
			num = str[i] - '0';
		else
			break;
		if (dot_index == -1) {
			res = res * multiple + num;
		}
		else {
			dot += little*num;
			little *= base;
		}
	}
	return sign*(res+dot);
}

int main()
{
	
	cout << stod("-0x12.13e1") << endl;
	cout << _stod("-0x12.13e1") << endl;
    return 0;
}

