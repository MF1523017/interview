// superPq.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(unsigned long long num)
{
	for (unsigned long long i = 2; i < sqrt(num)+1; ++i)
	{
		if (num%i == 0)
			return false;
	}
	return true;
}
int producePrime(unsigned long long num)
{
	num++;
	while (true)
	{
		if (isPrime(num))
			break;
		else
			num++;
	}
	return num;
}
int computeq(unsigned long long p, unsigned long long num)
{
	int q = 0;
	while (num!=1)
	{
		if (num%p == 0)
			q++;
		else
			return 0;
		num /= p;
	}
	return q;
}
void superPQ(unsigned long long num)
{
	unsigned long long p = 2;
	while (p<sqrt(num) + 1)
	{
		unsigned long long q = computeq(p, num);
		if(q==0)
			p = producePrime(p);
		else
		{
			cout << p << " " << q;
			return;
		}
	}
	cout << "No" << endl;
}

int main()
{
	unsigned long long num;
	cin >> num;
	superPQ(num);
    return 0;
}

