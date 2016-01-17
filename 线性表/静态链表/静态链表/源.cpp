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
////初始化链表函数
//void InitSList(StaticList & space)
//{
//	for (int i = 0; i< MAXSIZE - 1; i++)
//	{
//		space[i].cur = i + 1;
//	}
//
//	space[MAXSIZE - 1].cur = 0;//构成循环
//}
//
////分配节点(只需要返回被分配节点在数组中的下标即可)
//int Malloc_SL(StaticList & space)
//{
//	int i = space[0].cur;
//	if (i)
//	{
//		space[0].cur = space[i].cur;//把i节点从空闲链表中删除
//	}
//	return i;
//}
//
////回收节点到空闲链表
//void Free_SLNode(StaticList & space, int t)
//{
//	space[t].cur = space[0].cur;
//	space[0].cur = t;
//}
////插入
//bool insert(StaticList & space, int h, int m, int t)//在第t个元素之前插入一个下标值为m的新节点
//{
//	if (t <= 0)
//	{
//		return false;
//	}
//	int i = h;
//	int n = 0;//计数器
//	while (i)
//	{
//		if (n == t - 1 && space[i].cur)//找到插入节点
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
////删除第n个节点
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
//			Free_SLNode(space, t);//回收被删除的节点
//			return true;
//		}
//		i = space[i].cur;
//		m++;
//	}
//	return false;
//}
//
////在表尾增加一个新节点
//bool add(StaticList & space, int h, int m)//m代表新增加节点的下标值,h表示数据链表的头结点
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
//	//定义一个静态链表
//	StaticList MyList;
//	InitSList(MyList);
//	//分配一个新节点做为数据节点   空闲节点的默认头节点为0
//	int h = Malloc_SL(MyList);
//	MyList[h].cur = 0;
//	//添加新节点
//	int t = Malloc_SL(MyList);
//	MyList[t].data = 1;
//	add(MyList, h, t);
//	t = Malloc_SL(MyList);
//	MyList[t].data = 2;
//	add(MyList, h, t);
//	t = Malloc_SL(MyList);
//	MyList[t].data = 3;
//	add(MyList, h, t);
//	//遍历并输出该链表上的所有数据
//	cout << "遍历并输出该链表上的所有数据：" << endl;
//	int = i = MyList[h].cur;
//	while = (i)  
//	{ cout << mylist[i].data << "="" "; = "" } cout << endl; = "" 在第2个元素之前插入一个新节点 = "" cout << "在第2个元素之前插入一个值为5的新节点：" << endl; = "" t = "Malloc_SL(MyList);"
//	mylist[t].data = "5;" 
//	insert(mylist, h, t, 2); = "" 删除第2个节点 = "" cout << "删除第2节点：" << endl; = "" dele(mylist, h, 2); = ""
//}
//}