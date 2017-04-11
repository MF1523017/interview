#pragma once

#include<iostream>
#include<vector>
using namespace std;
/*
	1-9 的9个数字，每个数字只能出现一次，要求这样一个9位
	的整数：
	其第一位不能被1整除，前两位不能被2整除，前三位不能被
	3整除......依次类推，前9位不能被9整除。
*/
/*
思路：
每一个数字构成的节点都与其他数字相连，构成了一个所有数字都
两两相连的连通图
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

