#pragma once

#include<iostream>
#include<string>
using std::string;

class Solution {
public:
	string LeftRotateString(string str, int n) {
		string leftStr = str.substr(0, n);
		string rightStr = str.substr(n, str.size() - n);
		return rightStr + leftStr;
	}
};

void testSolution()
{
	string str("abcXYZdef");
	Solution s;
	std::cout << s.LeftRotateString(str, 3) << std::endl;;
}