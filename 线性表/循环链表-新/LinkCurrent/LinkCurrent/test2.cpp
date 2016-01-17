//实现带头节点带尾结点的循环列表，实验插入
#include<string>
#include<iostream>
using namespace std;
typedef struct Node
{
	Node *NextNode;
	int data;
}Node,*NodeLinks;
void Intial(NodeLinks &node,NodeLinks &endNode)
{
	node=(NodeLinks)malloc(sizeof(Node));
	node->data=0;
	node->NextNode=node;
	endNode=(NodeLinks)malloc(sizeof(Node));
}
void Insert(NodeLinks &node,int data,int s,NodeLinks &endNode)
{
	NodeLinks Insertlinks=(NodeLinks)malloc(sizeof(Node));
	Insertlinks->data=data;
	NodeLinks links=node;
	int counter=0;
	while(counter<s-1&&links->NextNode!=node)
		{
		  links=links->NextNode;
		  counter=counter+1;
		}
		if(links->NextNode!=node)
	   {
		  Insertlinks->NextNode=links->NextNode;
		links->NextNode=Insertlinks;
		
	   }
		else
		{
		links->NextNode=Insertlinks;
		Insertlinks->NextNode=node;
		endNode=Insertlinks;
		}
		node->data++;
}
void combine(NodeLinks &endNode1,NodeLinks &endNode2)
{
	NodeLinks links=endNode1->NextNode;
	links->data=endNode2->NextNode->data+links->data;
	endNode1->NextNode=endNode2->NextNode->NextNode;
	endNode2->NextNode=links;

      }
void prints(NodeLinks &node)
{
	NodeLinks links=node;
	while(links->NextNode!=node)
	{
		cout<<links->data<<endl;
		links=links->NextNode;
	}
	cout<<links->data<<endl;

}
void main()
{
 NodeLinks node,endNode;
	 Intial(node,endNode);
	Insert(node,10,1,endNode);
	Insert(node,44,2,endNode);
	Insert(node,13,2,endNode);
 NodeLinks node2,endNode2;

	 Intial(node2,endNode2);
	Insert(node2,1,1,endNode2);
	Insert(node2,2,1,endNode2);
	Insert(node2,3,1,endNode2);
	Insert(node2,4,1,endNode2);
	Insert(node2,5,1,endNode2);
	Insert(node2,6,1,endNode2);
	Insert(node2,7,1,endNode2);
   combine(endNode,endNode2);
	prints(node);
	
}
