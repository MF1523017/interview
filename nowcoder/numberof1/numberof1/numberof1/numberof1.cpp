// numberof1.cpp : 定义控制台应用程序的入口点。
//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
//

#include "stdafx.h"

class Solution {
public:
	int  NumberOf1(int n) {
		int res = 0;
		while (n)
		{
			if (n & 1)
				++res;
			n = (n >> 1);
		}
		return res;
	}

};
union
{
	char flag[3];
	short value;
} sampleUnion;
int main()
{
	int a[][3] = { {1},{3,2},{4,3,2} };
	int b = 10;
	int *p = &b;
	int *p1 = new int(12);
	int c[10];
	int *p2 = c;//指向c中的第一个int，也是指向一个int类型
	int(*p3)[3] = a;//int(*p)[3] 才表示一个指向一维数组的指针。 
	printf("sizeof union %d\n", sizeof(sampleUnion));
	Solution s;
	s.NumberOf1(-10);
    return 0;
}

