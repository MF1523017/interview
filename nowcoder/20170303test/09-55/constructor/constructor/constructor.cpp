// constructor.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdio.h"

class A
{
public:
	A()
	{
		printf("1");
	}
	A(A &a)
	{
		printf("2");
	}
	A &operator=(const A &a)
	{
		printf("3");
		return *this;
	}
};
int main()
{
	A a;
	A b = a;
}


