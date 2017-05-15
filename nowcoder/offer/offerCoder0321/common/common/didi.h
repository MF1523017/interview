#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include<algorithm>
#include<fstream>
#include<numeric>
#include <math.h>
using namespace std;
#if 0
bool mycmp(const pair<int, int> &lhs, const pair<int, int> &rhs)
{
	if (lhs.first == rhs.first)
		return lhs.second<rhs.second;
	return lhs.first<rhs.first;

}

void  testSolution()
{
	int n;
	cin >> n;
	vector<pair<int, int>> input(n);
	for (int i = 0; i<n; ++i)
		cin >> input[i].first >> input[i].second;
	sort(input.begin(), input.end(), mycmp);
	int res = 0;

	for (int i = 0; i<n - 1; ++i)
	{
		if (input[i].first<input[i + 1].first&&input[i].second<input[i + 1].second)
			res++;

	}
	cout << res << endl;
}

#endif 
#if 0
vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> hash(target + 1, -1);
	vector<int>_result;
	for (int i = 0; i<nums.size(); ++i)
	{
		int reminder = target - nums[i];
		if (hash[reminder] != -1) {
			_result.push_back(hash[reminder]);
			_result.push_back(i);
			break;
		}
		hash[nums[i]] = i;
		hash[reminder] = 0;
	}
	return _result;
}
void testSolution()
{
	vector<int> nums({ 3,2,4 });
	auto res = twoSum(nums, 6);
	for (auto i : res)
		cout << i << " ";
	cout << endl;
	
}
#endif
#if 0
int func(const vector<int> &nums, int sum)
{
	vector<int> res(sum + 1, 0);
	res[0] = 1;
	for (int i = 0; i < sum + 1; ++i)
	{
		for (int j = 0; j < nums.size(); ++j)
		{
			if (res[i] != 0) {
				int index = i + nums[j];
				if (index > sum)
					break;
				else if (index == sum) {
					if (res[i] == res[nums[j]])
						res[index] = res[i] * res[nums[j]];
					else
						res[index] = max(res[i], res[nums[j]]);
				}
				else if (index < sum)
				{
					++res[index];
				}
			}
		}
	}
	return res[sum];
}

void testSolution()
{
	int n, sum;
	ifstream cin("didi.txt");
	cin >> n >> sum;
	vector<int> nums(n, 0);
	for (int i = 0; i < n; ++i)
		cin >> nums[i];
	cout << func(nums, sum) << endl;
}

#endif

#if 0
void testSolution()
{
	ifstream cin("didi.txt");
	int n, m;
	cin >> n >> m;
	vector<int>desk_people(n, 0);
	for (int i=0; i < n; ++i)
		cin >> desk_people[i];
	sort(desk_people.begin(), desk_people.end());
	vector<int>res(n, 0);
	vector<int>b(m, 0);
	vector<int>c(m, 0);
	for (int i = 0; i < m; ++i)
	{
		cin >> b[i] >> c[i];
	}
	vector<bool> visited(m, false);
	for (int i = 0; i < n; ++i)
	{
		int k = 0;
		for (int j = 0; j < m; ++j)
		{
			if (!visited[j] && desk_people[i] >= b[j] && c[j] > res[i])
			{
				res[i] = c[j];
				k = j;
			}
		}
		visited[k] = true;
	}
	
	cout << accumulate(res.begin(),res.end(),0) << endl;
}
#endif
#if 0
void testSolution()
{
	int n;
	cin >> n;
	int res = n / 5;
	for (int i = 0; i <= n; i=i+5)
	{
		if (i>=625&&(i % 625 == 0)) {
			res = res + 3;
			continue;
		}
		if ((i>=25)&&(i % 25 == 0))
		{
			++res;
			continue;
		}
	}
	cout << res << endl;
}
#endif