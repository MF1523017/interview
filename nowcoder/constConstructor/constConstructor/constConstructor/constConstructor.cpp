// constConstructor.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
			 class A
		 {
			 int _a;
		 public:
			 A(int a) : _a(a)
			 {

			 }
			 A(const int a) :_a(a)
			 {
			 }
			 A(const A &a) :_a(a._a)
			 {
			 }
			 friend int f1(A &) {
				 ;
			 }
			 friend int f2(const A &)
			 {
				 ;
			 }
			 friend int f3(A)
			 {
				 ;
			 }
			 friend int f4(const A)
			 {
				 ;
			 }
		 };
int main()
{
	const A &a1 = 0;

    return 0;
}

