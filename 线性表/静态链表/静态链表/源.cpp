//#include<iostream>
//#include<string>
//using namespace std;
//
//const size_t MAXSIZE = 100;
//typedef struct SListNode {
//	int data;
//	size_t cur;
//
//}StaticList[MAXSIZE];
//
//
////��ʼ��������
//void InitSList(StaticList & space)
//{
//	for (int i = 0; i< MAXSIZE - 1; i++)
//	{
//		space[i].cur = i + 1;
//	}
//
//	space[MAXSIZE - 1].cur = 0;//����ѭ��
//}
//
////����ڵ�(ֻ��Ҫ���ر�����ڵ��������е��±꼴��)
//int Malloc_SL(StaticList & space)
//{
//	int i = space[0].cur;
//	if (i)
//	{
//		space[0].cur = space[i].cur;//��i�ڵ�ӿ���������ɾ��
//	}
//	return i;
//}
//
////���սڵ㵽��������
//void Free_SLNode(StaticList & space, int t)
//{
//	space[t].cur = space[0].cur;
//	space[0].cur = t;
//}
////����
//bool insert(StaticList & space, int h, int m, int t)//�ڵ�t��Ԫ��֮ǰ����һ���±�ֵΪm���½ڵ�
//{
//	if (t <= 0)
//	{
//		return false;
//	}
//	int i = h;
//	int n = 0;//������
//	while (i)
//	{
//		if (n == t - 1 && space[i].cur)//�ҵ�����ڵ�
//		{
//			space[m].cur = space[i].cur;
//			space[i].cur = m;
//			return true;
//		}
//		i = space[i].cur;
//		n++;
//	}
//	return false;
//}
//
////ɾ����n���ڵ�
//bool dele(StaticList & space, int h, int n)
//{
//	if (n<0) return false;
//	int i = h;
//	int m = 0;
//	while (i)
//	{
//		if (m == n - 1)
//		{
//			int t = space[i].cur;
//			space[i].cur = space[t].cur;
//			Free_SLNode(space, t);//���ձ�ɾ���Ľڵ�
//			return true;
//		}
//		i = space[i].cur;
//		m++;
//	}
//	return false;
//}
//
////�ڱ�β����һ���½ڵ�
//bool add(StaticList & space, int h, int m)//m���������ӽڵ���±�ֵ,h��ʾ���������ͷ���
//{
//	int i = h;
//	while (space[i].cur)
//	{
//		i = space[i].cur;
//	}
//	space[i].cur = m;
//	space[m].cur = 0;
//	return true;
//}
//
//int main()
//{
//	//����һ����̬����
//	StaticList MyList;
//	InitSList(MyList);
//	//����һ���½ڵ���Ϊ���ݽڵ�   ���нڵ��Ĭ��ͷ�ڵ�Ϊ0
//	int h = Malloc_SL(MyList);
//	MyList[h].cur = 0;
//	//����½ڵ�
//	int t = Malloc_SL(MyList);
//	MyList[t].data = 1;
//	add(MyList, h, t);
//	t = Malloc_SL(MyList);
//	MyList[t].data = 2;
//	add(MyList, h, t);
//	t = Malloc_SL(MyList);
//	MyList[t].data = 3;
//	add(MyList, h, t);
//	//����������������ϵ���������
//	cout << "����������������ϵ��������ݣ�" << endl;
//	int = i = MyList[h].cur;
//	while = (i)  
//	{ cout << mylist[i].data << "="" "; = "" } cout << endl; = "" �ڵ�2��Ԫ��֮ǰ����һ���½ڵ� = "" cout << "�ڵ�2��Ԫ��֮ǰ����һ��ֵΪ5���½ڵ㣺" << endl; = "" t = "Malloc_SL(MyList);"
//	mylist[t].data = "5;" 
//	insert(mylist, h, t, 2); = "" ɾ����2���ڵ� = "" cout << "ɾ����2�ڵ㣺" << endl; = "" dele(mylist, h, 2); = ""
//}
//}