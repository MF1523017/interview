// sumab.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;
/**
* ����������n��0��λ��
* array: �洢[0-n)������
* len: ���鳤��
* n: ������Ҫ��0��������
*/

void swap_with_zero(int* array, int len, int n) {
	int zIndex = -1;
	int nIndex = -1;
	for (int i = 0; i < len; ++i) {
		if (array[i] == 0) {
			zIndex = i;
		}
		if (array[i] == n) {
			nIndex = i;
		}
	}
	int temp = array[zIndex];
	array[zIndex] = array[nIndex];
	array[nIndex] = temp;
}


class Solution {
public:
	/**
	* ���÷���swap_with_zero����array��������
	*/
	void sort(int* array, int len) {
		for (int i = 0; i < len; ++i)
		{
			if (array[i] == 0)
			{
				array[i] = array[0];
				array[0] = 0;
				break;
			}
		}
		int	i = 1;
			while (i<len)
			{
				if (array[i] == i)
					i++;
				else {
					int tmp = array[i];
					cout << array[i] << endl;
					swap_with_zero(array, len, array[i]);
					swap_with_zero(array, len, array[tmp]);
					swap_with_zero(array, len, array[0]);
				}
			}
		}
	
};

int main(int argc, char **argv)
{
	int array[] = { 3,8,2,4,5,0,1,7,9,6 };
	Solution s;
	s.sort(array, 10);
	for (int i = 0; i < 10; ++i)
		cout << array[i] << " ";
	return 0;
}

