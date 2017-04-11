#pragma once
#if 0
//完美世界第二题
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
vector<int> split(string &s, char flag = ' ')
{
	vector<int> res;
	replace(s.begin(), s.end(), flag, ' ');
	int n;
	istringstream tmp(s);
	while (!tmp.eof())
	{
		tmp >> n;
		if (n)
			res.push_back(n);
	}
	return res;
}
//int partion(vector<int> &nums,int)
int main()
{
	string input;
	getline(cin, input);
	vector<int>nums(split(input));
	sort(nums.begin(), nums.end());
	for (int i = 0; i<nums.size();)
	{
		int tmp = nums[i];
		cout << tmp << " ";
		if (tmp == nums[i]) {
			while (tmp == nums[i])++i;
		}
		else
			++i;
	}
	cout << endl;
	return 0;
}
#endif
//完美世界第一题
#if 0
#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool func(const string &str)
{
	stack<char> st;
	for (int i = 0; i<str.size(); ++i)
	{

		if ('@' == str[i] || '#' == str[i] || '$' == str[i])
			st.push(str[i]);
		else if ('&' == str[i] || '^' == str[i] || '%' == str[i])
		{
			if (st.empty())
				return false;
			char ch = st.top();
			if ('@' == ch&&'&' == str[i])
				st.pop();
			else if ('#' == ch&&'^' == str[i])
				st.pop();
			else  if ('$' == ch&&'%' == str[i])
				st.pop();

		}
	}
	return st.empty();
}


int main()
{
	string input;
	cin >> input;
	cout << func(input) << endl;
	return 0;
}
#endif
