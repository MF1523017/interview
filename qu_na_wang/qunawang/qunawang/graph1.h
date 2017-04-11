#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<functional>
#include<string>
using std::string;
using std::pair;
using std::vector;
using std::cout;
using std::endl;
using std::ifstream;
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
	void initGraph(const string &first, const string &last, const vector<string> &dicts);
	void dijkstra(int start, int end);
	int changes(const string &first, const string &last);
};
void testGraph();
