#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
#if 1
void testSolution()
{
	int n, m;
	cin >> n >> m;
	vector<bool> coins(n, false);
	int left, right;
	for (int i = 0; i < m; ++i)
	{
		cin >> left >> right;
		for (int j = left - 1; j < right; ++j)
		{
			coins[j] = !coins[j];
		}
	
	}
	for (int i = 0; i < coins.size(); ++i)
		cout << coins[i];
	cout << endl;
}
#endif

