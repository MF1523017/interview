// randomListNode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<unordered_map>
using std::unordered_map;
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
	label(x), next(NULL), random(NULL) {
	}
};

class Solution {
public:
	void buildHash(RandomListNode* pHead)
	{
		RandomListNode *node = pHead;
		while (node)
		{
			RandomListNode *cloned = new RandomListNode(node->label);
			//cloned->label=node->label;
			cloned->next = node->next;
			_nodeMap.insert({ node,cloned });
			node = node->next;
		}
	}
	void cloneRandom()
	{
		for (auto item : _nodeMap)
		{
			std::cout << item.first->label << std::endl;
			if(item.first->random)
				(item.second)->random = _nodeMap[(item.first)->random];
		}
	}
	RandomListNode* Clone(RandomListNode* pHead)
	{
		buildHash(pHead);
		cloneRandom();
		return _nodeMap[pHead];
	}
private:
	unordered_map<RandomListNode*, RandomListNode*> _nodeMap;
};

int main()
{
	RandomListNode *pHead = new RandomListNode(0);
	pHead->next = new RandomListNode(1);
	pHead->next->next = new RandomListNode(2);
	pHead->random = pHead->next->next;
	Solution s;
	s.Clone(pHead);
    return 0;
}

