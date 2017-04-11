// qunawang.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include "graph1"
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<string>
#include<map>
#include<unordered_map>
#include<queue>
#include<fstream>
#include<functional>
using namespace std;

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
int leftEdge(vector<int> &array, size_t array_size, int value, int left, int right)
{
	if (left < 0)
		left = 0;
	while (left<=right)
	{
		int mid = (left + right) / 2;
		if (array[mid] >= value)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return right + 1;
}

int rightEdge(vector<int> &array, int array_size, int value, int left, int right)
{
	if (left < 0)
		left = 0;
	while (left<=right)
	{
		int mid = (left + right) / 2;
		if (array[mid] <= value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return left-1;
}

void  find_range(vector<int> &array )
{
	int array_size = array.size();
	int left = 0;
	int right = 0;
	while (right < array_size)
	{
		left=leftEdge(array, array_size, array[right], right, array_size - 1);
		right = rightEdge(array, array_size, array[left], left, array_size - 1);
		cout << array[left] << "(" << right - left +1<< ")" << endl;
		right++;
	}
}

int main()
{
	string input;
	//ifstream cin("test1.txt");
	getline(cin, input);
	auto array = split(input, ',');
	find_range(array);
	return 0;
}

#endif

#if 0
using namespace std;
const int NotAVertex = INT_MIN;
const int Infinity = INT_MAX;
class Graph
{
private:
	const int MAX_NODE = 1024;
	using pair_t_t = pair<int, int>;
	int _num_of_node;
	vector<vector<int>> _matrix_graph;
	vector<vector<pair<int, int>>> _list_graph;
	void _printPath(const vector<int>&paths, int v);
	void _printDist(const vector<int>&dis, int start, int end);
public:
	Graph(int n) :_num_of_node(n) {
		_matrix_graph.resize(_num_of_node, vector<int>(_num_of_node, 0));
		_list_graph.resize(_num_of_node);
	};
	void initGraph(std::istream &is);
	void initGraph(const  vector<string> &dicts);
	void dijkstra(int start, int end);
	int changes(const string &first, const string &last);
};

int Graph::changes(const string &first, const string &last)
{
	int count = 0;
	for (size_t i = 0; i < first.size(); ++i)
	{
		if (first[i] != last[i])
		{
			count++;
		}
	}
	return count;
}
void Graph::initGraph(std::istream &is)
{
	for (int i = 0; i < _num_of_node; ++i)
	{
		for (int j = 0; j < _num_of_node; ++j)
		{
			is >> _matrix_graph[i][j];//如果不可到达即为0；
			if (_matrix_graph[i][j] != 0)
			{
				_list_graph[i].push_back(std::make_pair(j, _matrix_graph[i][j]));
			}
		}
	}
}
void Graph::initGraph(const vector<string> &dicts)
{
	unordered_map<string, int> nodes;

	for (size_t i = 0; i < dicts.size(); ++i)
	{
		nodes[dicts[i]] = i;
	}
	for (auto n : nodes)
	{
		for (size_t i = 0; i < dicts.size(); ++i)
		{
			if (changes(n.first, dicts[i]) == 1)
			{
				_list_graph[n.second].push_back(make_pair(nodes[dicts[i]], 1));
			}
		}
	}
}

void Graph::_printDist(const vector<int>&dis, int start, int end)
{
	std::cout << "the distance between " << start << " and " << end << " is " << dis[end] << std::endl;
}

void Graph::_printPath(const vector<int>&paths, int v)
{
	if (paths[v] != NotAVertex)
	{
		_printPath(paths, paths[v]);
		std::cout << " to ";
	}
	std::cout << v;
}
void Graph::dijkstra(int start, int end)
{
	vector<int> pDist(_num_of_node, Infinity);//记录start到每个节点的距离
	pDist[start] = 0;
	vector<bool> visited(_num_of_node, false);//记录是否已经访问过
	vector<int> paths(_num_of_node, NotAVertex);//记录最短路径的路径
	//priority_queue<pair_t_t, vector<pair_t_t>, std::greater<pair_t_t>> Q;
	queue<pair_t_t> Q;
	Q.push(make_pair(pDist[start], start));//key是距离，value是节点
	while (!Q.empty())
	{
		pair_t_t tmp = Q.front();
		Q.pop();
		int dist = tmp.first;
		int cur_v = tmp.second;
		visited[cur_v] = true;//记录访问过的顶点
		for (size_t i = 0; i < _list_graph[cur_v].size(); ++i)
		{
			int next_v = _list_graph[cur_v][i].first;//与当前节点相邻的节点
			int weight = _list_graph[cur_v][i].second;//与i节点之间的权重
			if (!visited[next_v])
			{
				if (pDist[cur_v] + weight < pDist[next_v])//更新最短
				{
					pDist[next_v] = pDist[cur_v] + weight;
					Q.push(make_pair(pDist[next_v], next_v));
					paths[next_v] = cur_v;
				}
			}
		}
	}
	cout << pDist[end] << endl;
	//_printDist(pDist, start, end);
	//_printPath(paths, end);
}


void  func(const string &first,const string &last,const vector<string> &dicts)
{
	int first_ind = find(dicts.begin(), dicts.end(), first) - dicts.begin();
	int last_ind = find(dicts.begin(), dicts.end(), last) - dicts.begin();
	Graph g(dicts.size());
	g.initGraph(dicts);
	g.dijkstra(first_ind, last_ind);
}
vector<string> split(string &s, char flag = ' ')
{
	vector<string> res;
	replace(s.begin(), s.end(), flag, ' ');
	string n;
	istringstream tmp(s);
	while (!tmp.eof())
	{
		tmp >> n;
		res.push_back(n);
	}
	return res;
}
int main()
{
	ifstream cin("test.txt");
	string first;
	getline(cin, first);
	string last;
	getline(cin, last);
	string tmp;
	getline(cin, tmp);
	vector<string> dicts(split(tmp));
	dicts.push_back(first);
	func(first,last,dicts);
	return 0;
}

#endif
#if 0
class TakeBuses {
public:
	int chooseLine(vector<int> stops, vector<int> period, vector<int> interval, int n, int s) {
		vector<int>res(n,0);
		for (int i = 0; i < n; ++i)
		{
			int wait = s%interval[i] == 0 ? 0 : interval[i] - s%interval[i];
			res[i] = (stops[i] + 1) * 5 + stops[i] * period[i] + s + wait;
		}
		return *min_element(res.begin(), res.end());
	}
};
int main()
{
	//[13, 15, 26, 7, 27, 3, 30], [1, 2, 1, 2, 2, 2, 1], [5, 1, 4, 3, 2, 1, 4], 7, 10
	vector<int>stops({ 13, 15, 26, 7, 27, 3, 30 });
	vector<int>period({ 1, 2, 1, 2, 2, 2, 1 });
	vector<int>interval({ 5, 1, 4, 3, 2, 1, 4 });
	int n = 7;
	int s = 10;
	TakeBuses test;
	cout << test.chooseLine(stops, period, interval, n, s);
}

#endif

#if 0//第三题，kmp算法
class Coder {
public:
	vector<string> findCoder(vector<string> A, int n) {
		map<int, vector<string>> res;
		for (int i = 0; i<n; ++i)
		{
			size_t num_of_coder = coder_num(A[i]);
			if (num_of_coder)
				res[num_of_coder].push_back(A[i]);
		}
		vector<string> _res;
		for (map<int,vector<string>>::reverse_iterator it=res.rbegin();it!=res.rend();++it)
		{
			for (auto s : it->second)
			{
				_res.push_back(s);
			}
		}
		return _res;
		// write code here
	}
	size_t coder_num(const string &s)
	{
		string tmp(s);
		transform(tmp.begin(), tmp.end(), tmp.begin(), tolower);
		size_t count = 0;
		string coder("coder");
		for (int i = 0; i < tmp.size();)
		{
			int j = 0;
			int k = 0;
			while (coder[j] == tmp[i + k])
			{
				++j;
				++k;
				if (j == 5) {
					++count;
					break;
				}
			}
			if (k != 0)
				i += k;
			else
				++i;
		}
		return count;
		
	}
};

int main()
{
	vector<string> strs({ { "I am a coder" }, { "dccoderrlcoderxxpicoderhcoderbiwcoderdcoderrcodermcoderdbvcodertrwvycoderimvcoderuswfccoderczecoderczncoderkfuehcoderocoderiuvccoderfwcodervdiycoderifqjcoder" },{ "dccoderrlcoderxxpicoderhcoderbiwcoderdcoderrcodermcoderdbvcodertrwvycoderimvcoderuswfccoderczecoderczncoderkfuehcoderocoderiuvccoderfwcodervdiycoderifqjcoder" } });
	Coder c;
	auto res = c.findCoder(strs, 3);
    return 0;
}
#endif
//去哪儿网第三题豆豆答案
#if 0
#include <iostream>
#include <istream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

bool DiffOneChar(string word1, string word2)
{
	//should have: word1.size() == word2.size()
	int diffTimes = 0;
	for (int i = 0; i < word1.size(); ++i)
	{
		if (word1[i] != word2[i])
			++diffTimes;
		if (diffTimes > 1)
			return false;
	}
	return diffTimes == 1;
}


struct Graph
{
	short** content;
	int Size;
	Graph(vector<string> words) :Size(words.size())
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
		for (int i = 0; i < Size; ++i)
		{
			for (int j = i + 1; j < Size; ++j)
			{
				if (DiffOneChar(words[i], words[j]))
				{
					content[i][j] = 1;
					content[j][i] = 1;
				}
			}
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
	int Query(int start_ind, int end_ind)
	{
		set<int> bfs, bfs2;
		set<int> searched;
		bfs.insert(start_ind);
		int max_depth = 10000, current_ind;
		for (int depth = 1; depth <= max_depth; ++depth)
		{
			for (auto iter = bfs.begin(); iter != bfs.end(); ++iter)
			{
				current_ind = *iter;
				searched.insert(current_ind);
				for (int i = 0; i < Size; ++i)
				{
					if (searched.find(i) == searched.end())
						if (content[current_ind][i] == 1)
						{
							if (i == end_ind)
								return depth + 1;
							bfs2.insert(i);
						}
				}
			}
			bfs = bfs2;
		}
		return -1;
	}
	void ShowGraph()
	{
		for (int i = 0; i < Size; ++i)
		{
			for (int j = 0; j < Size; ++j)
			{
				cout << content[i][j] << "\t";
			}
			cout << endl;
		}
	}
};
int main()
{
	string start, end, temp;
	cin >> start >> end;
	vector<string> words;
	words.push_back(start);
	while (cin >> temp)
		words.push_back(temp);
	Graph g(words);
	int ind1 = find(words.begin(), words.end(), start) - words.begin();
	int ind2 = find(words.begin(), words.end(), end) - words.begin();
	if (ind1 == ind2)
		cout << 1 << endl;
	else
		cout << g.Query(ind1, ind2) << endl;
	return 0;
}
#endif