// ReverseList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"list.h"
class Solution {
public:
	Node* ReverseList(Node* pHead) {
		if (!pHead) return nullptr;
		Node *p1, *p2,*res;
		p1 = nullptr;
		p2 = pHead->next;
		res = nullptr;
		while (p2)
		{
			Node *tmp = p2->next;
			if (tmp == nullptr)
				res = p2;
			p2->next = p1;
			p1 = p2;
			p2 = tmp;
		}
		return res;
	}
};
int main()
{
	List l1 = CreateList();
	for (int i = 0; i < 10; ++i)
	{
		ListAppend(i, l1);
	}
	Solution s;
	List result = s.ReverseList(l1);
	printList(result);
    return 0;
}

