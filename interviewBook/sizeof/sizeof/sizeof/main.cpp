#include"testSizeof.h"
#include<iostream>
using std::cout;
using std::endl;
struct A
{
	short a1;
	short a2;
	short a3;
};

struct B
{
	double b1;
	char b2;
};
int main(int argc, char **argv)
{
	cout << "A size is " << sizeof(B);
	return 0;
}
