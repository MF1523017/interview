// printN.cpp : 定义控制台应用程序的入口点。
//输入数字n,按顺序打印出1到最大的n位十进制数，比如3，则打印1,2,3....999
//

#include "stdafx.h"
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
void printNums(string &nums)
{
	cout << nums << endl;;
	int taken = 0;
	for (int i = nums.size() - 1; i >= 0; --i)
	{
		int sum = nums[i] - '0' + taken;
		if (i == nums.size() - 1)
			sum++;
		if (sum >= 10)
		{
			sum -= 10;
			taken = 1;
			nums[i] = '0' + sum;
		}
		else
		{
			nums[i] = '0' + sum;
			break;
		}
	}
}
bool isOver(string &nums)
{
	for(int i=0;i<nums.size();++i)
	{
		if (nums[i] != '9')
			return false;
	}
	printNums(nums);
	return true;
}
void printN(int n)
{
	string nums(n, '0');
	while (!isOver(nums))
	{
		printNums(nums);
	}
}

int main()
{
	printN(4);
    return 0;
}

