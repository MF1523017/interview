// microsoft.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include"tree.h"
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<fstream>
#include<map>
using namespace std;

struct TreeNode
{
	int N = 0;
	short P;
	TreeNode* left = nullptr, *right = nullptr;
};

double makeTree(TreeNode *root, short P, short Q, int N, int depth, double val_path)
{
	if (root->P == 0)
		return 0;
	if (root->N == N)
	{
		root->left = nullptr;
		root->right = nullptr;
		delete root;
		return depth * val_path;
	}
	else
	{
		root->left = new TreeNode();
		root->left->N = root->N + 1;
		root->left->P = P / pow(2, root->left->N);
		double result = 0;
		result += makeTree(root->left, P, Q, N, depth + 1, val_path*root->P / 100.0);
		if (root->P<100)
		{
			root->right = new TreeNode();
			root->right->N = root->N;
			root->right->P = min(100 - root->P + Q, 100);
			result += makeTree(root->right, P, Q, N, depth + 1, val_path*(100 - root->P) / 100.0);
		}
		delete root;
		return result;
	}
}
int main()
{
	TreeNode* head;
	short P, Q;
	int N;
	cin >> P >> Q >> N;
	//make up tree
	head = new TreeNode();
	head->P = P;
	head->N = 0;
	cout << makeTree(head, P, Q, N, 0, 1) << endl;
	return 0;
}
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

int find(vector<int> &leaves, int target)
{
	for (int i = 0; i < leaves.size(); ++i)
	{
		if (leaves[i] == target)
			return i;
	}
	return -1;
}
int find(vector<vector<int>> &nodes, int target,int &r,int &c)
{
	for (int i = 0; i < nodes.size(); ++i)
	{
		for(int j=0;j<nodes[i].size();++j)
			if (nodes[i][j] == target)
			{
				r = i;
				c = j;
				return 0;
			}
	}
	return -1;
}
void func(vector<int> &leaves, vector<vector<int>>&nodes, vector<vector<int>>&D)
{
	map<int, int> parents;
	parents[nodes[0][0]] = 0;
	for (int j = 0; j < nodes[1].size(); ++j)
	{
		parents[nodes[1][j]] = nodes[0][0];
	}
	for (int i = 0; i < D.size(); ++i)
	{
		for (int j = 0; j < D[i].size(); ++j)
		{
			int r, c;
			if (D[i][j] == 0)
				continue;
			else if (D[i][j] == 2)
			{
				int res=find(nodes, leaves[i], r, c);
				int p = 0;
				if(c<nodes[r].size()/2)
					p = nodes[r - 1][c / 2];
				else
					p = nodes[r - 1][1+c / 2];
				parents[nodes[r][c]] = p;
				res = find(nodes, leaves[j], r, c);
				if (c < nodes[r].size() / 2)
					p = nodes[r - 1][c / 2];
				else
					p = nodes[r - 1][1 + c / 2];
				parents[nodes[r][c]] = p;
				
			}
		}
	}
	for (auto ps : parents)
		cout << ps.second << " ";

}


int main()
{
	string tmp;
	ifstream cin("test.txt");
	getline(cin, tmp);
	auto nmk = split(tmp);
	getline(cin, tmp);
	auto A = split(tmp);
	vector<vector<int>> nodes;
	for (int i = 0; i < nmk[1]; ++i)
	{
		getline(cin, tmp);
		nodes.push_back(split(tmp));
	}
	getline(cin, tmp);
	vector<int> leaves(split(tmp));
	vector<vector<int>> D;
	for (int i = 0; i < nmk[2]; ++i)
	{
		getline(cin, tmp);
		D.push_back(split(tmp));
	}
	func(leaves, nodes, D);
	return 0;
}
#endif

#if 0
double res = 0;
void fun(double p, double q, int n, int cur, double getPro, double proNow, int routeLen)
{
	if (cur == n)
	{
		res += routeLen*proNow;
		return;
	}
	if (getPro >= 1)
	{
		fun(p, q, n, cur + 1, p / pow(2, cur + 1), proNow, routeLen + 1);
	}
	else {
		fun(p, q, n, cur + 1, p / pow(2, cur + 1), proNow*getPro, routeLen + 1);
		fun(p, q, n, cur, getPro + q, proNow*(1 - getPro), routeLen + 1);
	}
}

int main()
{
	double p, q, n;
	cin >> p >> q >> n;
	fun(p / 100, q / 100, n, 0, p / 100, 1, 0);
	cout << res << endl;
	return 0;
}
#endif

