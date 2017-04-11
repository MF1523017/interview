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
			is >> _matrix_graph[i][j];//������ɵ��ＴΪ0��
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
	vector<int> pDist(_num_of_node, Infinity);//��¼start��ÿ���ڵ�ľ���
	pDist[start] = 0;
	vector<bool> visited(_num_of_node, false);//��¼�Ƿ��Ѿ����ʹ�
	vector<int> paths(_num_of_node, NotAVertex);//��¼���·����·��
	priority_queue<pair_t_t, vector<pair_t_t>, std::greater<pair_t_t>> Q;
	Q.push(make_pair(pDist[start], start));//key�Ǿ��룬value�ǽڵ�
	while (!Q.empty())
	{
		pair_t_t tmp = Q.top();
		Q.pop();
		int dist = tmp.first;
		int cur_v = tmp.second;
		visited[cur_v] = true;//��¼���ʹ��Ķ���
		for (int i = 0; i < _list_graph[cur_v].size(); ++i)
		{
			int next_v = _list_graph[cur_v][i].first;//�뵱ǰ�ڵ����ڵĽڵ�
			int weight = _list_graph[cur_v][i].second;//��i�ڵ�֮���Ȩ��
			if (!visited[next_v])
			{
				if (pDist[cur_v] + weight < pDist[next_v])//�������
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
