#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.size() != 5)
			return false;
		sort(numbers.begin(), numbers.end());
		int zero_count = 0;
		int space_count = 0;
		for (int i = 0; i<numbers.size(); ++i) {
			if (0 == numbers[i])
				zero_count++;
		}
		for (int i = zero_count; i<numbers.size() - 1; ++i) {
			int space = numbers[i + 1] - numbers[i] - 1;
			if (-1 == space)
				return false;
			space_count += space;
		}
		return space_count <= zero_count;
	}
};

void testSolution()
{
	vector<int> nums({ 1,0,3,6,4 });
	Solution s;
	std::cout<<s.IsContinuous(nums)<<std::endl;
}