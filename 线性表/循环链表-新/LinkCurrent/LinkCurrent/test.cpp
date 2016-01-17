//实现普通的循环链表
//#include<iostream>
//#include<string>
//using namespace std;
// typedef  struct Node
//{
//	Node *nextNode;
//    int data;
//}Node,*NodeLinks;
// void intials(NodeLinks &node)
// {
//	 node=(NodeLinks)malloc(sizeof(Node));
//	 node->nextNode=node;
//	 node->data=0;
//
// }
// 在第s个节点前插入值为data的节点
// bool add(NodeLinks  &node,int data,int s)
// {
//	 if(s<=0)
//	 {
//		 return false;
//	 }
//	 NodeLinks nodelinks=node;
//	 NodeLinks links=(NodeLinks)malloc(sizeof(Node));
//	 links->data=data;
//	 int counter=0;
//	 while(counter<s-1&&nodelinks->nextNode!= node)
//	 {
//		 counter=counter+1;
//	     nodelinks=nodelinks->nextNode;
//	    
//	 }
//	 如果不是尾结点
//	 if(nodelinks->nextNode!=node)
//	 {
//	 links->nextNode=nodelinks->nextNode;
//	 nodelinks->nextNode=links;
//	  node->data=node->data+1;
//	  return true;
//	 }
//	 else
//	 {
//		 nodelinks->nextNode=links;
//		 links->nextNode=node;
//		  node->data=node->data+1;
//	 }
//	
//	
//
// }
// 删除第s个节点的内容，从第一个节点开始
//void deleteNode(NodeLinks &node,int s)
// {
//	
//	 int counter=0;
//	 NodeLinks link=node;
//	 NodeLinks deleteLinks=(NodeLinks)malloc(sizeof(Node));
//	 找到要删除节点的上一个节点
//	 while(counter<s-1&&link->nextNode!=node)
//	 {
//		 link=link->nextNode;
//		 counter=counter+1;
//	 }
//	 deleteLinks=link->nextNode;
//		 link->nextNode=deleteLinks->nextNode;
//		 free(deleteLinks);
//		 node->data--;
//	
// }
// void prints(NodeLinks &node)
// {
//	 NodeLinks links=node;
//	 while(links->nextNode!=node)
//	 {
//		 cout<<links->data<<endl;
//	     links=links->nextNode;
//	 }
//	 cout<<links->data<<endl;
// }
// void main()
//{
//      NodeLinks node;
//	  intials(node);
//	for(int i=0;i<20;i++)
//	{
//		add(node,i,1);
//	}
//
//     deleteNode(node,1);
//	  prints(node);
//}