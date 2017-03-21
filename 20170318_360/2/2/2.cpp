// 2.cpp : 定义控制台应用程序的入口点。

#include"stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
void remove_space(const string &s, string &res)
{
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] != ' ')
			res += s[i];
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> elements(n, 0);
	vector<int> dp(n+1, 0);
	dp[0] = 1;
	for (int i = 0; i < n; ++i)
		cin >> elements[i];
	for (int i = 1; i <n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (j!=0&&elements[i] == elements[i - j])
				break;
			dp[i] = dp[i] + dp[i - j - 1];
		}
	}
	cout << dp[n-1] << endl;
	return 0;
}
