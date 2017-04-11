#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<string>
#include<fstream>
using namespace std;

/**
��һ��
* ���ֲ���
*
* ��Ŀ������
��дһ�����ֲ����㷨����һ�������ȳ��ֵ�index����������ڼ�������Ҫ����(-1)-��ǰ��Ӧ�ó��ֵ�λ�á�
���� [1,3,6],����5,5Ӧ������index=2��λ�õ������ڼ����С�����(-1)-2 = -3��
����
��һ�ж���һ������x����ʾҪ���ҵ������ڶ��ж���һ��������n����ʾ�����������Ԫ�ظ����������ж���n���������������ɴ����ҵ����顣
���
����x�������г��ֵ�����λ��(������0��ʼ����)����������ڣ�����(-1)-��ǰ��Ӧ�ó��ֵ�λ�á�
��������
3
5
0 1 3 5 6
�������
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
�ڶ���
* ��Ʊ����
*
��Ŀ������
����һ�������д洢��һ����Ʊ��һ�콻�״����ڸ�ʱ���Ĺ�Ʊ�۸�����������
ֻ����һ�������һ�����������ṩһ���㷨�������ͨ��������������Եõ����������
����
�۸����У���,�Ÿ���
���
���Ŀ�������
��������
2,3,2,4
�������
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
* �������·������
*
��Ŀ������
���罵�ٵ���ĸ������˿��̹������Ҫ�����������������ٶ���������������ıʿ�Ƿ׷��ײ߹滮·�ߡ�
��Ϊ����ıʿ֮һ����Ľ�ߵ��㣬����ð�մ�Խ��21���ͽ����������Ѱ������·�ߡ�
�����һ�γ��򣬶�ȡ��������֮��ľ��룬�������ڽӾ����ʾ����������������������·�����ȡ�
����
��һ�У���������������Ϊn
����n���ǹ��Ҽ������ڽӾ����ʾ
���
�������������·������
��������
4
0,1,2,3
1,0,4,5
2,4,0,2
3,5,2,0
�������
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