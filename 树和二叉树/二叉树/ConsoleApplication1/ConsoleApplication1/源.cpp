//���������ʵ��
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
//ǰ������ķǵݹ��㷨
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
//��������ķǵݹ��㷨
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
//��������ķǵݹ��㷨
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
		   //�����������������������û�з��ʹ�
			if ((p->rchild) && !(s.top()->rchild == pre_p))
			{
				p = p->rchild;
			}
			else
			{			
				//�����㲢������ǰ�ý�㣬��ʱֻҪȫ���˳�����Ϳ���
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