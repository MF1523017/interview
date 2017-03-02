// baseDerived.cpp : �������̨Ӧ�ó������ڵ㡣
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
	delete this;//�ͷŶ�̬������ڴ棬�������������ٴ��ͷ�
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

