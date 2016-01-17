// MyStack.cpp : �������̨Ӧ�ó������ڵ㡣
//�Լ�����һ����ʽջ������push����ջ����pop����ջ����top��ȡ��ջ��Ԫ�أ���size������ջ��С����empty���ж��Ƿ�Ϊ�գ��ȹ���

#include "stdafx.h"
#include <iostream>

using namespace std;

//����ջ�Ľڵ�
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
	
	//��ջ
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
	
	//��ջ
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
	
	//ȡ��ջ��Ԫ��
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

	//ȡ��ջ��Ԫ�ظ���
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
	//�ж�stack�Ƿ�Ϊ��
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