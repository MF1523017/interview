// huawei_test1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;
struct IP {
	int first;
	int second;
	int third;
	int forth;
};

bool mycmp(const IP &lhs, const IP &rhs)
{
	if (lhs.first != rhs.first)
		return lhs.first<rhs.first;
	else if (lhs.first == rhs.first&&lhs.second != rhs.second)
		return lhs.second<rhs.second;
	else if (lhs.first == rhs.first&&lhs.second == rhs.second&&lhs.third != rhs.third)
		return lhs.third<rhs.third;
	else if (lhs.first == rhs.first&&lhs.second == rhs.second&&lhs.third == rhs.third&&lhs.forth!=rhs.forth)
		return lhs.forth<rhs.forth;
	return false;
}

void split(string &s, IP &ips)
{
	for (int i = 0; i<s.size(); ++i)
	{
		if (s[i] == '.')
			s[i] = ' ';
	}
	istringstream tmp(s);
	tmp >> ips.first >> ips.second >> ips.third >> ips.forth;
}
bool isVaild(IP &ip)
{
	if (ip.first>255 || ip.second>255 || ip.third>255 || ip.forth>255)
		return false;
	return true;

}

void print(vector<IP> &ip, const char t) {
	if (!ip.empty()) {
		sort(ip.begin(), ip.end(), mycmp);
		cout << t << ':';
		cout << '[';
		int i = 0;
		for (; i<ip.size() - 1; ++i) {
			cout << ip[i].first << '.' << ip[i].second << '.' << ip[i].third << '.' << ip[i].forth << ',';
		}
		cout << ip[i].first << '.' << ip[i].second << '.' << ip[i].third << '.' << ip[i].forth << ']' << endl;

	}
}
int main()
{
	ifstream cin("test.txt");
	vector<IP> ipA;
	vector<IP> ipB;
	vector<IP> ipC;
	vector<IP> ipD;
	vector<IP> ipE;
	string tmp;
	int i = 0;
	while (i<5)
	{
		getline(cin, tmp);
		IP ip;
		split(tmp, ip);
		if (!isVaild(ip))
			continue;
		if (ip.first >= 0 && ip.first <= 127)
			ipA.push_back(ip);
		if (ip.first >= 128 && ip.first <= 191)
			ipB.push_back(ip);
		if (ip.first >= 192 && ip.first <= 223)
			ipC.push_back(ip);
		if (ip.first >= 224 && ip.first <= 239)
			ipD.push_back(ip);
		if (ip.first >= 240 && ip.first <= 247)
			ipE.push_back(ip);
		i++;
	}
	print(ipA, 'A');
	print(ipB, 'B');
	print(ipC, 'C');
	print(ipD, 'D');
	print(ipE, 'E');

	return 0;
}