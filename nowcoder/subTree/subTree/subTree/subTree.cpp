// subTree.cpp : 定义控制台应用程序的入口点。
//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构） 

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
		if (pRoot2 == nullptr)//如果Tree2为空，则说明第二棵树遍历完了，即匹配成功
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

