// qsort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using std::string;
void qsort(int *array, int len)
{
	int value, start, end;
	if (len <= 1)
		return;
	value = array[0];
	start = 0;
	end = len - 1;
	while (start < end) {
		for (; start < end; --end) {
			if (array[end] < value) {
				array[start++] = array[end]; 
					break;
			}
		 }
		for (; start < end; ++start) {
			if (array[start] > value)
			{			 
				array[end--] = array[start];
				break;
			 }
		 }
	}
	array[start] = value;
	qsort(array, start);
	qsort(array+start+1, len-start-1);
}

int main()
{
	int array[7] = { 4,2,6,5,3,1,8 };
	qsort(array, 7);
#if 0
	int m, n;
	for (m = 0, n = -1; n = 0; m++, n++)//一次也不执行
		n++;
	const char * tmp=" ";
	if (!strcmp(tmp, " "))
		std::cout << 1 << std::endl;

	int a[4] = { 1,2,3,4 };
	int *ptr = (int*)(&a + 1);
	printf("%d", *(ptr - 1));

#endif
		int i;
	for (i = 0; i<3; i++) {
		switch (i) {
		case 0:printf("%d", i);
		case 2:printf("%d", i);
		default:printf("%d", i);
		}
	}
	return 0;
}

