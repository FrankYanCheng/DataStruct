//ʵ����ͨ��ѭ������
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
// �ڵ�s���ڵ�ǰ����ֵΪdata�Ľڵ�
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
//	 �������β���
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
// ɾ����s���ڵ�����ݣ��ӵ�һ���ڵ㿪ʼ
//void deleteNode(NodeLinks &node,int s)
// {
//	
//	 int counter=0;
//	 NodeLinks link=node;
//	 NodeLinks deleteLinks=(NodeLinks)malloc(sizeof(Node));
//	 �ҵ�Ҫɾ���ڵ����һ���ڵ�
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