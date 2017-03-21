#pragma once
#include<iostream>
#include<vector>
using std::vector;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> >res;
		if (sum<3)return res;
		int left = 1, right = 2;
		int tmpSum = 3;
		while (right<=sum / 2 + 1)
		{
			if (left != right) {
				if (tmpSum < sum)
				{
					right++;
					tmpSum += right;
					continue;
				}
				if (tmpSum > sum)
				{
					tmpSum -= left;
					left++;
					continue;
				}
				if (tmpSum == sum)
				{
					res.push_back(produce_vector(left, right));
					right++;
					tmpSum += right;
					continue;
				}
			}
			else
				break;
		}
		return res;
	}
	vector<int> produce_vector(int left, int right)
	{
		vector<int> res;
		for (int i = left; i <= right; ++i)
			res.push_back(i);
		return res;
	}
};

void testFindContinuousSequence()
{
	Solution s;
	s.FindContinuousSequence(3);
}