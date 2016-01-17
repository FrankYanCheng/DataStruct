#include<iostream>
#include<string>
using namespace std;
typedef struct Node
{
	int expn;
	float value;
	Node *next;
}Node,*NodeLinks;
void Intial(NodeLinks &node)
{
	node=(NodeLinks)malloc(sizeof(Node));
	node->next=NULL;
	node->expn=-1;
	node->value=0;
    
}
//默认添加到默认最后的位置,expn为指数，valu为值
void add(NodeLinks &node,float value,int expn)
{
    NodeLinks links=node;
	while(links->next)
	{
		links=links->next;
	}
    NodeLinks insertNode=(NodeLinks)malloc(sizeof(Node));
	insertNode->expn=expn;
	insertNode->value=value;
	links->next=insertNode;
	insertNode->next=NULL;
}
void prints(NodeLinks &node)
{
	NodeLinks links=node->next;
	while(links!=NULL)
	{
		cout<<links->value<<"X^"<<links->expn;
		if(links->next!=NULL)
		{
			cout<<"+";
		}
		links=links->next;
	}
}
//合并多项式。合并在node1里，消除node2
void combine(NodeLinks &node1,NodeLinks &node2)
{
	//如果不按顺序来排，查找的空间复杂度为n*m不科学
	//int counter0;
	//NodeLinks nodeLink1=node1->next;
	//NodeLinks nodeLink2=node2->next;
	//NodeLinks deleteNode;
	//while(nodeLink1!=NULL)
	//{
	//	deleteNode=nodeLink2;
	//    while(deleteNode)
	//	{
	//		if(deleteNode->expn==nodeLink1->expn)
	//		{
	//			nodeLink1->value=nodeLink1->value+deleteNode->value;
	//			//先不删除
	//		}
	//		else
	//		{

	//		}
	//	   deleteNode=deleteNode->next;

	//	}
	//	nodeLink1=nodeLink1->next;
	//}
	//---------------------------------------------------------
	//按顺序来排的时候 
	NodeLinks nodeLink1=node1->next;
	NodeLinks nodeLink2=node2->next;
	NodeLinks RemeberNode=node1;;
	while(nodeLink1)
	{
		if(nodeLink2->expn<nodeLink1->next->expn)
		{
			RemeberNode->next=nodeLink2;
			nodeLink2->next=nodeLink1;
			nodeLink2->next=nodeLink1;
		}
		if(nodeLink2->expn=nodeLink1->expn)
		{
			nodeLink1->value=nodeLink1->value+nodeLink2->value;
			RemeberNode=nodeLink2;
			nodeLink2=nodeLink2->next;
		    free(RemeberNode);
		}
		nodeLink1=nodeLink1->next;
	}
}
void main()
{
     NodeLinks node;
	 Intial(node);
	 add(node,1,2);
	 add(node,3,5);
	 add(node,3,6);
	 prints(node);
cout<<"-----------------------"<<endl;
	   NodeLinks node2;
	 Intial(node2);
	 add(node2,1,1);
	 add(node2,2,5);
	 add(node2,3,6);
	 	 prints(node2);
cout<<"-----------------------"<<endl;
combine(node,node2);
 prints(node);


}