#include"tree.h"
#include<iostream>
//�������������������ԶС����������
SearchTree MakeEmpty(SearchTree T)
{
    if (T!=nullptr)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        delete T;
    }
	return T;
}
SearchTree Find(SearchTree T,ElementType e)
{
    if (T==nullptr)
        return T;
    if (e<T->Element)
        return Find(T->Left,e);
    else if(e>T->Element)
        return Find(T->Right,e);
    else
        return T;
}
SearchTree FindMin(SearchTree T)
{
    if (T==nullptr)
        return T;
    else if (T->Left==nullptr)
        return T;
    else
        return FindMin(T->Left);
}
SearchTree FindMax(SearchTree T)
{
    if (T==nullptr)
        return T;
    else if (T->Right==nullptr)
        return T;
    else
        return FindMax(T->Right);
}
SearchTree Insert(SearchTree T,ElementType e)
{
    if (T==nullptr){
        T=new TreeNode;
        T->Element=e;
        T->Left=T->Right=nullptr;
        }
    if (e<T->Element)
        T->Left=Insert(T->Left,e);
    else if(e>T->Element)
        T->Right=Insert(T->Right,e);
    return T;
}
SearchTree Delete(SearchTree T,ElementType e)
{
	Position tmp;
	if (T==nullptr)
		return T;
	else if(e<T->Element)
		T->Left=Delete(T->Left,e);
	else if (e>T->Element)
		T->Right=Delete(T->Right,e);
	else if(T->Left&&T->Right)
	{
		tmp=FindMin(T->Right);
		T->Element=tmp->Element;
		T->Right=Delete(T->Right,tmp->Element);
	}
	else
	{
		tmp=T;
		if (T->Left==nullptr)
			T=T->Right;
		else if(T->Right==nullptr)
			T=T->Left;
		delete tmp;
	}
	return T;

}
void PrintTreePostOrder(SearchTree T)
{
	if(T!=nullptr)
	{
		PrintTreePostOrder(T->Left);
		PrintTreePostOrder(T->Right);
		std::cout<<T->Element<<" ";
	}
}
void PrintTreePreOrder(SearchTree T)
{
	if(T!=nullptr)
	{
		std::cout<<T->Element<<" ";
		PrintTreePreOrder(T->Left);
		PrintTreePreOrder(T->Right);
		
	}
}
void PrintTreeInOrder(SearchTree T)
{
	if(T!=nullptr)
	{
		PrintTreeInOrder(T->Left);
		std::cout<<T->Element<<" ";
		PrintTreeInOrder(T->Right);
	}
}

