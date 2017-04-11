#pragma once
class Balls {
public:
	int helper(int n)
	{
		int res = n;
		n = (n >> 1);
		while (n)
		{
			res += 2 * n;
			n = (n >> 1);
		}
		return res;
	}
	int calcDistance(int A, int B, int C, int D) {
		// write code here
		return helper(A) + helper(B) + helper(C) + helper(D);
	}
};

void testSolution()
{
	Balls b;
	b.calcDistance(100, 90, 80, 70);
}