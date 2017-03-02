// reload.cpp : 定义控制台应用程序的入口点。
//a.成员函数被重载的特征：
//（1）相同的范围（在同一个类中）；
//（2）函数名字相同；
//（3）参数不同；
//（4）virtual 关键字可有可无。
//b.覆盖是指派生类函数覆盖基类函数，特征是：
//（1）不同的范围（分别位于派生类与基类）；
//（2）函数名字相同；
//（3）参数相同；
//（4）基类函数必须有virtual 关键字。
//c.“隐藏”是指派生类的函数屏蔽了与其同名的基类函数，规则如下：
//（1）如果派生类的函数与基类的函数同名，但是参数不同。此时，不论有无virtual关键字，基类的函数将被隐藏（注意别与重载混淆）。
//（2）如果派生类的函数与基类的函数同名，并且参数也相同，但是基类函数没有virtual 关键字。此时，基类的函数被隐藏（注意别与覆盖混淆）
//

#include "stdafx.h"
#include<iostream>
using std::cout;
using std::endl;
class Base
{
public:
	void func1() { cout << "Base func1" << endl; }

private:

};
class Derived :public Base
{
public:
	//函数名相同，参数不相同，会忽略基类里面的同名函数，无法调用无参数的func1()
	void func1(int) { cout << "Derived func1" << endl; }
	//函数名相同，参数相同，覆盖了基类里面的func1()，不一定非要有virtual关键字
	void func1() { cout << "Derived func1" << endl; }
};

int main()
{
	Derived d;
	d.func1();
    return 0;
}

