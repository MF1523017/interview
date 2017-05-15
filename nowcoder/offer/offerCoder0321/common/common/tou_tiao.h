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
using namespace std;
#if 0//今日头条第三题
char zero[5][3] = { {'*','*','*' },
					{ '*',' ','*' },
					{ '*',' ','*' } ,
					{ '*',' ','*' } ,
					{ '*','*','*' } };
char one[5][1] = { {'*'},
				{ '*' },
				{ '*' },
				{ '*' },
				{ '*' }};
char two[5][3]= { { '*','*','*' },
				{ ' ',' ','*' },
				{ '*','*','*' } ,
				{ '*',' ',' ' } ,
				{ '*','*','*' } };
char three[5][3] = { { '*','*','*' },
					{ ' ',' ','*' },
					{ '*','*','*' } ,
					{ ' ',' ','*' } ,
					{ '*','*','*' } };
char four[5][3] = { { '*',' ','*' },
					{ '*',' ','*' },
					{ '*','*','*' } ,
					{ ' ',' ','*' } ,
					{ ' ',' ','*' } };
char five[5][3] = { { '*','*','*' },
					{ '*',' ',' ' },
					{ '*','*','*' } ,
					{ ' ',' ','*' } ,
					{ '*','*','*' } };
char six[5][3] = { { '*','*','*' },
					{ '*',' ',' ' },
					{ '*','*','*' } ,
					{ '*',' ','*' } ,
					{ '*','*','*' } };
char seven[5][3] = { { '*','*','*' },
					{ ' ',' ','*' },
					{ ' ',' ','*' } ,
					{ ' ',' ','*' } ,
					{ ' ',' ','*' } };
char eight[5][3] = { { '*','*','*' },
					{ '*',' ','*' },
					{ '*','*','*' } ,
					{ '*',' ','*' } ,
					{ '*','*','*' } };
char nine[5][3] = { { '*','*','*' },
					{ '*',' ','*' },
					{ '*','*','*' } ,
					{ ' ',' ','*' } ,
					{ '*','*','*' } };
char one_space[5][1] = { {' '},
						{ ' ' },
						{ ' ' },
						{ ' ' },
						{ ' ' }, };

char add_[5][3] = { { ' ',' ',' ' },
					{ ' ','*',' ' },
					{ '*','*','*' } ,
					{ ' ','*',' ' } ,
					{ ' ',' ',' ' } };
char minus_[5][3] = { { ' ',' ',' ' },
					{ ' ',' ',' ' },
					{ '*','*','*' } ,
					{ ' ',' ',' ' } ,
					{ ' ',' ',' ' } };
char mul_[5][3] = { { ' ',' ',' ' },
					{ '*',' ','*' },
					{ ' ','*',' ' } ,
					{ '*',' ','*' } ,
					{ ' ',' ',' ' } };
char div_[5][3] = { { ' ',' ',' ' },
					{ ' ',' ','*' },
					{ ' ','*',' ' } ,
					{ '*',' ',' ' } ,
					{ ' ',' ',' ' } };
char equal_[5][4] = { { ' ',' ',' ',' ' },
					{ '*','*','*','*' },
					{ ' ',' ',' ',' ' } ,
					{ '*','*','*','*' } ,
					{ ' ',' ',' ',' ' } };
char point_[5][2] = { {' ',' '},
					{ ' ',' ' },
					{ ' ',' ' },
					{ '*','*' },
					{ '*','*' }, };



