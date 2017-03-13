// buySnack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;
bool myCmp(const pair<double, int> &rhs, const pair<double, int> &lhs)
{
	return rhs.second>lhs.second;
}
void compute(vector<pair<double, int> > &data)
{
	sort(data.begin(), data.end(), myCmp);
	int Ans = 0;
	double sumPrice = 0;
	for (int i = 0; i<data.size(); ++i)
	{
		sumPrice = data[i].first;//+ data[i + 1].first + data[i + 2].first);
		for (int j = i + 1; j<data.size(); ++j) {
			sumPrice += data[j].first;
			for (int k = j + 1; k<data.size(); ++k) {
				sumPrice += data[k].first;
				if (static_cast<int>(2*sumPrice) % 10 == 0)
				{
					Ans = data[i].second + data[j].second + data[k].second;
					cout << Ans << endl;
					return;
				}
				else
				{
					sumPrice -= data[k].first;
				}
			}
			sumPrice -=data[j].first;
		}
	}
}
int main(int argc, char *argv[])
{
	vector<vector<int>> a;
	a[0].push_back(1); 
	int Q;
	std::ifstream cin("tmp.txt", std::ifstream::in);
	cin >> Q;
	while (Q)
	{
		int N;
		cin >> N;
		vector<pair<double, int> > data;
		while (N)
		{
			double A;
			int B;
			cin >> A >> B;
			data.push_back(make_pair(A, B));
			N--;
		}
		compute(data);
		Q--;
	}
	return 0;
}



