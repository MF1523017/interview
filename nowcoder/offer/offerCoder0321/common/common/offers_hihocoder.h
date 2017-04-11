#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;
#if 0
string snake_to_camel(string &s)
{
	replace(s.begin(), s.end(), '_', ' ');
	string n;
	string res("");
	istringstream tmp(s);
	while (!tmp.eof())
	{
		tmp >> n;
		n[0] = n[0] - 32;
		res+=n;
	}
	res[0] = res[0] + 32;
	return res;
}
string camel_to_snake(string &s)
{
	string res;
	int len = 0;
	int i = 0;
	for (; i < s.size(); ++i)
	{
		if (s[i] >= 'A'&&s[i] <= 'Z')
		{
			string tmp = s.substr(i - len, len);
			tmp[0] = tmp[0] + 32;
			res += tmp;
			res += '_';
			len = 1;
		}
		else
			len++;
	}
	string tmp = s.substr(i - len, len);
	tmp[0] = tmp[0] + 32;
	res += tmp;
	res[0] = res[0] - 32;
	return res;
}
string combine(string &s)
{
	string res;
	auto r = s.find('_');
	if (r != s.npos)
		res = snake_to_camel(s);
	else
		res = camel_to_snake(s);
	return res;
}
void testSolution()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		cout << combine(s) << endl;
	}
}
#endif
#if 0
void print(const vector<vector<int>>&a,int n,int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout<<a[i][j]<<" ";
		}
		cout << endl;
	}
}
int func(const vector<vector<int>>&a,int n,int m,int k)
{
	vector<vector<int>> sums(n, vector<int>(m, 0));
	sums[0][0] = a[0][0];
	for (int i = 1; i < m; ++i)
		sums[0][i] = sums[0][i - 1] + a[0][i];
	for (int i = 1; i < m; ++i)
		sums[i][0] = sums[i-1][0] + a[i][0];

	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < m; ++j)
		{
			sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1]+a[i][j];
		}
	}
	//print(sums, n, m);
	vector<vector<int>> dp(n,vector<int>(m,0));
	int res = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = m - 1; j >= 0; --j)
		{
			if (sums[i][j] <= k)
			{
				res = max(res, (i + 1)*(j + 1));

			}
			else
			{
				for (int r = i; r > 0; --r) {
					for (int s = j; s > 0; --s)
					{
						if (r == i&&s == j)
							continue;
						if (sums[i][j] - sums[r-1][j]-sums[i][s-1]+sums[r-1][s-1] <= k)
						{
							res = max(res, (i - r + 1)*(j - s + 1));
						}
					}
				}
			}
		}
	}
	return res;

}

void testSolution()
{
	ifstream cin("test.txt");
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> a(n, vector<int>(m,0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
		}
	}
	cout << func(a, n, m, k) << endl;
}
#endif


#if 0
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

bool win(const vector<string>&a)
{
	for (int i = 0; i < a.size();i+=3)
	{
		if (a[i].compare(a[i + 1]) == 0)
		{
			if (a[i + 1].compare(a[i + 2]) == 0)
			{
				continue;
			}
		}
		else
		{

		}
	}
}

int func(vector<string> &a, const vector<string>&b)
{
	for (int i = 0; i < b.size(); ++i)
	{
		a.push_back(b[i]);
		sort(a.begin(), a.end());
	}
}
void testSolution()
{
	int n;
	cin >> n;
	string input;
	getline(cin, input);
	auto a = split(input);
	getline(cin, input);
	auto b = split(input);

}

#endif
#if 0
bool check(int i, int j) {
	if (i >= 1 && i <= 8 && j >= 1 && j <= 8)
		return true;
	return false;
}

void testSolution()
{
	int n, r, c;
	cin >> n >> r >> c;

	if (!check(r, c)) {
		cout << 0 << endl;
	}
	vector<vector<int>>dp(9, vector<int>(9, 0));
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++) {
			dp[i][j] = 1;
		}
	for (int t = 1; t <= n; t++) {
		vector<vector<int>>tmp(dp.begin(),dp.end());
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++) {
				int sum = 0;
				if (check(i - 1, j - 2)) {
					sum += tmp[i - 1][j - 2];
					sum = sum % 1000000007;
				}
				if (check(i - 2, j - 1)) {
					sum += tmp[i - 2][j - 1];
					sum = sum % 1000000007;
				}
				if (check(i - 1, j + 2)) {
					sum += tmp[i - 1][j + 2];
					sum = sum % 1000000007;
				}
				if (check(i - 2, j + 1)) {
					sum += tmp[i - 2][j + 1];
					sum = sum % 1000000007;
				}
				if (check(i + 1, j + 2)) {
					sum += tmp[i + 1][j + 2];
					sum = sum % 1000000007;
				}
				if (check(i + 2, j + 1)) {
					sum += tmp[i + 2][j + 1];
					sum = sum % 1000000007;
				}
				if (check(
					i + 1, j - 2)) {
					sum += tmp[i + 1][j - 2];
					sum = sum % 1000000007;
				}
				if (check(i + 2, j - 1)) {
					sum += tmp[i + 2][j - 1];
					sum = sum % 1000000007;
				}dp[i][j] = sum;

			}
	}
	cout << dp[r][c] % 1000000007 << endl;
}
#endif