// PrintMinNumber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool mycmp(const string &lhs, const string &rhs)
{
	string t1 = lhs + rhs;
	string t2 = rhs + lhs;
	return t1 < t2;
}
class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		string res;
		vector<string> strNum;
		for (auto n : numbers)
			strNum.push_back(to_string(n));
		sort(strNum.begin(), strNum.end(), mycmp);
		for (auto s : strNum)
			res += s;
		return res;
	}
};
int main()
{
	vector<int>nums({ 3,32,321 });
	Solution s;
	cout << s.PrintMinNumber(nums)<<endl;
    return 0;
}

