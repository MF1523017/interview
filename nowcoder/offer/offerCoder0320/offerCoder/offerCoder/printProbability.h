#pragma once
//把n个骰子扔到地上，所有骰子朝上的一面点数之和为S，输入n，打印出所有s的可能的值的概率


//思路1：
//最小值是n,最大值是6n
//所有的可能性是pow(6,n)
//将所有的骰子分为两堆，1和n-1，一个骰子可以有1-6种可能性，再加上n-1个骰子的和
//然后再在n-1中分出两堆，1 和n-2，同上，递归
#include<iostream>
#include<vector>
#include<cmath>
#include<ctime>
using namespace std;

void  compute(vector<int> &res, int sum, int n, int N)
{
	if (n == 0)
	{
		res[sum - N]++;
		return;
	}
	for (int i = 1; i <= 6; ++i) {
		compute(res, sum + i, n - 1, N);
	}
}

void print_probability(int n)
{
	vector<int> res(5 * n + 1, 0);
	compute(res, 0, n, n);
	double p = pow(6, n);
	for (int i = 0; i < res.size(); ++i)
	{
		std::cout << i+n << "'s probability is " << res[i] / p << endl;
	}
}

//思路1随着n值的增大，递归调用将会非常多，运行速度慢，
//思路2:
//在加上一个骰子时，和为n的骰子出现的次数，应该等于，上一次n-1,n-2,n-3,n-4,n-5,n-6出现的次数的和
void print_probability2(int n)
{
	vector<vector<int>> res(2, vector<int>(6 * n + 1, 0));
	int flag = 0;
	for (int i = 1; i <= 6; ++i)
		res[flag][i] = 1;
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j < i; ++j)
			res[1 - flag][i] = 0;//把前面不可能出现的结果清零
		for (int k = i; k <= 6 * i; ++k)
		{
			res[1 - flag][k] = 0;//把旧结果清零
			for (int j = 1; j <= k&&j <= 6; ++j)
				res[1 - flag][k] += res[flag][k - j];
		}
		flag = 1 - flag;
	}
	double p = pow(6, n);
	for (int i = n; i < 6 * n + 1; ++i)
	{
		std::cout << i << "'s probability is " << res[flag][i] / p << endl;
	}
}

void testSolution()
{
	clock_t start = clock();
	print_probability(10);
	clock_t end = clock();
	std::cout << "probability1 time is " << end - start << endl;

	start = clock();
	print_probability2(10);
	end = clock();
	std::cout << "probability2 time is " << end - start << endl;
}