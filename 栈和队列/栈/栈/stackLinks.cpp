//栈的链式实现
#include<iostream>
using namespace std;
typedef  struct Stack{
  int data;
  Stack *next;
  
}Stack,*stackLink;
void Intial(stackLink &stack)
{
	stack->next=NULL;
	stack->data=0;
}
void push(stackLink &stack,int data)
{  
    stackLink headstack=(stackLink)malloc(sizeof(Stack));
	headstack->data=data;
	headstack->next=stack;
	stack=headstack;
   
}
int pop(stackLink &stack)
{
	if(stack->next!=NULL)
	{
		
	/*	Stack *t=stack;*/
		stack=stack->next;
	/*	free(t);*/
		return stack->data;
	}
	return -1;

}
void main()
{
	stackLink stack;
	Intial(stack);
	for(int i=0;i<500000;i++)
	{
         push(stack,i);
	}

		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;

		cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;

		cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;

		cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;

		cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
		cout<<pop(stack)<<endl;
	
}
