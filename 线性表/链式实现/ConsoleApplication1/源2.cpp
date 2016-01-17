#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;
typedef int ElementType;
typedef struct Node
{
	ElementType data;
	Node  *next;
}Node, *NodeLinks;

void  Intial_Node(NodeLinks &node)
{
	node = (NodeLinks)malloc(sizeof(Node));
	node->next = NULL;
	node->data = 0;
}
bool AddNode(NodeLinks &node,int pos,ElementType data)
{
	NodeLinks links = node;
	int counter = 0;
	while (links&&counter < pos - 1)
	{
		links = links->next;
		counter++;
	}
	if (!links||counter >=pos)
	{
		return false;
	}
	NodeLinks the_addNode = (NodeLinks)malloc(sizeof(Node));
	the_addNode->next= links->next;
	the_addNode->data = data;
	links->next = the_addNode;
	node->data++;
	return true;
	
}
bool DeleteNode(NodeLinks &node, int pos)
{
	int counter=0;
	NodeLinks links = node;
	while (links&&counter < pos - 1)
	{
		links = links->next;
		counter++;
	}
	if (!links || counter >= pos)
	{
		return false;
	}
	NodeLinks deleteNode = links->next;
	links->next = deleteNode->next;
	free(deleteNode);
	node->data--;
	return true;
}
bool ClearNode(NodeLinks &node)
{
	cout << "清除链表数据" << endl;
	NodeLinks links = node->next;
	while (links)
	{
		NodeLinks deleteLinks = links;
		links = links->next;
		free(deleteLinks);
	}
	if (!node)
	{
		return false;
	}
	node->next = NULL;
	node->data = 0;
	return true;
}
bool DestoryNode(NodeLinks &node)
{
	
	cout << "释放线性表" << endl;
	if (node==NULL)
	{
		cout << "线性表损坏" << endl;
	}
	NodeLinks links;
	while (node)
	{
	    links = node;
		node = node->next;
		free(links);
	}
	if (!node)
	{
		return true;
	}
	return false;
}
void PrintNode(NodeLinks &node)
{
	cout << "开始输出" << endl;
	NodeLinks links = node->next;
	while (links)
	{
		cout << links->data << endl;
	    links = links->next;
	}
}
int SearchNode(NodeLinks &node,ElementType result)
{
	int counter = 0;
	node = node->next;
	while (node)
	{
		counter++;
		if (node->data == result)
		{
			return counter;
		}
		node = node->next;
	}
	return -1;
}

void CombineNode(NodeLinks  &a, NodeLinks &b, NodeLinks &c)
{

	a = a->next;
	b = b->next;
	NodeLinks l = c;
	while (a&&b)
	{
		if (a->data <= b->data)
		{
			l->next = a;
			l->next->data = a->data;
			a = a->next;
			l = l->next;
		}
		else
		{
			l->next = b;
			l->next->data = b->data;
			b = b->next;
			l = l->next;
		}
	}
	
	l->next = a ? a : b;
}
void main()
{
	//NodeLinks test;
	//Intial_Node(test);
	//AddNode(test, 1, 456);
	//AddNode(test, 2, 123);
	//AddNode(test, 2, 111);
	//AddNode(test, 2, 444);
	//DeleteNode(test, 2);
	//PrintNode(test);
	///*ClearNode(test);
	//AddNode(test, 1, 456);*/
	///*DestoryNode(test);*/
	//PrintNode(test);
	//cout << SearchNode(test, 456);
	NodeLinks test;		 
	Intial_Node(test);
	AddNode(test, 1, 7);
	AddNode(test, 1, 5);
	AddNode(test, 1, 3);
	AddNode(test, 1, 1);


	NodeLinks test2;
	Intial_Node(test2);
	AddNode(test2, 1, 8);
	AddNode(test2, 1, 6);
	AddNode(test2, 1, 4);
	AddNode(test2, 1, 2);
	PrintNode(test);
	cout << "-----------------------------------" << endl;
	PrintNode(test2);
	cout << "-----------------------------------" << endl;
	NodeLinks test3;
	Intial_Node(test3);
	CombineNode(test, test2, test3);
	PrintNode(test3);
}

