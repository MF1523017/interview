#pragma once
#ifndef  LIST_H
#define LIST_H
struct Node;
using ElementType =int;
//typedef struct Node * PtrToNode;
using PtrToNode = struct Node *;
using Position = PtrToNode;
using List = PtrToNode;
struct Node
{
	ElementType element;
	Position next;
};
inline bool isEmpty(List L)
{
	return L->next == nullptr;
}
inline bool isLast(Position p, List L)
{
	return p->next == nullptr;
}
Position CreateList();
Position Find(ElementType e, List L);
void Delete(ElementType e, List L);
Position FindPrevious(ElementType e, List L);
void Insert(ElementType e, List L, Position p);
void DeleteList(List L);
void printList(List L);
void ListAppend(ElementType e, List L);
Position getTail(List L);
#endif // ! LIST_H
