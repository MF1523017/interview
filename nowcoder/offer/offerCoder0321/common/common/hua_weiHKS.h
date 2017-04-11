#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<queue>
using namespace std;
#if 0
//字符串被分解成int数组
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
int reverse(int n)
{
	int res = 0;
	while (n)
	{
		res = res * 10 + n % 10;
		n /= 10;
	}
	return res;
}
int reverseAdd(int a, int b)
{

	a = reverse(a);
	b = reverse(b);
	if ((a > 70000 || a < 1) || (b > 70000 || b < 1))
		return -1;
	return a+b;
}
void testSolution()
{
	string input;
	getline(cin, input);
	vector<int> ab = split(input, ',');
	cout << reverseAdd(ab[0], ab[1]) << endl;
}
#endif

//20170324华为第三题 最短路径
#if 0

int graph[6][6]={
	{0,2,10,5,3,0},
	{0,0,12,0,0,10},
	{0,0,0,0,7,0},
	{2,0,0,0,2,0},
	{4,0,0,1,0,0},
	{3,0,1,0,2,0}
};
void changeGraph(int y)
{
	for (int i = 0; i < 6;++i)
	{
		graph[i][y - 1] = 0;
		graph[y - 1][i] = 0;
	}
}
vector<bool> visited(6, false);
vector<int> paths(6, 1000);
void shortestPath(vector<int> &res,int start)
{
	deque<int> cities;
	cities.push_back(start);
	while (!cities.empty())
	{
		int city = cities.front();
		cities.pop_front();
		visited[city] = true;
		for (int i = 0; i < 6; ++i)
		{
			if (graph[city][i] != 0)
			{
				if (!visited[i]) {
					if(res[city]+graph[city][i]<res[i])
					{ 
						//cout << "city is " << city << " adj city is " << i << endl;
						res[i] = res[city] + graph[city][i];
						paths[i] = city;
						cities.push_back(i);
					}
				}
			}
		}
	}
}
void printPath(int city)
{
	if (paths[city] != 1000)
	{
		printPath(paths[city]);
		cout << ",";
	}
	
	cout << city + 1;
}

void testSolution()
{
	int x, y;
	cin >> x;
	cin >> y;
	changeGraph(y);
	vector<int> res(6, 1000);
	res[4] = 0;
	shortestPath(res, 4);
	cout << res[x - 1] << endl;
	if (res[x - 1] == 0 || res[x - 1] == 1000)
		cout << "[]"<<endl;
	else {
	cout << "[";
	printPath(x - 1);
	cout << "]" << endl;
}
}
#endif