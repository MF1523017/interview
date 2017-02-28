// base.cpp : �������̨Ӧ�ó������ڵ㡣
//����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
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

