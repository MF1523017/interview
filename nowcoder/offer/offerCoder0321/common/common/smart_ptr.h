#pragma once
#include<iostream>
#include<memory>
using std::unique_ptr;
using std::shared_ptr;
using std::make_shared;
using std::cout;
using std::endl;

shared_ptr<int> f(shared_ptr<int> p)
{
	return p;
}
void test_ptr()
{
	shared_ptr<int> p = make_shared<int>(1);
	f(p);
	cout << p.use_count() << endl;
	{
		shared_ptr<int> p1(p);
		cout << p.use_count() << endl;
		cout << p1.use_count() << endl; 
	}
	cout << p.use_count() << endl;
	unique_ptr<int>p11(new int(1));
}
