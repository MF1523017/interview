#pragma once

#include <iostream>
#include <istream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include<queue>
#include<fstream>
#include<map>
#include<assert.h>
using namespace std;
#if 0// 视频面试题目
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int v) :val(v), next(nullptr) {}
};

class Stack
{
private:
	size_t _size;
	ListNode *_s;
public:
	Stack() :_size(0), _s(new ListNode(INT_MIN)) {}
	bool empty()const { return _size == 0; }
	size_t size()const { return _size; }
	void push(int v) {
		ListNode *tmp = new ListNode(v);
		tmp->next = _s->next;
		_s->next = tmp;
		++_size;
	}
	int top()
	{
		if (empty())
			return INT_MIN;
		return _s->next->val;
	}
	void pop()
	{
		if (empty())
			return;
		ListNode *tmp = _s->next;
		_s->next = tmp->next;
		delete tmp;
		--_size;
	}
};

void testSolution()
{
	Stack s;
	assert(s.empty() == true);
	assert(s.size() == 0);
	s.push(2);
	assert(s.size() == 1);
	assert(s.top() == 2);
	s.pop();
	assert(s.size() == 0);
}

#endif

#if 0
bool mycmp(char a, char b)
{
	return a>b;
}

int testSolution()
{
	int m, n;
	ifstream cin("test1.txt");
	cin >> m >> n;
	string input;
	getline(cin, input);
	getline(cin, input);
	int a, s, e;
	map<int, int> res1;
	map<int, int> res2;

	for (int i = 0; i<n; ++i) {
		cin >> a >> s >> e;
		if (1 == a)
			res1[s] = e;
		else
			res2[s] = e;
	}
	auto it = res1.begin();
	s = it->first;
	 e = it->second;
	++it;
	for (; it != res1.end(); ++it)
	{
		if (it->first <= e)
			e = it->second;
		else
		{
			sort(input.begin() + s - 1, input.begin() + e);
			s = it->first;
			e = it->second;
		}
	}
	sort(input.begin() + s - 1, input.begin() + e);
	auto it2 = res2.begin();
	s = it2->first;
	e = it2->second;
	++it2;
	for (; it2 != res2.end(); ++it2)
	{
		if (it2->first <= e)
			e = it2->second;
		else
		{
			sort(input.begin() + s - 1, input.begin() + e,mycmp);
			s = it2->first;
			e = it2->second;
		}
	}
	sort(input.begin() + s - 1, input.begin() + e, mycmp);
		//sort(input.begin() + s - 1, input.end() + e - 1);
	cout << input << endl;
	return 0;
}
#endif

#if 1


struct Graph
{
	short** content;
	int Size;
	Graph(vector<vector<int>> edges,int min_v,int max_v) :Size(max_v-min_v+1)
	{
		content = new short*[Size];
		for (int i = 0; i < Size; ++i)
		{
			content[i] = new short[Size];
			for (int j = 0; j < Size; ++j)
			{
				content[i][j] = 0;
			}
		}
		for (int i = 0; i < edges.size(); ++i)
		{
			int r = edges[i][0]-min_v;
			int c = edges[i][1] - min_v;
			content[r][c] = 1;
			content[c][r] = 1;
		}
		//ShowGraph();
	}
	~Graph()
	{
		for (int i = 0; i < Size; ++i)
		{
			delete[] content[i];
		}
		delete[] content;
	}
	int Query(int start_ind, int end_ind,int min_v)
	{
		vector<int>dis(Size, 10000000);
		int s = start_ind - min_v;
		dis[s] = 0;
		vector<bool> visited(Size, false);
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int tmp = q.back();
			q.pop();
			visited[tmp] = true;
			for (int i = 0; i < Size; ++i)
			{
				if (!visited[i]&&content[tmp][i]!=0)
				{
					if (dis[tmp] + 1 < dis[i])
					{
						dis[i] = dis[tmp] + 1;
						q.push(i);
					}
				}
			}
		}
		int res = 0;
		for (int i = 0; i < Size; ++i) {
			if (dis[i] != 10000000)
				res += dis[i];
		}
		return res;
	}
	void ShowGraph()
	{
		for (int i = 0; i < Size; ++i)
		{
			for (int j = 0; j < Size; ++j)
			{
				cout << content[i][j] << " ";
			}
			cout << endl;
		}
	}
};
void testSolution()
{
	int n, m;
	ifstream cin("test.txt");
	cin >> n;
	vector<vector<int>>g(n, vector<int>(2, 0));
	int max_v = 0;
	int min_v = 10000000;
	for (int i = 0; i < n; ++i) {
		cin >> g[i][0] >> g[i][1];
		max_v = max(max_v, g[i][0]);
		max_v = max(max_v, g[i][1]);
		min_v = min(min_v, g[i][0]);
		min_v = min(min_v, g[i][1]);
	}
	cin >> m;
	vector<int> special_nodes(m,0);
	for (int i = 0; i < m; ++i)
		cin >> special_nodes[i];
	Graph _graph(g, min_v, max_v);
	_graph.ShowGraph();
	int res = 0;
	for (int i = 0; i < m; ++i)
		res += _graph.Query(special_nodes[i],g[0][0], min_v);
	cout << res<<endl;
}
#endif