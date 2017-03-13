// lessLength.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

void func(int N, int L)
{
	while (L <=100)
	{
		if (N%L == 0 && L % 2 == 0)
			L++;
		else if (N%L == 0 && L%2 == 1)
		{
			int res = N / L;
			for (int i = -L/2; i < L / 2+1; ++i)
			{
				cout << res + i << " ";
			}
			return;
		}
		//L++;
	}
	cout << "NO" << endl;
}
int main()
{
	unsigned int N, L;
	cin >> N >> L;
	func(N, L);
    return 0;
}

