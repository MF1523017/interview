// hks.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
map<char, int> tmp;
char flags[4] = { 0x7F,0x1F,0x0F,0x07 };
void build()
{
	for (int i = 0; i<16; ++i)
	{
		if (i<10)
			tmp['0' + i] = i;
		else
			tmp['A' + i - 10] = i;
	}
}
int turn(int strSize, string &in)
{
	int res = ((tmp[in[0]] * 16 + tmp[in[1]])&flags[strSize / 2]) << (strSize / 2 - 1) * 6;
	for (int i = 2; i<strSize; i = i + 2)
	{
		res |= ((tmp[in[i]] * 16 + tmp[in[i + 1]]) & 0x3F) << ((strSize - i) / 2 - 1) * 6;
	}
	return res;
}

string Decode(string in) {
	if (in.empty())return string();
	build();
	string res;
	char flag = toupper(in[0]);
	if ('F' == flag) {
		if (in.size() != 8)
			return false;
		int tmpres = turn(8, in);
		if (tmpres < 65536 || tmpres>1114111)
			return false;
		res = to_string(tmpres);
	}
	else if ('E' == flag) {
		if (in.size() != 6)
			return false;
		int tmpres = turn(6, in);
		if (tmpres < 2048 || tmpres>65535)
			return false;
		res = to_string(tmpres);
	}
	else if ('C' == flag || 'D' == flag) {
		if (in.size() != 4)
			return false;

		int tmpres = turn(4, in);
		if (tmpres < 128 || tmpres>2047)
			return false;
		res = to_string(tmpres);
	}
	else if ('8' == flag || '9' == flag || 'A' == flag || 'B' == flag)
		return false;
	else {
		if (in.size() != 2)
			return false;
	res = to_string(turn(2, in));
}
	return res;
}


int main()
{
	cout << Decode("C280");
    return 0;
}

