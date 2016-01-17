//#include<iostream>
//#include<string>
//#include<stdio.h>
//typedef int ElemType;
//typedef struct LNode
//{	
//	ElemType data;
//	LNode *next;
//	
//}LNode, *LinkList;
//int init_List(LinkList &l)
//{
//	printf("初始化线性表\n");
//	//产生一个头结点，并且使L指向头结点  
//	l = (LinkList)malloc(sizeof(LNode));
//	if (!l)
//		exit(OVERFLOW);//分配空间失败  
//	l->next = NULL;//头结点的指针域为空表示无元素  
//	l->data = 0;//头结点数据域用于表示链表的长度  
//	return 1;
//}
//// 销毁链式单向线性表
//void destory_List(LinkList &l)
//{
//	printf("销毁线性表");
//	LinkList q;
//	/*循环的释放每一个结点的内存空间*/
//	while (l)
//	{
//		q = l->next;
//		free(l);
//		l = q;
//	}
//}
////将线性表重新置为空表，并非销毁  
//int clear_List(LinkList &l)
//{
//	printf("清空线性表，并非销毁\n");
//	LinkList p, q;
//	p = l->next;//p指向第一个结点  
//	while (p)
//	{
//		q = p->next;
//		free(p);
//		p = q;
//	}
//	//之后将头指针域的指向性设置为空  
//	l->next = NULL;
//	l->data = 0;
//	return 1;
//}
///*删除线性表中的某个位置元素
//i是从1开始的**/
//int delete_LinkList(LinkList &l, int i)
//{
//	printf("删除线性表%d位置的元素\n", i);
//	int j = 0;
//	LinkList p = l;
//	//首先找到要删除的元素的位置
//	while (p->next&&i >= 1 && j<i - 1)
//	{
//		p = p->next;
//		j++;
//	}
//	if (!p->next || j>i - 1)
//		return 0;//删除的位置不合理
//	LinkList q = p->next;
//	p->next = q->next;
//	free(q);
//	l->data--;
//	return 1;
//}
////线性表插入(带头结点的)
////在第i个位置之前插入e，i值从1开始
//int insert_List(LinkList &l, int i, ElemType e)
//{
//	printf("在第%d个位置插入%d\n", i, e);
//	//首先寻找第i个结点
//	LinkList q = l, s;
//	int j = 0;//用于循环的计数器
//	while (q&&j<i - 1)
//	{
//		q = q->next;
//		j++;
//	}
//	if (!q || j>i - 1)
//	{
//		return 0;
//	}
//	s = (LinkList)malloc(sizeof(LNode));//生成一个新的结点
//	s->data = e;
//	s->next = q->next;
//	q->next = s;
//	l->data++;//线性表的长度加1
//	return 1;
//}
//
///*取得线性表的i位置的元素，存在返回ok，并将之存在e中
//反之返回ERROR，需要注意的是l是带头结点的单链表
//*/
//int getElem(LinkList l, int i, ElemType &e)
//{
//	LNode * p = l->next;
//	int count = 1;
//	//初始化，使p指向第一个结点，count为计数器
//	while (p&&count < i)
//	{
//		p = p->next;
//		count++;
//	}
//	//p指针移动到要取得的元素位置的结点处
//	if (!p || count >i)
//		return 0;
//	e = p->data;
//	return e;
//}
///*判断线性表是否为空*/
//int isEmpty(LinkList &l)
//{
//	if (l->data == 0)
//		return 0;
//	else
//		return 1;
//
//}
//int main()
//{
//	LinkList l;
//	int e;
//	init_List(l);
//	insert_List(l, 1, 3);
//	insert_List(l, 1, 4);
//	insert_List(l, 1, 5);
//	insert_List(l, 1, 6);
//	printf("第一个位置的元素为%d\n", getElem(l, 1, e));
//	printf("线性表的元素个数;%d\n", l->data);
//	clear_List(l);
//	destory_List(l);
//	//_getch();
//	return 0;
//}