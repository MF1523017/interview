#pragma once
#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Base
{
public:
	Base(size_t size,int level)
	{
		_graph.resize(2);
		for (int i = 0; i < level; ++i) {
			_graph[0] += " ";
			_graph[1] += " ";
		}
		_graph[0] += "+";
		for (int i = 0; i < 2 * size - 1; ++i)
			_graph[0] += "-";
		_graph[0] += "+";
		_graph[1] += "|";
		for (int i = 0; i < 2 * size - 1; ++i)
		{
			_graph[1] += " ";
		}
		_graph[1] += "|";
		for (int i = 0; i < level; ++i) {
			_graph[0] += " ";
			_graph[1] += " ";
		}
	}
	void change()
	{
		bool begin = false;
		int start = 0;
		int end = 0;
		for (int i = 0; i < _graph[1].size(); ++i)
		{
			if (_graph[1][i] == '|') {
				if (start == 0)
					start = i + 1;
				else
					end = i - 1;
			}
	
		}
		_graph[1][start] = '+';
		_graph[1][end] = '+';

		for (int i = start+1; i < end; ++i)
		{
			_graph[1][i] = '-';
		}
	}
	void print()
	{
		cout << _graph[0] << endl;
		cout << _graph[1] << endl;
	}
	void print_reverse()
	{
		cout << _graph[1] << endl;
		cout << _graph[0] << endl;
	}
	void print_1()
	{
		cout << _graph[1] << endl;
	}
private:
	vector<string> _graph;
};


int g(const string &str)
{
	stack<char> st;
	size_t max_size = 0;
	for (int i = 0; i<str.size(); ++i)
	{

		if ('[' == str[i])
			st.push(str[i]);
		else if (']' == str[i])
		{
			//max_size = max_size > st.size() ? max_size : st.size();
			max_size = std::max(max_size, st.size());
			st.pop();
		}
			
	}
	vector<Base> res;
	int s = 0;
	for (int i = 0; i<str.size(); ++i)
	{
		
		if ('[' == str[i]) {
			Base tmp(max_size - s,s);
			if (s != max_size - 1)
			{
				if(str[i+1]=='[')
				tmp.change();
				
			}
			res.push_back(tmp);
			if (st.empty())
				tmp.print();
			else
				tmp.print_1();
			st.push(str[i]);
			++s;
		}
		else if (']' == str[i])
		{
			--s;
			if (!st.empty() && st.top() == '[') {
				cout << endl;
				if(str[i+1]==']')
					res.back().print_1();
				else
					res.back().print_reverse();
			}
			else if (res.size() == 1)
				res.back().print_reverse();
			else
				res.back().print_1();
			res.pop_back();
			while(!st.empty())st.pop();
		}
	}
	return max_size;
}
void testSolution()
{
	string s;
	cin >> s;
	g(s);
}
