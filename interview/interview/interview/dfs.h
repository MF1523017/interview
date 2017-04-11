#pragma once

#include<iostream>
#include<vector>
using namespace std;
/*
	1-9 ��9�����֣�ÿ������ֻ�ܳ���һ�Σ�Ҫ������һ��9λ
	��������
	���һλ���ܱ�1������ǰ��λ���ܱ�2������ǰ��λ���ܱ�
	3����......�������ƣ�ǰ9λ���ܱ�9������
*/
/*
˼·��
ÿһ�����ֹ��ɵĽڵ㶼����������������������һ���������ֶ�
������������ͨͼ
*/

vector<bool>visited(10, false);
void dfs(int res,int depth)
{
	if (depth&&res%depth != 0)
		return;
	if (depth == 9)
	{
		cout << res<<endl;
		return;
	}
	for (int i = 1; i <= 9; ++i)
	{
		if (!visited[i]) {
			visited[i] = true;
			dfs(res * 10 + i , depth + 1);
			visited[i] = false;
		}
	}
}


void testSolution()
{
	dfs(0, 0);
}

