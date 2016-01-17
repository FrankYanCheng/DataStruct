//二叉查找树的实现
#include<iostream>
#include<string>
using namespace std;
typedef struct Node
{
	int data;
	Node *rchild;
	Node *lchild;

}Node,*NodeList;
void insertNode(int keys, NodeList  &list)
{
	int data;
	cin >> data;
	if (list==NULL)
	{
		list = (NodeList)malloc(sizeof(Node));
		list->data = data;
		list->lchild = NULL;
		list->rchild = NULL;
	}
	else if (list->data >keys)
	{
		insertNode(list->data,list->lchild);
	}
	else if (list->data < keys)
	{
		insertNode(list->data, list->rchild);
	}
	

}
void InOrder(NodeList &T)
{
	if (T != NULL)
	{

		InOrder(T->lchild);
		cout << T->data;
		InOrder(T->rchild);
	}
}
void createNode()
{
	cout << "请输入关键字" << endl;
	int keys;
	cin >> keys;
	int i = 0;

	NodeList list = (NodeList)malloc(sizeof(Node));
	list->data = keys;
	list->lchild = NULL;
	list->rchild = NULL;
	while (i<5)
	{
		insertNode(keys, list);
		i++;
	}
	InOrder(list);
}
void main()
{
	createNode();
}