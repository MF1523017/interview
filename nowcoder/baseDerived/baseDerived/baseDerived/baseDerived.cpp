// baseDerived.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
class Base
{
public:
	Base()
	{
		Init();
	}
	virtual void Init()
	{
		printf("Base Init\n");
	}
	void func()
	{
		printf("Base func\n");
	}
};
class Derived : public Base
{
public:
	virtual void Init()
	{
		printf("Derived Init\n");
	}
	void func()
	{
		printf("Derived func\n");
	}
};
class myClass {
public:
	void foo();
};
void myClass::foo() {
	delete this;//释放动态申请的内存，析构函数不会再次释放
}

void func() {
	myClass *a = new myClass();
	a->foo();
}
int main()
{
	Derived d;
	((Base *)&d)->func();
	func();
	return 0;
}

