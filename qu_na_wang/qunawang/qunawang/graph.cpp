#include"stdafx.h"
#include"graph1.h"
#include<map>
using std::map;
using std::priority_queue;
using std::make_pair;
const int NotAVertex = INT_MIN;
const int Infinity = INT_MAX;
int Graph::changes(const string &first, const string &last)
{
	int count = 0;
	for (int i = 0; i < first.size(); ++i)
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
void Graph::initGraph(const string &first, const string &last, const vector<string> &dicts)
{
	map<string, int> nodes;
	nodes[first] = 0;
	for (int i = 0; i < dicts.size(); ++i)
	{
		nodes[dicts[i]] = i + 1;
	}
	for (auto n : nodes)
	{
		for (int i = 0; i < dicts.size(); ++i)
		{
			if (changes(n.first, dicts[i])==1)
			{
				_list_graph[i].push_back(std::make_pair(nodes[dicts[i]],1));
			}
		}
	}
}

void Graph::_printDist(const vector<int>&dis,int start,int end)
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
void Graph::dijkstra(int start,int end)
{
	vector<int> pDist(_num_of_node, Infinity);//记录start到每个节点的距离
	pDist[start] = 0;
	vector<bool> visited(_num_of_node, false);//记录是否已经访问过
	vector<int> paths(_num_of_node, NotAVertex);//记录最短路径的路径
	priority_queue<pair_t_t, vector<pair_t_t>, std::greater<pair_t_t>> Q;
	Q.push(make_pair(pDist[start], start));//key是距离，value是节点
	while (!Q.empty())
	{
		pair_t_t tmp = Q.top();
		Q.pop();
		int dist = tmp.first;
		int cur_v = tmp.second;
		visited[cur_v] = true;//记录访问过的顶点
		for (int i = 0; i < _list_graph[cur_v].size(); ++i)
		{
			int next_v = _list_graph[cur_v][i].first;//与当前节点相邻的节点
			int weight = _list_graph[cur_v][i].second;//与i节点之间的权重
			if (!visited[next_v])
			{
				if (pDist[cur_v] + weight < pDist[next_v])//更新最短
				{
					pDist[next_v] = pDist[cur_v] + weight;
					Q.push(make_pair(pDist[next_v],next_v));
					paths[next_v] = cur_v;
				}
			}
		}
	}
	_printDist(pDist, start, end);
	_printPath(paths, end);
}

void testGraph()
{
	Graph g(7);
	ifstream cin("test.txt");
	g.initGraph(cin);
	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			g.dijkstra(i, j);
			cout << endl;
		}
	}
}
