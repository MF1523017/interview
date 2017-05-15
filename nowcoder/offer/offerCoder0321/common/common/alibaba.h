#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
using namespace std;

//阿里约会问题
double date(int N) {

	double res = 0;
	double tmp = N;
	for (int i = 0; i<N; ++i)
	{
		res += tmp / (tmp - i);
	}
	return res;
}

void testSolution()
{
	double res;
	int N;
	cin >> N;

	res = date(N);
	printf("%.4f", res);
}
#if 0

bool Find(int n, int k)
{
	if (n <= k)
	{
		return true;
	}
	for (int i = 1; i<=k; ++i)
	{
		if (!Find(n - i, i))
		{
			return true;
		}
	}
	return false;
}
int Find(int n)
{
	for (int i = n / 2; i>0; --i)
	{
		if(!Find(n-i, i))
			return i;
	}
	return -1;
}

void testSolution()
{
	int n = 0;
	cin >> n;
	cout << Find(n) << endl;
}

#endif