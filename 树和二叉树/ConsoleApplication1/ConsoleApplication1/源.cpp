//二叉链表的实现
#include<iostream>
#include<string>
using namespace std;
typedef char TElemType;
typedef struct BiNode {
	TElemType data;
	BiNode *lchild, *rchild;
}BiNode,*BiTree;
void CreateBiTree(BiTree &T)
{
	T = (BiTree)malloc(sizeof(BiNode));

	char ch;
	cin >> ch;
	if (ch != '#')
	{	
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);

	}
	else
		T= NULL;
}
TElemType Visit(BiTree &T)
{
	return T->data;
}
void PreOrder(BiTree &T)
{
	if (T != NULL)
	{
	cout<<Visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void InOrder(BiTree &T)
{
	if (T != NULL)
	{
		
		InOrder(T->lchild);
		cout << Visit(T) ;
		InOrder(T->rchild);
	}
}
void Postrder(BiTree &T)
{
	if (T != NULL)
	{
	
		Postrder(T->lchild);
		Postrder(T->rchild);
		cout << Visit(T);
	}
}

void main()
{
	BiTree RT;
	CreateBiTree(RT);
	PreOrder(RT);
	cout << endl;
	InOrder(RT);
	cout << endl;
	Postrder(RT);

}