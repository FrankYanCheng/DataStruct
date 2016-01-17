//双向链表,带头节点
#include<iostream>
#include<string>
using namespace std;
typedef struct Node
{
   int data;
   Node *prior;
   Node *next;

}Node,*NodeLinks;
void Intial(NodeLinks &links)
{
     links=(NodeLinks)malloc(sizeof(Node));
	 links->data=0;
	 links->next=links;
	 links->prior=links;

}
//在第s个位置之前插入data元素
void add(NodeLinks &links,int data,int s)
{
	int counter=0;
	NodeLinks node=links;
	NodeLinks InsertNode=(NodeLinks)malloc(sizeof(Node));
	InsertNode->data=data;
	while(node->next!=links&&counter<s-1)
	{ 
		node=node->next;
		counter++;
	}
	InsertNode->prior=node->next->prior;
	InsertNode->next=node->next;
	node->next->prior=InsertNode;
	node->next=InsertNode;
	//if(links==InsertNode->next)
	//{
	//	links->prior=InsertNode->next;
	//}
	links->data++;

}
//删除第s个节点
void deleteNode(NodeLinks &links,int s)
{
  	int counter=0;
	NodeLinks node=links;
	while(node->next!=links&&counter<s-1)
	{ 
		node=node->next;
		counter++;
	}
	//要删除的节点
	NodeLinks DeleteNode=node->next;
    node->next=DeleteNode->next;
    DeleteNode->next->prior=node;
	free(DeleteNode);
	links->data--;
}
void Prints(NodeLinks &links)
{
	NodeLinks node=links;
	while(node->next!=links)
	{
		cout<<node->data<<endl;
		node=node->next;
	}
	cout<<node->data<<endl;

}
void ReseverPrint(NodeLinks &links)
{
	NodeLinks node=links;
	while(node->prior!=links)
	{
		node=node->prior;
		cout<<node->data<<endl;
		
	}
	node=node->prior;
	cout<<"元素个数有"<<node->data<<endl;
}
void main()
{
     NodeLinks links;
	 Intial(links);
	 for(int i=0;i<10;i++)
	 {
	 add(links,i,1);
	 }

	 Prints(links);
	 cout<<"--------------------------"<<endl;
	 ReseverPrint(links);

}
