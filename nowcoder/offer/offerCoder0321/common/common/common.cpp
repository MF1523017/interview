// common.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"common.h"
//#include"mei_tuan.h"

int Function(unsigned int n) {

	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);

	return n;
}
int main()
{
	std::cout << Function(197) << std::endl;
	
	testSolution();
    return 0;
}

