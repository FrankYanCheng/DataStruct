//ѭ�����У�����һ����λ��������ͷһ���β��,�����ڸ�����֪�Ķ���
#include<iostream>
#include<string>
using namespace std;
typedef struct
{

	int front;
	int rear;
	int *base;
}Queue;
void IntialQueue(Queue &list)
{
	list.base=(int *)malloc(10*sizeof(int));
	list.front=0;
	list.rear=0;
}
void add(Queue &list,int value)
{
	if(((list.rear+1)%10)==list.front)
	{
		cout<<"��������"<<endl;
	}
	else
	{
		list.base[list.rear]=value;
		list.rear=(list.rear+1)%10;
	}
}
void deletes(Queue &list)
{
	if(list.front!=list.rear)
	list.front=(list.front+1)%10;
	else
	{
		cout<<"�����Կ�"<<endl;
	}
}
void prints(Queue &list)
{
	int front=list.front;
	int rear=list.rear;
	while(front!=(rear)%10)
	{
		cout<<list.base[front]<<endl;
		front++;
	}
}
int GetLength(Queue &list)
{
	return (list.rear-list.front+10)%10;	
}
void main()
{
	Queue list;
IntialQueue(list);
for(int i=0;i<1;i++)
{
	add(list,i);
}
for(int j=0;j<11;j++)
deletes(list);

prints(list);cout<<GetLength(list)<<endl;
	
}