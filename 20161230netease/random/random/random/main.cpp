#include<iostream>
#include<random>
#include<ctime>
#include<vector>
using std::vector;
/*��Ŀ������
���ϴ����һ���˿���
---------------------------
0|1|2|3|4|5|6|7|8|9|10
ÿ�β�����������������һ��Ԫ�ػ���λ��
Ȼ������Ԫ�ؼ�Сһ��������������ķ�Χ��Сһ�����ٴβ����������
���С�������Ԫ�ص����һ��Ԫ�ػ�����
�㷨ʱ�临�Ӷ�O(N)
�㷨�ռ临�Ӷ�O(1)
���ν�����£�
**********************************************************
//42 49 9 38 47 50 23 37 52 15 13 44 0 7 16 41 24 17 19 45 
//1 6 11 31 22 27 46 43 3 2 48 51 14 25 10 20 4 34 29 5 32 
//28 12 36 40 30 21 33 8 35 26 18 53 39
**********************************************************
//9 0 2 42 24 31 4 29 33 37 26 52 3 22 20 28 27 38 39 12 17 
//40 8 14 1 36 10 19 46 44 51 13 32 7 5 45 6 34 41 30 49 23 
//43 16 47 48 50 18 35 25 15 11 21 53
***********************************************************
//44 37 49 5 52 51 1 2 32 43 8 20 48 47 39 9 34 7 19 36 27 6 
//17 12 24 41 50 38 30 35 25 0 23 16 11 45 31 40 26 13 28 22 
//14 4 29 10 42 18 21 53 33 15 3 46
*/

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void  shuffled()
{
	vector<int> veci;
	//����һ���˿��Ʊ����Ϊ0-53���ŵ�vector��
	for (int i = 0; i < 54; ++i)
		veci.push_back(i);
	srand((unsigned)time(NULL));//��������
	for (int i = 0; i < 54; ++i) {
		//�������λ��
		int r = rand() % (54-i);
		//������Ԫ�ؽ���
		swap(veci[r], veci[54-i-1]);
	}
	//��ʾ
	for (auto b : veci)
		std::cout << b << " ";
}

int main(int argc, char **argv)
{
	shuffled();
	return 0;
}