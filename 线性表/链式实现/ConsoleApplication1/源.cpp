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
//	printf("��ʼ�����Ա�\n");
//	//����һ��ͷ��㣬����ʹLָ��ͷ���  
//	l = (LinkList)malloc(sizeof(LNode));
//	if (!l)
//		exit(OVERFLOW);//����ռ�ʧ��  
//	l->next = NULL;//ͷ����ָ����Ϊ�ձ�ʾ��Ԫ��  
//	l->data = 0;//ͷ������������ڱ�ʾ����ĳ���  
//	return 1;
//}
//// ������ʽ�������Ա�
//void destory_List(LinkList &l)
//{
//	printf("�������Ա�");
//	LinkList q;
//	/*ѭ�����ͷ�ÿһ�������ڴ�ռ�*/
//	while (l)
//	{
//		q = l->next;
//		free(l);
//		l = q;
//	}
//}
////�����Ա�������Ϊ�ձ���������  
//int clear_List(LinkList &l)
//{
//	printf("������Ա���������\n");
//	LinkList p, q;
//	p = l->next;//pָ���һ�����  
//	while (p)
//	{
//		q = p->next;
//		free(p);
//		p = q;
//	}
//	//֮��ͷָ�����ָ��������Ϊ��  
//	l->next = NULL;
//	l->data = 0;
//	return 1;
//}
///*ɾ�����Ա��е�ĳ��λ��Ԫ��
//i�Ǵ�1��ʼ��**/
//int delete_LinkList(LinkList &l, int i)
//{
//	printf("ɾ�����Ա�%dλ�õ�Ԫ��\n", i);
//	int j = 0;
//	LinkList p = l;
//	//�����ҵ�Ҫɾ����Ԫ�ص�λ��
//	while (p->next&&i >= 1 && j<i - 1)
//	{
//		p = p->next;
//		j++;
//	}
//	if (!p->next || j>i - 1)
//		return 0;//ɾ����λ�ò�����
//	LinkList q = p->next;
//	p->next = q->next;
//	free(q);
//	l->data--;
//	return 1;
//}
////���Ա����(��ͷ����)
////�ڵ�i��λ��֮ǰ����e��iֵ��1��ʼ
//int insert_List(LinkList &l, int i, ElemType e)
//{
//	printf("�ڵ�%d��λ�ò���%d\n", i, e);
//	//����Ѱ�ҵ�i�����
//	LinkList q = l, s;
//	int j = 0;//����ѭ���ļ�����
//	while (q&&j<i - 1)
//	{
//		q = q->next;
//		j++;
//	}
//	if (!q || j>i - 1)
//	{
//		return 0;
//	}
//	s = (LinkList)malloc(sizeof(LNode));//����һ���µĽ��
//	s->data = e;
//	s->next = q->next;
//	q->next = s;
//	l->data++;//���Ա�ĳ��ȼ�1
//	return 1;
//}
//
///*ȡ�����Ա��iλ�õ�Ԫ�أ����ڷ���ok������֮����e��
//��֮����ERROR����Ҫע�����l�Ǵ�ͷ���ĵ�����
//*/
//int getElem(LinkList l, int i, ElemType &e)
//{
//	LNode * p = l->next;
//	int count = 1;
//	//��ʼ����ʹpָ���һ����㣬countΪ������
//	while (p&&count < i)
//	{
//		p = p->next;
//		count++;
//	}
//	//pָ���ƶ���Ҫȡ�õ�Ԫ��λ�õĽ�㴦
//	if (!p || count >i)
//		return 0;
//	e = p->data;
//	return e;
//}
///*�ж����Ա��Ƿ�Ϊ��*/
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
//	printf("��һ��λ�õ�Ԫ��Ϊ%d\n", getElem(l, 1, e));
//	printf("���Ա��Ԫ�ظ���;%d\n", l->data);
//	clear_List(l);
//	destory_List(l);
//	//_getch();
//	return 0;
//}