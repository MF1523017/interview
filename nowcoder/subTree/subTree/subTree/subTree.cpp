// subTree.cpp : �������̨Ӧ�ó������ڵ㡣
//�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ�� 

#include "stdafx.h"
#include<iostream>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool res = false;
		if (pRoot1 != nullptr&&pRoot2 != nullptr) {
			if (pRoot1->val == pRoot2->val)
				res = isHas(pRoot1, pRoot2);
			if (!res)
				res = HasSubtree(pRoot1->left, pRoot2);
			if (!res)
				res = HasSubtree(pRoot1->right, pRoot2);
		}
		return res;
	}
	bool isHas(TreeNode *pRoot1, TreeNode *pRoot2)
	{
		if (pRoot2 == nullptr)//���Tree2Ϊ�գ���˵���ڶ������������ˣ���ƥ��ɹ�
			return true;
		if (pRoot1 == nullptr)
			return false;
		if (pRoot1->val != pRoot2->val)
			return false;
		return isHas(pRoot1->left, pRoot2->left) && isHas(pRoot1->right, pRoot2->right);
	}

};

int main()
{
	char str[14] = "helloworld!";
	printf("%s,%5.3s\n", str, str);
	int i = 3; 
	printf("%d %d", ++i, ++i);
    return 0;
}

