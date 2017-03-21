#pragma once
#include<iostream>
#include<vector>
using std::vector;

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		if (data.size()<2)return;
		int res = doXor(data);
		int oneBit = findOneBit(res);
		std::cout << "first 1 bit is " << oneBit << std::endl;
		vector<int> d1;
		vector<int> d2;
		int flag = (1 << oneBit);

		for (int i = 0; i<data.size(); ++i)
		{
			if ((data[i] & flag) != 0)
				d1.push_back(data[i]);
			else
				d2.push_back(data[i]);
		}
		*num1 = doXor(d1);
		*num2 = doXor(d2);
	}
	int doXor(vector<int> &data)
	{
		int res = data[0];
		for (int i = 1; i<data.size(); ++i)
			res ^= data[i];
		return res;
	}
	int findOneBit(int n)
	{
		int indexBit = 0;
		while ((n & 1) == 0 && indexBit<8 * sizeof(int))
		{
			n >>= 1;
			++indexBit;
		}
		return indexBit;
	}
};

void testFindOnce()
{
	Solution s;
	vector<int> nums({ 2,4,3,6,3,2,5,5 });
	int num1, num2;
	s.FindNumsAppearOnce(nums, &num1, &num2);
	std::cout << num1 << " " << num2 <<std::endl;
}