void print_3(char p[][3],int i)
{
		for (int j = 0; j < 3; ++j)
		{
			cout << p[i][j];
		}	
}
void print_2(char p[][2],int i)
{
		for (int j = 0; j < 2; ++j)
		{
			cout << p[i][j];
		}
}
void print_4(char p[][4],int i)
{
		for (int j = 0; j < 4; ++j)
		{
			cout << p[i][j];
		}
}
void print_1(char p[][1],int i)
{
		for (int j = 0; j < 1; ++j)
		{
			cout << p[i][j];
		}	
}
string keep_two(string &s)
{
	string res;
	for (int i = 0; i < s.size(); ++i)
	{
		res += s[i];
		if (s[i] == '.')
		{
			res += s[i+1];
			res += s[i+2];
			break;
		}
	}
	return res;
}
string compute(string &s)
{
	istringstream is(s);
	string res;
	string sign;
	int left;
	int right;
	is >> left;
	is >> sign;
	is >> right;
	if (sign.compare("*")==0)
		res = to_string(left*right);
	if (sign.compare("/") == 0)
	{
		if (left%right == 0)
			res = to_string( left / right);
		else {
			res = to_string(round(100 * (static_cast<double>(left) / right)) / 100);
			res = keep_two(res);
		}
	}
	if (sign.compare("+")==0)
		res = to_string(left + right);
	if (sign.compare("-") == 0)
		res = to_string(left - right);
	return res;
}
void print_s(string &s)
{
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < s.size(); ++j)
		{
			switch (s[j])
			{
			case '0':
				print_3(zero,i);
				break;
			case '1':
				print_1(one, i);
				break;
			case '2':
				print_3(two, i);
				break;
			case '3':
				print_3(three, i);
				break;
			case '4':
				print_3(four, i);
				break;
			case '5':
				print_3(five, i);
				break;
			case '6':
				print_3(six, i);
				break;
			case '7':
				print_3(seven, i);
				break;
			case '8':
				print_3(eight, i);
				break;
			case '9':
				print_3(nine, i);
				break;
			case '+':
				print_3(add_, i);
				break;
			case '-':
				print_3(minus_, i);
				break;
			case '*':
				print_3(mul_, i);
				break;
			case '/':
				print_3(div_, i);
				break;
			case '=':
				print_4(equal_, i);
				break;
			case '.':
				print_2(point_, i);
				break;
			case ' ':
				print_1(one_space, i);
				break;
			default:
				break;
			}
			print_1(one_space, i);
		}
		cout << endl;
	}
}
void func(string &s)
{
	string tmp = compute(s);
	s += " = ";
	s += tmp;
	print_s(s);
}
void testSolution()
{
	string input;
	getline(cin, input);
	func(input);
}

#endif
#if 0
void testSolution()
{
	unsigned long long id;
	map<long long, int> record;
	while (1)
	{
		cin >> id;
		if (id == 0)
			break;
		if (record[id] == 1)
			continue;
		record[id] = 1;
	}
	cout << record.size() << endl;
}

#endif
#if 0

vector<int> used(10, 0);
vector<int> value_used(10, 0);
map<char, int> rep({ {'A',0},
{'B',0},
{ 'C',0 },
{ 'D',0 },
{ 'E',0 },
{ 'F',0 },
{ 'G',0 },
{ 'H',0 },
{ 'I',0 },
{ 'J',0 }
});
unsigned long long max_res = 0;

unsigned long long stoi(string &s)//,map<char,int>&rep)
{
	unsigned long long res = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		res = res * 10 + rep[s[i]];
	}
	return res;
}
unsigned long long adder(vector<string> &strs)//,map<char,int>&rep)
{
	unsigned long long sum_res = 0;
	for (int i = 0; i < strs.size(); ++i)
	{
		sum_res += stoi(strs[i]);
	}
	return sum_res;
}
void bfs(vector<string> &strs,unsigned int depth)
{
	if (depth==10)
	{
		max_res = max(max_res, adder(strs));
		return;
	}
	for (int i = 9; i >= 0; --i)
	{
		
		for (char p='A'+depth;p<='J';++p)
		{
			if (!used[i]) {
				rep[p] = i;
				used[i] = 1;
				bfs(strs, depth + 1);
				used[i] = 0;
			}
		}
	}
	
}
void testSolution()
{
	int n;
	ifstream cin("test3.txt");
	cin >> n;
	vector<string> inputs(n);
	for (int i = 0; i < n; ++i)
		cin >> inputs[i];
	bfs(inputs, 0);
	cout << max_res << endl;
}

#endif
#if 0
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
#endif