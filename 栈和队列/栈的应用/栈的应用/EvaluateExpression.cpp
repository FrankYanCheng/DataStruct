#include<iostream>
#include<string>
using namespace std;
//��ջ�Ľ���ת��
#include<iostream>
#include<string>
using namespace std;
typedef struct
{
   int *base;
   int stacksize;
   int *top;
}Stack;
void Intial(Stack &stack)
{
	stack.stacksize=5;
	stack.base=(int *)malloc(stack.stacksize*sizeof(int));
	stack.top=stack.base;
	//Ĭ�ϳ�ʼ����Ԫ��ֵΪ
	stack.stacksize=5;
	
}
//ջԪ�ص����
void push(Stack &stack,int value)
{
	if(stack.top-stack.base>=stack.stacksize)
	{
		//���¿��ط���ռ�
		stack.base=(int *)realloc(stack.base,(stack.stacksize+3)*sizeof(int));
		stack.top=stack.base+stack.stacksize;
		stack.stacksize+=3;
	}
	*stack.top=value;
	stack.top++;
}
//����Ԫ��,ջ���ǲ���Ԫ��ֵ��
int pop(Stack &stack)
{

	if(stack.top!=stack.base)
	{
	int *top=stack.top;
	//cout<<top<<endl;
	stack.top=stack.top-1;
	//cout<<stack.top<<endl;
	int value=*(stack.top);
	/*free(top);*/
	//Ϊʲô�ͷŲ����ڴ棿
    return value;
	}
	else
	{
		return -1;
	}
}
void prints(Stack &stack)
{
	while(stack.top!=stack.base)
	{
		cout<<*stack.base<<endl;
		stack.base++;
	}
}
bool Combine(char before,char later,Stack &stack)
{
  
}
void main()
{
    Stack stack;
	Intial(stack);
	Stack operatorStack;
	Intial(operatorStack);

	
}