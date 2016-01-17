//二叉链表的实现
#include<iostream>
#include<string>
#include<stack>
using namespace std;
typedef char TElemType;
typedef struct BiNode {
	TElemType data;
	BiNode *lchild, *rchild;
}BiNode, *BiTree;
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
		T = NULL;
}
TElemType Visit(BiTree &T)
{
	return T->data;
}
void PreOrder(BiTree &T)
{
	if (T != NULL)
	{
		cout << Visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void InOrder(BiTree &T)
{
	if (T != NULL)
	{

		InOrder(T->lchild);
		cout << Visit(T);
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
//前序遍历的非递归算法
void Pre_Order(BiTree &T)
{
	stack<BiTree> s;
	BiTree p = T;
	while (p||!s.empty())
	{
		if (p)
		{
			s.push(p);
			cout << p->data;
			p=p->lchild;
		}
		else
		{
			p =s.top();
			s.pop();
			p = p->rchild;
		}
	}
}
//中序遍历的非递归算法
void In_Order(BiTree &T)
{
	stack<BiTree> s;
	BiTree p = T;
	while (p || !s.empty())
	{
		if (p)
		{
			s.push(p);
			p = p->lchild;
		}
		else
		{
			p = s.top();
			s.pop();
			cout << p->data;
			p = p->rchild;
			
		}
	}
}
//后序遍历的非递归算法
void Post_Order(BiTree &T)
{
	stack<BiTree> s;
	BiTree p = T;
	BiTree pre_p=NULL;
	while (p ||!s.empty())
	{
		if (p)
		{
			s.push(p);
			p = p->lchild;
		}
		else
		{
			p = s.top();
		   //如果存在右子树并且右子树没有访问过
			if ((p->rchild) && !(s.top()->rchild == pre_p))
			{
				p = p->rchild;
			}
			else
			{			
				//输出结点并且设置前置结点，此时只要全部退出输入就可以
			    	cout << p->data;
					pre_p = p;
					p = NULL;
					s.pop();		
			
			}
		
			
		}

	}
}
void main()
{
	BiTree RT;
	CreateBiTree(RT);
	//PreOrder(RT);
	//cout << endl;
	//Pre_Order(RT);

	//InOrder(RT);

	//cout << endl;
	//In_Order(RT);
	Postrder(RT);
	cout << endl; Post_Order(RT);

}