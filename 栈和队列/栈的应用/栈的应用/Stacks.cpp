
#include<string>
#include<iostream>
#include "Stacks.h"
using namespace std;
void Stacks:: Intial(Stack &stack)
{
	stack.stacksize=5;
	stack.base=(int *)malloc(stack.stacksize*sizeof(int));
	stack.top=stack.base;
	//默认初始化的元素值为
	stack.stacksize=5;
	
}
//栈元素的添加
void Stacks:: push(Stack &stack,int value)
{
	if(stack.top-stack.base>=stack.stacksize)
	{
		//重新开拓分配空间
		stack.base=(int *)realloc(stack.base,(stack.stacksize+3)*sizeof(int));
		stack.top=stack.base+stack.stacksize;
		stack.stacksize+=3;
	}
	*stack.top=value;
	stack.top++;
}
//弹出元素,栈顶是不存元素值的
 int Stacks:: pop(Stack &stack)
{

	if(stack.top!=stack.base)
	{
	int *top=stack.top;
	//cout<<top<<endl;
	stack.top=stack.top-1;
	//cout<<stack.top<<endl;
	int value=*(stack.top);
	/*free(top);*/
	//为什么释放不了内存？
    return value;
	}
	else
	{
		return -1;
	}
}
void Stacks:: prints(Stack &stack)
{
	while(stack.top!=stack.base)
	{
		cout<<*stack.base<<endl;
		stack.base++;
	}
}

