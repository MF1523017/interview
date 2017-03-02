// 21-29.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using std::cout;
using std::endl;

class A
{
public:
	static int a;
};
class B :public A
{
public:
	int func() { return a; }
};
int A::a = 1;
struct list
{
	list *pre;
	list *next;
	char data[0];

};
int main()
{
	cout << sizeof(list) << endl;
	B b;

	b.func();
	int u = 010;
	cout << u << endl;
    return 0;
}

