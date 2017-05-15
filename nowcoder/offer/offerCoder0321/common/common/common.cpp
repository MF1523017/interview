// common.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<set>
#include<map>
//#include"paypal.h"
//#include"offers_hihocoder.h"
//#include"tou_tiao.h"
#include<iomanip>
#include<assert.h>
#include<ctype.h>
//#include"hua_wei.h"
#include"alibaba.h"
//#include"didi.h"
//#include"common.h"
using namespace std;
#if 0 //滴滴二轮 第二题
int lcs(string &a1,string &a2)
{
	int size1 = a1.size();
	int size2 = a2.size();
	vector<vector<int>>dp(size1 + 1, vector<int>(size2 + 1, 0));
	//vector<vector<int>>b(size1 + 1, vector<int>(size2 + 1, -1));
	for (int i = 1; i <= size1; ++i)
	{
		for (int j = 1; j <= size2; ++j)
		{
			if (a1[i - 1] == a2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				//b[i][j] = left_up;
			}
			else
			{
				if (dp[i - 1][j] >= dp[i][j - 1])
				{
					dp[i][j] = dp[i - 1][j];
					//b[i][j] = up;
				}
				else
				{
					dp[i][j] = dp[i][j - 1];
					//b[i][j] = ori::left;
				}
			}
		}
	}
	//print_lcs(b, a1, size1, size2);
	//cout << endl;
	return dp[size1][size2];
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
map<char, string> dict_26;
void build()
{
	for (int i = 0; i < 26; ++i)
	{
		if (i <= 15)
			dict_26[i + 'a'] = to_string(i / 3 + 2);
		else if (i > 15 && i < 19)
			dict_26[i + 'a'] = "7";
		else
			dict_26[i + 'a'] = to_string((i - 1) / 3 + 2);
	}
}

int main()
{
	//ifstream cin("didi.txt");
	string tmp;
	build();
	getline(cin, tmp);
	auto strs = split(tmp);
	getline(cin, tmp);
	vector<string> dicts;

	for (auto s : strs)
	{
		string new_str;
		for (auto c : s) {
			char tmp = tolower(c);
			new_str += dict_26[tmp];
		}
		dicts.push_back(new_str);
	}
	int res = 0;
	int index=0;
	int i = 0;
	for (auto s : dicts)
	{
		int len = lcs(s, tmp);
		//cout << len << " " << s << endl;
		if (len > res) {
			index = i;
			res = len;
		}
		++i;
	}
	cout << strs[index] << endl;
	return 0;
}
#endif


#if 0//百度第二题
struct point
{
	char c;
	int x;
	int y;
	int z;
	point(char c1, int x1, int y1, int z1) :c(c1), x(x1), y(y1), z(z1) {}
};
double distance(const point &p1, const point &p2)
{
	double dis_x = p1.x - p2.x;
	double dis_y = p1.y - p2.y;
	double dis_z = p1.z - p2.z;

	return sqrt(dis_x*dis_x + dis_y*dis_y + dis_z*dis_z);
}
double heran(const point &p1, const point &p2, const point &p3)
{
	double a = distance(p1, p2);
	double b = distance(p1, p3);
	double c = distance(p2, p3);
	if ((a + b <= c) || (a + c <= b) || (b + c <= a))
		return -1;
	double p = (a + b + c) / 2;
	return sqrt(p*(p - a)*(p - b)*(p - c));
}
double get_max(const vector<point>&r_points, const vector<point>&g_points, const vector<point>&b_points)
{
	double max_area = 0;
	if (r_points.size() >= 3)
	{
		for (int i = 0; i < r_points.size(); ++i)
		{
			for (int j = 0; j < r_points.size(); ++j)
			{
				for (int k = 0; k < r_points.size(); ++k)
				{
					if ((i != j) && (i != k) && (j != k))
						max_area = max(max_area, heran(r_points[i], r_points[j], r_points[k]));
				}
			}
		}
	}
	if (g_points.size() >= 3)
	{
		for (int i = 0; i < g_points.size(); ++i)
		{
			for (int j = 0; j < g_points.size(); ++j)
			{
				for (int k = 0; k < g_points.size(); ++k)
				{

					if ((i != j) && (i != k) && (j != k))
						max_area = max(max_area, heran(g_points[i], g_points[j], g_points[k]));
				}
			}
		}
	}
	if (b_points.size() >= 3)
	{
		for (int i = 0; i < b_points.size(); ++i)
		{
			for (int j = 0; j < b_points.size(); ++j)
			{
				for (int k = 0; k < b_points.size(); ++k)
				{
					if ((i != j) && (i != k) && (j != k))
						max_area = max(max_area, heran(b_points[i], b_points[j], b_points[k]));
				}
			}
		}
	}
	if ((!r_points.empty()) && (!g_points.empty()) && (b_points.empty()))
	{
		for (int i = 0; i < r_points.size(); ++i)
		{
			for (int j = 0; j < g_points.size(); ++j)
			{
				for (int k = 0; k < b_points.size(); ++k)
				{
					max_area = max(max_area, heran(r_points[i], g_points[j], b_points[k]));
				}
			}
		}
	}
	return max_area;
}

int main()
{
	int n;
	cin >> n;
	vector<point> r_points;
	vector<point> g_points;
	vector<point> b_points;
	for (int i = 0; i < n; ++i)
	{
		char c;
		int x, y, z;
		cin >> c >> x >> y >> z;
		if (c == 'R')
		{
			r_points.push_back(point(c, x, y, z));
		}
		else if (c == 'G')
		{
			g_points.push_back(point(c, x, y, z));
		}
		else
			b_points.push_back(point(c, x, y, z));
	}
	double res = get_max(r_points, g_points, b_points);
	printf("%.5f\n", res);
	return 0;
}
#endif 

#if 0//百度第一题

int main() {

		unsigned int N;
		cin >> N;
		set<unsigned int> price;
		for (int i = 0; i<N; ++i)
		{
			unsigned int tmp;
			cin >> tmp;
			price.insert(tmp);
		}
		auto b = price.begin();
		++b;
		++b;
		cout << *(b) << endl;
		return 0;
	
	//testSolution();
	return 0;

}
#endif


