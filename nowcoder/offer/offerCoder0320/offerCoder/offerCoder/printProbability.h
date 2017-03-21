#pragma once
//��n�������ӵ����ϣ��������ӳ��ϵ�һ�����֮��ΪS������n����ӡ������s�Ŀ��ܵ�ֵ�ĸ���


//˼·1��
//��Сֵ��n,���ֵ��6n
//���еĿ�������pow(6,n)
//�����е����ӷ�Ϊ���ѣ�1��n-1��һ�����ӿ�����1-6�ֿ����ԣ��ټ���n-1�����ӵĺ�
//Ȼ������n-1�зֳ����ѣ�1 ��n-2��ͬ�ϣ��ݹ�
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

//˼·1����nֵ�����󣬵ݹ���ý���ǳ��࣬�����ٶ�����
//˼·2:
//�ڼ���һ������ʱ����Ϊn�����ӳ��ֵĴ�����Ӧ�õ��ڣ���һ��n-1,n-2,n-3,n-4,n-5,n-6���ֵĴ����ĺ�
void print_probability2(int n)
{
	vector<vector<int>> res(2, vector<int>(6 * n + 1, 0));
	int flag = 0;
	for (int i = 1; i <= 6; ++i)
		res[flag][i] = 1;
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j < i; ++j)
			res[1 - flag][i] = 0;//��ǰ�治���ܳ��ֵĽ������
		for (int k = i; k <= 6 * i; ++k)
		{
			res[1 - flag][k] = 0;//�Ѿɽ������
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