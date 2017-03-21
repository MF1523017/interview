#pragma once

#include<iostream>
#include<vector>
using namespace std;
void compute(vector<int>&res, int offset, int n, int L1, int L2)
{
	if (offset + n <= L1)
	{
		res.push_back(offset);
		res.push_back(offset + n);
		res.push_back(0);
		res.push_back(0);
	}
	else if (offset > L1&&offset + n <= L1 + L2)
	{
		res.push_back(L1);
		res.push_back(L1);
		res.push_back(offset - L1);
		res.push_back(offset - L1 + n);
	}
	else if (offset + n > L1&&offset+n<=L1+L2)
	{
		res.push_back(L1 - offset);
		res.push_back(L1);
		res.push_back(0);
		res.push_back(n-(L1-offset));
	}
	else if (offset + n > L1 + L2)
	{
		if (offset > L1&&offset<L1+L2) {
			res.push_back(L1);
			res.push_back(L1);
			res.push_back(offset-L1);
			res.push_back(L2);
		}
		else if (offset>L1 + L2) {
			res.push_back(L1);
			res.push_back(L1);
			res.push_back(L2);
			res.push_back(L2);
		}
		else if (offset < L1)
		{
			res.push_back(offset);
			res.push_back(L1);
			res.push_back(0);
			res.push_back(L2);
		}
	}
}

void test()
{
	int offset, n, L1, L2;
	vector<vector<int>> res;
	vector<int>tmp;
	while (cin >> offset >> n >> L1 >> L2)
	{
		compute(tmp, offset, n, L1, L2);
		res.push_back(tmp);
		tmp.clear();
	}

	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < 4; ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}