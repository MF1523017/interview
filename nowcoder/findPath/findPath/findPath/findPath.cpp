// findPath.cpp : 定义控制台应用程序的入口点。
//输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。 

#include "stdafx.h"
#include<iostream>
#include<vector>
using std::vector;


struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
class Solution {
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		preOrder(root, 0,expectNumber);
		return res;
	}
	void preOrder(TreeNode *root,int sum, int expectNumber)
	{
		sum += root->val;
		path.push_back(root->val);
		if (root->left == nullptr&&root->right == nullptr&&sum == expectNumber)
			res.push_back(path);
		
		if(root->left!=nullptr)
		preOrder(root->left,sum, expectNumber);
		if(root->right!=nullptr)
		preOrder(root->right,sum, expectNumber);
		sum -= root->val;
		path.pop_back();
	}
private:
	vector<vector<int>> res;
	vector<int> path;
};
int main()
{
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(12);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(7);
	Solution s;
	s.FindPath(root, 22);
    return 0;
}

