// treeMaxPath.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;
struct Tree
{
	Tree *left;
	Tree *right;
	int val;
	Tree(int v) :val(v), left(nullptr), right(nullptr) {}
};

int maxPathSum(Tree *root)
{
	if (root == nullptr)
		return 0;
	return root->val + max(maxPathSum(root->left), maxPathSum(root->right));
}
int main()
{
	Tree *root = new Tree(1);
	root->left = new Tree(2);
	root->right = new Tree(3);
	root->left->left = new Tree(2);
	root->left->right = new Tree(4);

	cout << maxPathSum(root)<<endl;
    return 0;
}

