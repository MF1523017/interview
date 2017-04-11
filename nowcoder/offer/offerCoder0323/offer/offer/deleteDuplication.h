#pragma once
#include<iostream>
using namespace std;
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == nullptr || pHead->next == nullptr)return pHead;
		ListNode foo(INT_MIN);
		foo.next = pHead;
		ListNode *p = pHead;
		ListNode *prev = &foo;
		while (p&&p->next)
		{
			if (p->val == p->next->val)
			{
				int val = p->val;
				while (p&&val == p->val)
				{
					ListNode *tmp = p->next;
					delete p;
					p = tmp;
				}
				prev->next=p;
			}
			else {
				p = p->next;
				prev = prev->next;
			}

		}
		return foo.next;
	}
};

void  testSolution()
{
	
	ListNode *pHead = new ListNode(1);
	ListNode *tmp = pHead;
	tmp->next = new ListNode(1);
	tmp = tmp->next;
	tmp->next = new ListNode(3);
	tmp = tmp->next;
	tmp->next = new ListNode(3);
	tmp = tmp->next;
	tmp->next = new ListNode(4);
	tmp = tmp->next;
	tmp->next = new ListNode(4);
	tmp = tmp->next;
	tmp->next = new ListNode(6);
	Solution s;

	ListNode *res=s.deleteDuplication(pHead);
	cout << res << endl<<pHead<<endl;
	
}