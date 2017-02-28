#include"stdafx.h"
#include "list.h"
#include<iostream>
Position CreateList()
{
	Position tmp = new Node;//带有头节点的链表
	tmp->next = nullptr;
	return tmp;
}
Position Find(ElementType e, List L)
{
	Position tmp;
	tmp = L->next;
	while (tmp->next != nullptr && tmp->element != e)
		tmp = tmp->next;
	return tmp;
}
Position FindPrevious(ElementType e, List L)
{
	Position tmp;
	tmp = L;
	while (tmp->next != nullptr && tmp->next->element != e)
		tmp = tmp->next;
	return tmp;
}
void Delete(ElementType e, List L)
{
	Position tmp,p;
	p = FindPrevious(e, L);
	if (!isLast(p,L)){
		tmp = p->next;
		p->next = tmp->next;
		delete tmp;
	}
}
void Insert(ElementType e, List L, Position p)
{
	Position tmp;
	tmp = new Node;
	tmp->element = e;
	tmp->next = p->next;
	p->next = tmp;
}
Position getTail(List L)
{
	Position p=L;
	while (p->next != nullptr)
	{
		p = p->next;
	}
	return p;
}
void ListAppend(ElementType e, List L)
{
	Position p, tmp;
	p = getTail(L);
	tmp = new Node;
	tmp->element = e;
	tmp->next = nullptr;
	p->next = tmp;	
}
void DeleteList(List L)
{
	Position tmp,p;
	tmp = L;
	while (tmp != nullptr) {
		p = tmp->next;
		delete tmp;
		tmp = p;
	}
}
void printList(List L)
{
	Position tmp;
	tmp = L->next;
	while (tmp != nullptr) {
		
		std::cout << tmp->element<< ' ';
		tmp = tmp->next;
	}
}