#pragma once
//����һ���ַ���s������Դ���ɾ��һЩ�ַ���ʹ��ʣ�µĴ���һ�����Ĵ������ɾ������ʹ�û��Ĵ���أ�
//�����Ҫɾ�����ַ�������
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;


#if 0

/* ˼·����
* �����ַ��� BDCABA �� ABCBDAB, �ַ��� BCBA �� BDAB ���������ǵ������������
* lcs[i][j] ��ʾ s1 ����Ϊ i, s2 ����Ϊ j ʱ����󹫹��Ӵ�����
* ������֪ lcs[i - 1][j] �� s1 ����Ϊ i - 1, s2 ����Ϊ j ʱ����󹫹��Ӵ�����
* ������֪ lcs[i][j - 1] �� s1 ����Ϊ i, s2 ����Ϊ j - 1 ʱ����󹫹��Ӵ�����
* �� s1 �� s2 ͬʱ����һ���ַ�֮��, �ж� lcs[i][j] ����󹫹��Ӵ�����
* ��̬����, ��� s1 �� s2 ���ӵ��ַ�����ͬ��, ����󹫹��Ӵ����ȿ��� + 1, ������󹫹��Ӵ�����Ϊ lcs[i-1][j] �� lcs[i][j-1]
*/
int func1(string &str)
{
	string rstr(str.rbegin(),str.rend());
	int size = str.size();
	vector<vector<int>> dp(size + 1, vector<int>(size + 1, 0));
	for (int i = 1; i <= size; ++i)
	{
		for (int j = 1; j <= size; ++j)
		{
			if (str[i - 1] == rstr[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return size - dp[size][size];
}
void testSolution()
{
	string input;
	while (cin>>input)
	{
		cout << func1(input) << endl;
	}
}
#endif

//СQ���������һ�����⣺��һ���ַ����Ĵ�д��ĸ�ŵ��ַ����ĺ��棬�����ַ������λ�ò��䣬�Ҳ����������Ŀռ䡣
//���ܰ��СQ��
//
//
//�������� :
//
//���������ж��飬ÿ�����һ���ַ���s���ұ�֤:1 <= s.length <= 1000.
//
//
//
//	������� :
//
//	����ÿ�����ݣ������λ����ַ�����
//
//	�������� :
//					   AkleBiCeilD
//
//						   ������� :
//					   kleieilABCD

#if 0
void func2(string &str)
{
	int upperSize = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] >= 'A'&&str[i] <= 'Z')
		{
			++upperSize;
		}
		else
		{
			char tmp = str[i];
			for (int j = i ; j > i - upperSize; --j)
			{
				str[j] = str[j - 1];
			}
			str[i - upperSize] = tmp;
		}
	}

}
void testSolution()
{
	string input;
	while (cin >> input)
	{
		func2(input);
		cout <<input <<endl;
	}
}

#endif



//СQ�������ϲ���ʱ�뵽��������⣺��n������������ɶ�Ԫ�飬����С���ж��ٶ��أ�������أ�
//
//
//�������� :
//
//�����������������ݡ�
//
//����ÿ��������ݣ�
//
//N - �������������n����
//
//a1, a2...an - ��Ҫ���������
//
//��֤ :
//
//1 <= N <= 100000, 0 <= ai <= INT_MAX.
//
//
//
//������� :
//
//	����ÿ�����ݣ��������������һ������ʾ����С�Ķ������ڶ�������ʾ�����Ķ�����
//
//	�������� :
//6
//45 12 45 32 5 6
//
//������� :
//	1 2

#if 0
void func3(vector<int> &nums)
{
	int min_res = 0, max_res;
	sort(nums.begin(), nums.end());
	int size = nums.size();
	int min_count = count(nums.begin(), nums.end(), nums[0]);
	int max_count = count(nums.begin(), nums.end(), nums[size - 1]);
	if (size == 1)
	{
		cout << 0 << " " << 0 << endl;
		return;
	}
	if ((min_count == size) && max_count == size)
	{
		int res = size*(size - 1) / 2;
		cout << res << " " << res << endl;
		return;
	}
	max_res = min_count*max_count;

	int min_val = nums[size - 1] - nums[size - 2];
	for (int i = size - 1; i > 0; --i)
	{
		int tmp = nums[i] - nums[i - 1];
		if (tmp<min_val)
			min_val = tmp;

	}
	for (int i = size - 1; i>0;) {
		int tmp = nums[i] - nums[i - 1];
		if (tmp == min_val)
		{
			int count = 1;
			while (nums[i] - nums[i - 1] == 0)
			{
				++count;
				--i;
			}
			min_res += count*(count - 1) / 2;
		}
		--i;
	}
	cout << min_res << " " << max_res << endl;
}

void testSolution()
{
	int n;
	vector<int> input;
	ifstream cin("test.txt");
	while (cin >> n)
	{
		input.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> input[i];
		func3(input);
		input.clear();
	}
}

#endif