// firstNotRepeatingChar.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		char char_count[256] = {0};
		for (int i = 0; i<str.size(); ++i)
		{
			char_count[str[i]]++;
		}
		int res_ind;
		for (int i = 0; i<str.size(); ++i)
		{
			if (char_count[str[i]] == 1) {
				res_ind = i;
				break;
			}
		}
		return res_ind;
	}
};

int main()
{
	Solution s;
	cout << s.FirstNotRepeatingChar("google") << endl;
    return 0;
}

