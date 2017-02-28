// constPointer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
using namespace std;
typedef struct ST {
	long a; int b; char c[2];
} NEW;

void GetMemeory(char* p)
{
	p = (char*)malloc(100);
}
void test()
{
	char *str = NULL;
	GetMemeory(str);
	strcpy(str, "Thunder");
	strcat(str + 2, "Downloader");
	printf(str);
}

int main() {
	char a = '\92';
	test();
	int m, n;
	for (m = 0, n = -1; n = 0; m++, n++)
		n++;
	const int i = 0;
	int *j = (int *)&i;
	*j = 1;
	printf("%d,%d", i, *j);
	system("pause");
	return 0;
}


