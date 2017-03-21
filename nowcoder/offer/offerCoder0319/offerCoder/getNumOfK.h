#pragma once
#include<iostream>
#include<vector>
using std::vector;
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		if (data.empty())
			return 0;
		int kLeftIndex = getLeftIndex(data, k, 0, data.size() - 1);
		int kRightIndex = getRightIndex(data, k, kLeftIndex, data.size() - 1);
		return kRightIndex - kLeftIndex - 1;
	}
	int getLeftIndex(vector<int> &data, int k, int left, int right)
	{
		int mid = 0;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (data[mid] >= k)
				right = mid - 1;
			else
				left = mid + 1;
		}
		return right;
	}
	int getRightIndex(vector<int> &data, int k, int left, int right)
	{
		int mid = 0;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (data[mid] <= k)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return left;
	}
};

void testGetNumberOfK()
{
	vector<int> nums({ 1,2,3,3,3,3,4,5 });
	Solution s;
	std::cout<<s.GetNumberOfK(nums, 3)<<std::endl;
}
