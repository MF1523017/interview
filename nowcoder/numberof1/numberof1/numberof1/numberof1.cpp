// numberof1.cpp : �������̨Ӧ�ó������ڵ㡣
//����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
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
	int *p2 = c;//ָ��c�еĵ�һ��int��Ҳ��ָ��һ��int����
	int(*p3)[3] = a;//int(*p)[3] �ű�ʾһ��ָ��һά�����ָ�롣 
	printf("sizeof union %d\n", sizeof(sampleUnion));
	Solution s;
	s.NumberOf1(-10);
    return 0;
}

