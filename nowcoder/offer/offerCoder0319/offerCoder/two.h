#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#if 0
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int v) :val(v), next(NULL) {}
};
bool func(ListNode *head)
{
	ListNode *p = head;
	vector<int> res;
	while (p)
	{
		res.push_back(p->val);
		p = p->next;
	}
	int size = res.size();
	for (int i = 0; i < size / 2; ++i)
	{
		if (res[i] != res[size - 1 - i])
			return false;
	}
	return true;
}
#endif




void test()
{

		int n, m;
		cin >> n >> m;
		vector<int> nums(m, 0);
		for (int i = 0; i<n; ++i)
		{
			cin >> nums[i];
		}
		char q, o;
		int c, r;
		cin >> q >> c >> r;
		int sum = 0;
		for (int j = -r; j <= r; ++j)
		{
			sum += nums[c - 1 + j];
		}
		cout << sum << endl;

		for (int i = 0; i < m / 2; ++i)
		{
			char q, o;
			int c, r;
			int s, t;
			cin >> q >> c >> r;
			cin >> o >> s >> t;
			int sum = 0;
			if (o == 'C')
				swap(nums[s-1], nums[t-1]);
			if (o == 'D')
				nums[s-1] -= t;
			if (o == 'A')
				nums[s-1] += t;
			for (int j = -r; j <=r; ++j)
			{
				sum += nums[c-1 + j];
			}
			cout << sum << endl;
		
	}
#if 0
	int r, c;
	cin >> r >> c;
	vector<vector<int>> nums(r,vector<int>(c,0));
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> nums[i][j];
		}
	}
	int steps[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
	int minr, minc;
	int maxr, maxc;
	int minv = nums[0][0], maxv = nums[0][0];
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (nums[i][j]>maxv)
			{
				maxv = nums[i][j];
				maxr = i;
				maxc = j;
			}
			if (nums[i][j] < minv)
			{
				minv = nums[i][j];
				minr = i;
				minc = j;
			}
		}
	}
	int res = 0;
	while ((maxr != minr) && (maxc != minc))
	{
		for (int i = 0; i < 4; ++i)
		{
			int c1 = maxr + steps[i][0];
			int r1 = maxc + steps[i][1];
			if (c1 >= 0 && c1 < c&&r1 >= 0 && r1 < r)
			{
				
			}
		}
#endif

#if 0
		if (maxr == r - 1&&maxc==0)
		{
			if (nums[maxr - 1][0] > nums[maxr][1])
				maxr = maxr - 1;
			else
				maxc = 1;
		}
		if (maxr == r - 1 && maxc == c - 1)
		{
			if (nums[maxr - 1][c - 1] > nums[maxr][c - 2])
				maxr = maxr - 1;
			else
				maxc = c - 2;
		}
		if (maxr == 0 && maxc == 0)
		{
			if (nums[1][0] > nums[0][1])
				maxr = 1;
			else
				maxc = 1;
		}
		if (maxr == 0 && maxc == c - 1)
		{
			if (nums[1][c - 1] > nums[0][c - 2])
				maxr = 1;
			else
				maxc = c - 2;
		}
		else
		{
			if(nums[])
		}
#endif
	


}
