#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<string>
#include<fstream>
using namespace std;

/**
第一题
* 二分查找
*
* 题目描述：
请写一个二分查找算法查找一个数最先出现的index，如果数不在集合中需要返回(-1)-当前数应该出现的位置。
例如 [1,3,6],查找5,5应该是在index=2的位置但并不在集合中。返回(-1)-2 = -3。
输入
第一行读入一个整数x，表示要查找的数；第二行读入一个正整数n，表示待查找数组的元素个数；第三行读入n个递增整数，构成待查找的数组。
输出
整数x在数组中出现的索引位置(索引从0开始计数)；如果不存在，返回(-1)-当前数应该出现的位置。
样例输入
3
5
0 1 3 5 6
样例输出
2
*/
#if 0
int func(const vector<int> &nums,int x)
{
	int left = 0;
	int right = nums.size() - 1;
	int res = -1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] < x)
			left = mid+1;
		else if (nums[mid] > x)
			right = mid-1;
		else {
			res = mid;
			break;
		}
	}
	if (res == -1)
		res = -1 - left;
	return res;
}
void testSolution()
{
	int x;
	cin >> x;
	int n;
	cin >> n;
	vector<int> nums(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	cout << func(nums, x)<<endl;
}
#endif
/**
第二题
* 股票利润
*
题目描述：
假如一个数组中存储了一个股票在一天交易窗口内各时间点的股票价格（正整数）。
只允许一次买入和一次卖出，请提供一个算法，计算出通过卖出和买入可以得到的最大利润
输入
价格序列，用,号隔开
输出
最大的可能利润
样例输入
2,3,2,4
样例输出
2
*
*/

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
int func(const vector<int> &stocks)
{
	int size = stocks.size();
	vector<int>dp(size, 0);
	int min_price = stocks[0];
	for (int i = 1; i < size; ++i)
	{
		dp[i] = max(dp[i - 1], stocks[i] - min_price);
		min_price = min(min_price, stocks[i]);
	}
	return dp[size - 1];
}
void testSolution()
{
	string input;
	getline(cin, input);
	auto stocks = split(input, ',');
	cout << func(stocks) << endl;
}

#endif
/**
* 遍历最短路径长度
*
题目描述：
暴风降临的龙母丹妮莉丝·坦格利安要骑着她的龙以最快的速度游历各国，她的谋士们纷纷献策规划路线。
作为她的谋士之一和仰慕者的你，决定冒险穿越到21世纪借助计算机来寻求最优路线。
请设计一段程序，读取各国两两之间的距离，距离以邻接矩阵表示，并计算出遍历各国的最短路径长度。
输入
第一行：国家数量，假设为n
后续n行是国家间距离的邻接矩阵表示
输出
遍历各国的最短路径长度
样例输入
4
0,1,2,3
1,0,4,5
2,4,0,2
3,5,2,0
样例输出
5

TC: O(n!)
SC: O(n)
*/
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

void func(const vector<vector<int>> &graph,vector<vector<int>> &res,vector<int> &tmpres,int start,int end)
{
	if (start == end) {
		res.push_back(tmpres);
		return;
	}
	for (int i = start; i < end; ++i)
	{
		swap(tmpres[start], tmpres[i]);
		func(graph, res,tmpres, start + 1, end);
		swap(tmpres[start], tmpres[i]);
		//tmpres = tmpres - graph[start][i];
	}
}
int compute(const vector<vector<int>> &graph, const vector<vector<int>> &res)
{
	int _res = 10000;
	for (int i = 0; i < res.size(); ++i)
	{
		int tmp = 0;
		cout << "path is ";
		for (int j = 1; j < 4; ++j)
		{
			tmp += graph[res[i][j - 1]][res[i][j]];
			cout << res[i][j - 1] << " to ";
		}
		cout << res[i][3]<<"  the distance is "<<tmp<<endl;
		_res = min(_res, tmp);
	}
	return _res;
}
void testSolution()
{
	int n;
	ifstream cin("test.txt");
	vector<vector<int>> graph;
	cin >> n;
	string input;
		getline(cin, input);
	
	for (int i=0; i < n; ++i) {
		getline(cin, input);
		graph.push_back(split(input, ','));
	}
	//for(int i=0;i<n;++i)

	vector<int> tmpres;
	for (int i = 0; i < n; ++i)
		tmpres.push_back(i);
	vector<vector<int>> combine;
	func(graph, combine, tmpres, 0, n);
	cout <<compute(graph,combine) << endl;
}