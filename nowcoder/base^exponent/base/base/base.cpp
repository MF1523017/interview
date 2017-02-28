// base.cpp : 定义控制台应用程序的入口点。
//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
//

#include "stdafx.h"
#include<iostream>
class Solution {
public:
	double Power(double base, int exponent) {
		if (exponent == 0)
			return 1;
		long long e = abs(exponent);
		double res = helper(base, e);
		return exponent<0 ? 1 / res : res;
	}
	double helper(double base, long long exponent) {
		if (exponent == 1)
			return base;
		int mid = exponent / 2;
		if (exponent % 2 == 0)
			return helper(base, mid)*helper(base, mid);
		else
			return helper(base, mid)*helper(base, mid + 1);
	}
};

int main()
{
	Solution s;
	std::cout<<s.Power(2.0, -100)<<std::endl;
    return 0;
}

