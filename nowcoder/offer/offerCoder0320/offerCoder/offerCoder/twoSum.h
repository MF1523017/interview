#pragma once
#include<iostream>
#include<vector>
using std::vector;
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		int mul = INT_MAX;
		int left = 0;
		int right = array.size() - 1;
		vector<int> res(2, 0);
		while (left != right)
		{
			if (array[left] + array[right]>sum)
				right--;
			else if (array[left] + array[right]<sum)
				left++;
			else
			{
				if (array[left] * array[right]<mul)
				{
					mul = array[left] * array[right];
					res[0] = array[left];
					res[1] = array[right];
				}
				left++;
				// right--;
			}

		}
		return res;
	}
};


void testSolution()
{
	vector<int> nums({ 1,2,3,4 });
	Solution s;
	s.FindNumbersWithSum(nums, 5);

}