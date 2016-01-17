// MyStack.cpp : 定义控制台应用程序的入口点。
//自己构造一个链式栈，具有push（入栈），pop（出栈），top（取得栈顶元素），size（返回栈大小），empty（判断是否为空）等功能

#include "stdafx.h"
#include <iostream>

using namespace std;

//构造栈的节点
template <class T>
struct NODE
{
	NODE<T>* next;
	T data;
};

template <class T>
class MyStack
{
public:
	MyStack()
	{
		phead = new NODE<T>;
		if (phead == NULL)
		{
			cout << "Failed to malloc a new node. " << endl;
		}
		else
		{
			phead->data = NULL;
			phead->next = NULL;
		}
	}
	
	//入栈
	void push(T e)
	{
		NODE<T>* p = new NODE<T>;
		if (p == NULL)
		{
			cout << "Failed to malloc a new node. " << endl;
		}
		else
		{
			p->data = e;
			p->next = phead->next;
			phead->next = p;
		}
	}
	
	//出栈
	T pop()
	{
		T e;
		NODE<T>* p = phead->next;

		if(p != NULL)
		{
			phead->next = p->next;
			e = p->data;
			delete p;
			return e;
		}
		else
		{
			cout << "There is no elements in the stack." << endl;
			return NULL;
		}
	}
	
	//取得栈顶元素
	T top()
	{
		T e;
		NODE<T>* p = phead->next;
		if (p != NULL)
		{
			e = p->data;
			return e;
		}
		else
		{
			cout << "There is no elements in the stack." << endl;
			return NULL;
		}
	}

	//取得栈中元素个数
	int size()
	{
		int count(0);
		NODE<T>* p = phead->next;
		while (p != NULL)
		{
			p = p->next;
			count++;
		}
		return count;
	}
	//判断stack是否为空
	bool empty()
	{
		NODE<T>* p = phead;
		if (p->next == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	NODE<T>* phead;
};
int _tmain(int argc, _TCHAR* argv[])
{
	MyStack<int> sta;
	sta.push(1);
	sta.push(2);
	sta.push(3);
	cout << "The size of the stack now is " << sta.size() << endl;
	sta.pop();
	cout << "The top element is " << sta.top() << endl;
	cout << "The size of the stack now is" << sta.size() << endl;
	if (sta.empty())
	{
		cout << "This stack is empty." << endl;
	}
	else
	{
		cout << "This stack is not empty." << endl;
	}
	return 0;
}