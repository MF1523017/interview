#pragma once

#include"common.h"
#include<deque>
#include<set>
using std::sort;
using std::set;
using std::deque;
using std::cin;
using std::cout;
using std::endl;
#if 0
vector<int> split(string &s, char flag = ' ')
{
	vector<int> res;
	replace(s.begin(), s.end(), flag, ' ');
	int n;
	istringstream tmp(s);
	while (!tmp.eof())
	{
		tmp >> n;
		res.push_back(n);
	}
	return res;
}
#endif
////20170325网易 第三题
#if 0
int minTime(vector<int> &nums)
{
	int sum = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		nums[i] = nums[i] / 1024;
		sum += nums[i];
	}
	vector<bool> dp(sum / 2 + 1, false);
	dp[0] = true;
	for (int i = 0; i < nums.size(); ++i)
	{
		int temp = nums[i];
		for (int j = dp.size() - 1; j >= 0; --j)
		{
			if (dp[j] && j + temp < dp.size())
				dp[j + temp] = true;
		}
	}
	int i = dp.size() - 1;
	for (; i > 0; --i)
	{
		if (dp[i])
			break;
	}
	return (sum - i) * 1024;
	//cout << (sum - i) * 1024 << endl;
}


void testSolution()
{
	int n;
	cin >> n;
	string test;
	std::getline(cin, test);
	std::getline(cin, test);
	auto nums = split(test);
	cout << minTime(nums);
}
#endif
//20170325网易 第一题
#if 0
int cal(int nNum1, char op, int nNum2)
{
	if (op == '+')
	{
		return nNum1 + nNum2;
	}

	if (op == '-')
	{
		return nNum1 - nNum2;
	}

	if (op == '*')
	{
		return nNum1 * nNum2;
	}
	return 0;
}


int compute(string &str)
{
	int n1, n2;
	vector<int>nums;
	for (int i = 0; i<str.size(); i = i + 2)
	{
		nums.push_back(str[i] - '0');
	}
	int res = nums[0];
	int j = 0;
	while (j < str.size() / 2) {
		int index = j * 2 + 1;
		res = cal(res, str[index], nums[j + 1]);
		j++;
	}
	//cout << res << endl;
	return 0;
}

void testSolution()
{
	string str;
	cin >> str;
	cout << compute(str) << endl;
}
#endif

//20170325网易 第二题
#if 0
int count(int w, int x, int y, int z)
{
	set<int> res;
	for (int i = w; i <= x; ++i)
	{
		for (int j = y; j <= z; ++j)
		{
			res.insert(i / j);
		}
	}
	return res.size();
}

void testSolution()
{
	int w, x, y, z;
	cin >> w >> x >> y >> z;
	cout << count(w, x, y, z) << endl;
}

#endif


//第一道题目
#if 0
bool is_palindrome(const vector<int>&nums,int left,int right)
{
	int mid=(left+right)/2;
	for (int i = left; i < mid+1; ++i)
	{
		if (nums[i] != nums[right+left- i])
			return false;
	}
	return true;
}

int changes(vector<int>&nums)
{
	int left = 0;
	int right = nums.size() - 1;
	int res = 0;
	while (left < right)
	{
		if (is_palindrome(nums, left, right))
		{
			return res;
		}
		if (nums[left] < nums[right])
		{
			nums[left + 1] += nums[left];
			++left;
			++res;
			if (is_palindrome(nums, left, right))
				return res;
		}
		else if (nums[left] > nums[right])
		{
			nums[right - 1] += nums[right];
			--right;
			++res;
			if (is_palindrome(nums, left, right))
				return res;
		}
		else
		{
			++left;
			--right;
		}
	}
	return res;
}



void testSolution()
{
	int n;
	cin >> n;
	string test;
	std::getline(cin, test);
	std::getline(cin, test);
	auto nums = split(test);
	cout << changes(nums)<< endl;

}
#endif

//第二道题目
#if 0
bool square(int n, int r)
{
	int _r = static_cast<int>(sqrt(n-r*r));
	return _r*_r == n - r*r;
}

int num_of_points(int n)
{
	int res = 0;
	int _r = static_cast<int>(sqrt(n));
	if (_r*_r == n) {
		res += 4;
		--_r;
	}
	while (_r>0)
	{
		if (square(n, _r))
			res += 4;
		--_r;
	}
	return res;
}

void testSolution()
{
	int r_sq;
	cin >> r_sq;
	cout << num_of_points(r_sq);
}

#endif
//第三道题目
#if 0
vector<int> diviseur(int n)
{
	vector<int>res;
	for (int i = 2; i < n/2+1; ++i)
	{
		if (n%i == 0)
			res.push_back(i);
	}
	return res;
}

int least_step(int n, int m)
{
	deque<int>dq;
	vector<int>_res(m+1, INT_MAX);
	dq.push_back(n);
	dq.push_back(0);
	int minStep = 0;
	while (!dq.empty())
	{
		int front = dq.front();
		dq.pop_front();
		if (front == 0) {
			++minStep;
			continue;
		}
		auto d = diviseur(front);
		for (auto item : d)
		{
			if (front + item > m)
				continue;
			if (_res[front + item] > minStep) {
				_res[front + item] = minStep;
				dq.push_back(front + item);
			}
		}
		if(dq.back()!=0)
			dq.push_back(0);
	}
	return _res[m];
}
vector<int> diviseur1(int n)
{
	vector<int>res;
	for (int i = 2; i < sqrt(n)+1; ++i)
	{
		if (n%i == 0) {
			res.push_back(i);
			res.push_back(n / i);
		}
	}
	return res;
}

int least_step1(int n,int m)
{
	vector<int>_res(m + 1, -1);
	_res[n] = 0;
	for (int i = n; i <= m; ++i)
	{
		if (_res[i] != -1)
		{
			for (auto d : diviseur1(i))
			{
				if (i + d > m)
					continue;
				if (_res[i + d] == -1)
					_res[i + d] = _res[i] + 1;
				else
					_res[i + d] = _res[i + d] < _res[i] + 1 ? _res[i + d] : _res[i] + 1;
			}
		}
	}
	return _res[m];
	
}
void testSolution()
{
	int n, m;
	cin >> n >> m;
	//n = 4, m = 24;
	cout << least_step1(n, m) << endl;
}
#endif
