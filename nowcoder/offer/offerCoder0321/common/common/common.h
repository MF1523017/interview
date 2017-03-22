#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using std::vector;
using std::string;
using std::istringstream;

//字符串被分解成int数组
vector<int> split(string &s, char flag=' ')
{
	vector<int> res;
	if (' ' != flag)
	{
		for (int i = 0; i < s.size(); ++i)
		{
			if (flag == s[i])
				s[i] = ' ';
		}
	}
	int n;
	istringstream tmp(s);
	while (!tmp.eof())
	{
		tmp >> n;
		res.push_back(n);
	}
	return res;
}
void print(vector<int> &nums)
{
	for (int i = 0; i < nums.size(); ++i)
		std::cout << nums[i] << " ";
	std::cout << std::endl;
}

//最大公约数,假设m>=n

unsigned int gcd(unsigned int m, unsigned int n)
{
	unsigned int res;
	while (n > 0)
	{
		res = m%n;
		m = n;
		n = res;
	}
	return m;
}
//判断两个数是否互为素数
bool isPrimeTwoNums(unsigned int m, unsigned int n)
{
	return gcd(m, n) == 1;
}
//判断一个数是否为素数
bool is_prime(unsigned int n)
{
	if (n < 3&&n>0) {
		return true;
	}
	if (n % 2 == 0) {  //先判断是否为偶数，若偶数就直接输出NO并结束程序  
		return false;   //在主程序main()中使用return 0可以直接结束程序  
	}
	//从3开始，到Num的算术平方根结束，步进为2 
	for (int i = 3; i <= sqrt(n); i += 2)
		if (n % i == 0) {
			return false;
		}
	return true;

}

//快速幂计算

long long pow(long long x, unsigned int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	if (n % 2 == 0)
		return pow(x*x, n / 2);
	else
		return pow(x*x, n / 2)*x;
}

//二分查找

int binary_search(const vector<int> &nums, int x)
{
	
	int left = 0, right = nums.size() - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (nums[mid] < x)
			left = mid + 1;
		else if (nums[mid] > x)
			right = mid - 1;
		else
			return mid;
	}
	return INT_MIN;
}
void testSolution()
{
#if 0//split test
	string test;
	std::getline(std::cin,test);
	print(split(test));
#endif
#if 0//gcd test
	std::cout << gcd(15, 15) << std::endl;
#endif
#if 0
	std::cout << isPrimeTwoNums(15, 13) << std::endl;
#endif;
#if 0//test is_prime
	std::cout << "10000 以内的素数为：" << std::endl;
	for (int i = 1; i < 10000; ++i) {
		if(is_prime(i))
			std::cout <<i<<" ";
	}
#endif

#if 0//test pow
	std::cout << pow(3, 102) << std::endl;
#endif

#if 1//test binary_search
	vector<int> nums({ 1,2,3,4,5,6,7 });
	std::cout << binary_search(nums, 5)<<std::endl;

#endif
}