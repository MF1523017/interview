// convert.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
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
	void inOrder(TreeNode* root)
	{
		if (root)
		{
			inOrder(root->left);
			_inOrder.push_back(root);
			if (_inOrder.size() == 1)
				_res = root;
			inOrder(root->right);
		}
	}
	void buildList()
	{
		if (_inOrder.empty()) {
			_res = nullptr;
			return;
		}
		if (_inOrder.size() == 1)
		{
			_res->left = nullptr;
			_res->right = nullptr;
			return;
		}
		for (int i = 0; i<_inOrder.size(); ++i)
		{
			if (i == 0)
			{
				_inOrder[i]->right = _inOrder[i + 1];
				_inOrder[i]->left = nullptr;
			}
			else if (i == _inOrder.size() - 1)
			{
				_inOrder[i]->right = nullptr;
				_inOrder[i]->left = _inOrder[i - 1];
			}
			else
			{
				_inOrder[i]->right = _inOrder[i + 1];
				_inOrder[i]->left = _inOrder[i - 1];
			}

		}
	}
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		inOrder(pRootOfTree);
		buildList();
		return _res;
	}
private:
	vector<TreeNode*> _inOrder;
	TreeNode *_res;
};


int main()
{
	TreeNode *root = new TreeNode(1);
	Solution s;
	s.Convert(root);
    return 0;
}

