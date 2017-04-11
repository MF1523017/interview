#pragma once
//给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
//输出需要删除的字符个数。
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;


#if 0

/* 思路解释
* 两个字符串 BDCABA 和 ABCBDAB, 字符串 BCBA 和 BDAB 都是是它们的最长公共子序列
* lcs[i][j] 表示 s1 长度为 i, s2 长度为 j 时的最大公共子串长度
* 现在已知 lcs[i - 1][j] 即 s1 长度为 i - 1, s2 长度为 j 时的最大公共子串长度
* 而且已知 lcs[i][j - 1] 即 s1 长度为 i, s2 长度为 j - 1 时的最大公共子串长度
* 当 s1 与 s2 同时增加一个字符之后, 判断 lcs[i][j] 的最大公共子串长度
* 动态方程, 如果 s1 和 s2 增加的字符是相同的, 则最大公共子串长度可以 + 1, 否则最大公共子串长度为 lcs[i-1][j] 或 lcs[i][j-1]
*/
int func1(string &str)
{
	string rstr(str.rbegin(),str.rend());
	int size = str.size();
	vector<vector<int>> dp(size + 1, vector<int>(size + 1, 0));
	for (int i = 1; i <= size; ++i)
	{
		for (int j = 1; j <= size; ++j)
		{
			if (str[i - 1] == rstr[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return size - dp[size][size];
}
void testSolution()
{
	string input;
	while (cin>>input)
	{
		cout << func1(input) << endl;
	}
}
#endif

//小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
//你能帮帮小Q吗？
//
//
//输入描述 :
//
//输入数据有多组，每组包含一个字符串s，且保证:1 <= s.length <= 1000.
//
//
//
//	输出描述 :
//
//	对于每组数据，输出移位后的字符串。
//
//	输入例子 :
//					   AkleBiCeilD
//
//						   输出例子 :
//					   kleieilABCD

#if 0
void func2(string &str)
{
	int upperSize = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] >= 'A'&&str[i] <= 'Z')
		{
			++upperSize;
		}
		else
		{
			char tmp = str[i];
			for (int j = i ; j > i - upperSize; --j)
			{
				str[j] = str[j - 1];
			}
			str[i - upperSize] = tmp;
		}
	}

}
void testSolution()
{
	string input;
	while (cin >> input)
	{
		func2(input);
		cout <<input <<endl;
	}
}

#endif



//小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，差最小的有多少对呢？差最大呢？
//
//
//输入描述 :
//
//输入包含多组测试数据。
//
//对于每组测试数据：
//
//N - 本组测试数据有n个数
//
//a1, a2...an - 需要计算的数据
//
//保证 :
//
//1 <= N <= 100000, 0 <= ai <= INT_MAX.
//
//
//
//输出描述 :
//
//	对于每组数据，输出两个数，第一个数表示差最小的对数，第二个数表示差最大的对数。
//
//	输入例子 :
//6
//45 12 45 32 5 6
//
//输出例子 :
//	1 2

#if 0
void func3(vector<int> &nums)
{
	int min_res = 0, max_res;
	sort(nums.begin(), nums.end());
	int size = nums.size();
	int min_count = count(nums.begin(), nums.end(), nums[0]);
	int max_count = count(nums.begin(), nums.end(), nums[size - 1]);
	if (size == 1)
	{
		cout << 0 << " " << 0 << endl;
		return;
	}
	if ((min_count == size) && max_count == size)
	{
		int res = size*(size - 1) / 2;
		cout << res << " " << res << endl;
		return;
	}
	max_res = min_count*max_count;

	int min_val = nums[size - 1] - nums[size - 2];
	for (int i = size - 1; i > 0; --i)
	{
		int tmp = nums[i] - nums[i - 1];
		if (tmp<min_val)
			min_val = tmp;

	}
	for (int i = size - 1; i>0;) {
		int tmp = nums[i] - nums[i - 1];
		if (tmp == min_val)
		{
			int count = 1;
			while (nums[i] - nums[i - 1] == 0)
			{
				++count;
				--i;
			}
			min_res += count*(count - 1) / 2;
		}
		--i;
	}
	cout << min_res << " " << max_res << endl;
}

void testSolution()
{
	int n;
	vector<int> input;
	ifstream cin("test.txt");
	while (cin >> n)
	{
		input.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> input[i];
		func3(input);
		input.clear();
	}
}

#endif