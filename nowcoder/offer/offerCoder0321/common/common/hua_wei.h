#pragma once
#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<map>
#include<sstream>
#include<list>
#include<queue>
using namespace std;
const int inf = 1000;
int graph[6][6] = { {0,2,10,5,3,inf },
					{inf,0,12,inf,inf,10},
					{inf,inf,0,inf,7,inf},
					{2,inf ,inf,0,2,inf},
					{4,inf,inf,1,0,inf},
					{3,inf,1,inf,2,0} };
void change_graph(int y)
{
	if (-1 == y)return;
	for (int i = 0; i < 6; ++i) {
		graph[i][y] = inf;
		graph[y][i] = inf;
	}
}
int visited[6] = { 0 };
vector<int> path(6,inf);
vector<int> dis(6,inf);
void shortest_path(int end)
{
	visited[4] = 1;
	priority_queue<int> q;
	q.push(4);
	dis[4] = 0;
	while (!q.empty())
	{
		int now = q.top();
		q.pop();
		for (int i = 0; i < 6; ++i)
		{
			if (!visited[i])
			{
				if (dis[now] + graph[now][i] < dis[i])
				{
					dis[i] = dis[now] + graph[now][i];
					q.push(i);
					path[i] = now;
				}
			}
		}
	}

}
void printPath(int city)
{
	if (path[city] != 1000)
	{
		printPath(path[city]);
		cout << ",";
	}

	cout << city + 1;
}
void testSolution()
{
	int x, y;
	cin >> x;
	cin >> y;
	change_graph(y-1);
	shortest_path(x - 1);
	cout << dis[x - 1] << endl;
	if (dis[x - 1] == 0 || dis[x - 1] == inf)
		cout << "[]" << endl;
	else {
		cout << "[";
		printPath(x - 1);
		cout << "]" << endl;
	}
}

#if 0
string split(string &s)
{
	string file_name = "";
	string line_no = "";
	string tmp("");
	for (int i = s.size()-1; i >= 0; --i)
	{
		if (s[i] != '\\')
			tmp += s[i];
		else
			break;
	}
	bool flag = false;
	for (int i = tmp.size()-1; i >= 0; --i)
	{
		if (tmp[i] == ' ')
			flag = true;
		else if (flag)
			line_no += tmp[i];
		else
			file_name += tmp[i];
	}
	cout << "file_name " << file_name << " line_no " << line_no << endl;
	return file_name+" "+line_no;
}
void print(const pair<string, int>&rhs)
{
	istringstream is(rhs.first);
	string file_name, line_no;
	is >> file_name >> line_no;
	int size = file_name.size();
	if (size > 16)
		cout << file_name.substr(size - 16, 16) << " " << line_no << " " << rhs.second << endl;
	else
		cout << rhs.first << " " << rhs.second << endl;
}
bool mycmp(const pair<string, int>&lhs, const pair<string, int> &rhs)
{
	return lhs.second > rhs.second;
}
void testSolution()
{
	ifstream cin("test3.txt");
	string line;
	map<string, int> record;
	while (getline(cin, line))
	{
		++record[split(line)];
	}
	vector<pair<string, int>> new_rcd;
	for (auto b : record)
		new_rcd.push_back(b);
	sort(new_rcd.begin(), new_rcd.end(), mycmp);
	int size = min(8, (int)new_rcd.size());
	for (int i = 0; i < size; ++i)
		print(new_rcd[i]);

}

#endif
#if 0//µÚÒ»Ìâ
void testSolution()
{
	int n, m;
	ifstream cin("test3.txt");
	cin >> n >> m;
	vector<int> record(n+1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> record[i];
	}
	char op;
	int a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >> op >> a >> b;
		if ('Q' == op)
		{
			cout << *max_element(record.begin()+min(a,b), record.begin()+max(a,b)+1)<<endl;
		}
		else
		{
			record[a] = b;
		}
	}
}
#endif