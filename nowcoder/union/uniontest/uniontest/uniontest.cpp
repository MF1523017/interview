// uniontest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

union Test
{
	char a[4];
	short b;
};
		

int main()
{
	Test test;
	test.a[0] = 256;//a[0]=0; 256-256=0;
	test.a[1] = 255;//a[1]=-1;255-256=-1;
	test.a[2] = 254;//a[2]=-2;254-256=-2;
	test.a[3] = 253;//a[3]=-3;253-256=-3;
	printf("%d\n", test.b);
    return 0;
}

