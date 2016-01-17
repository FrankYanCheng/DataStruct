////链式队列的实现
//#include<iostream>
//#include<string>
//using namespace std;
//typedef int DataValue;
//typedef struct Node
//{
//	Node *next;
//	DataValue values;
//
//}Node,*NodeList;
//struct LinkQueue
//{
//	NodeList front;
//	NodeList rear;
//};
//void Intials(NodeList &node,LinkQueue &links)
//{
//   node=(NodeList)malloc(sizeof(Node));
//   node->next=NULL;
//   node->values=NULL;
//   links.front=node;
//   links.rear=node;
//}
//void Insert(NodeList &node,LinkQueue &links,DataValue values)
//{
//   NodeList NewNode=(NodeList)malloc(sizeof(Node));
//   NewNode->values=values;
//   links.rear->next=NewNode;
//   links.rear=NewNode;
//}
//void Delete(NodeList &node,LinkQueue &links)
//{
//	if(links.rear!=links.front)
//	{
//	NodeList DeleteNode=node->next;
//	
//	
//	if(links.rear==DeleteNode)
//	{
//		links.rear=node;
//		node->next=node;
//	}
//	
//	
//	else
//	{
//        node->next=DeleteNode->next;
//	} 
//	delete(DeleteNode);
//	}
//	
//}
//void Prints(NodeList &node,LinkQueue &links)
//{
//	NodeList list=node->next;
//	if(links.rear!=links.front)
//	{
//	while(list!=links.rear)
//	{
//		cout<<list->values<<endl;
//	    list=list->next;
//	}
//	cout<<list->values<<endl;
//	}
//    
//}
//void main()
//{
//
//	NodeList ts;
//	LinkQueue g;
//    Intials(ts,g);
//	for(int i=1;i<100;i=i+3)
//	Insert(ts,g,i);
//	Delete(ts,g);
//	Delete(ts,g);
//	
//	Prints(ts,g);
//
//}
