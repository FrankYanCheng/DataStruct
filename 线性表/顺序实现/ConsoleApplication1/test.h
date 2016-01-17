#include <iostream>
#include <stdlib.h>
#include<vector>
typedef int ElemType;

class List  {
private:
	ElemType *list;        //存线性表元素的动态存储空间的指针
	int size;              //存线性表长度
	int MaxSize;          //规定list数组的长度
public:
	List();                //初始化L为空
	~List();    //清除L中的所有元素
	int LengthList();      //返回L的长度
	bool EmptyList();      //判断L是否为空
	ElemType GetList(int pos);  //返回L中第pos个元素的值
	void TraverseList();    //遍历输出L中的所有元素
	bool FindList(ElemType &item);//从L中查找并返回元素
	bool UpdateList(const ElemType &item,const ElemType Number);   //修改L中元素
	bool InsertList(ElemType item, int pos);//向L插入元素
	bool DeleteList(ElemType &item, int pos);//从L删除元素
	void SortList();     //对L中的所有元素重新按给定条件排序
};
List::List()
{

	// 初始定义数组长度为10，以后可增减，或者附加一个形参给定初始数组长度
		MaxSize = 10;
	//动态存储空间分配
	list = new  ElemType[MaxSize];
	if (list == NULL)  {
		cout << "动态可分配的存储空间用完，退出运行! " << endl;
		exit(1);
	}
	//置线性表长度为0，即为空表
	size = 0;
};
List::~List()
{
	if (list!= NULL)
	{
		delete list;
		list = NULL;
	}
	MaxSize = 0;
	size = 0;
}
int List::LengthList() {
	return  size;
}

bool List::EmptyList() {
	return size == 0;
}
ElemType List::GetList(int pos)
{
	if (pos > size || pos < 1)
	{
		cerr << "数据错误";
		exit(1);
	}
	else
		list[pos - 1];
}		 
void List::TraverseList()
{
	if (list!=NULL)
	{
		for (vector<ElemType>::size_type i = 0; i < size; i++)
			cout << list[i] << endl;
	}
}
bool List::FindList(ElemType &item)//从L中查找并返回元素
{
	for (vector<ElemType>::size_type i = 0; i < size; i++)
	{
		if (list[i] == item)
		{
			return true;
		}
	}
	return false;
}	
bool List::UpdateList(const ElemType &item, const ElemType Number)  //修改L中元素
{

		if (list[Number] == item)
		{
			return false;
		}
		else
		{
			list[Number] = item;
			return true;
		}
	
	
}

bool List:: InsertList(ElemType item, int pos)//向L插入元素
{
	if (pos<-1 && pos>size + 1)
		cerr << "插入地址错误";

	if (pos ==-1)
	{
		pos = size + 1;
	}
	if (size == MaxSize)
	{
		int k = sizeof(ElemType);  //计算每个元素存储空间的长度
		list = (ElemType*)realloc(list, MaxSize * 2 * k);

	}
	if (list == NULL)
	{
		cerr << "运行分配空间出错" << endl;
	}
	MaxSize *= 2;
	for (int i = size; i >= pos-1; i--)
	{
		list[i+1] = list[i];
	}
	list[pos - 1] = item;
	size++;
	return true;

}
bool List::DeleteList(ElemType &item, int pos) {
	//检查线性表是否为空，若是则无法删除，返回假
	if (size == 0)  {
		cout << "线性表为空，删除无效!" << endl;
		return  false;
	}
	//检查pos值是否有效，若无效则无法删陈，返回假
	if (pos<-1 || pos>size) {
		cout << "pos值无效!" << endl;
		return  false;
	}
	//求出按值删除时item的删除位置，使之保存到pos中
	int i;
	if (pos == 0)  {
		for (i = 0; i<size; i++)
			if (item == list[i])  break;
		if (i == size)  return false;  //无元素可删返回假
		pos = i + 1;
	}
	//得到表尾元素的序号，被保存在pos中
	else if (pos == -1)  pos = size;
	//把被删除元素的值赋给变参item带回
	item = list[pos - 1];
	//将待删除元素位置后面的所有元素从前向后依次前移一个位置
	for (i = pos; i<size; i++)
		list[i - 1] = list[i];
	//线性表长度减l
	size--;
	//若线性表存储空间空余太多，则进行适当削减
	if (float(size) / MaxSize<0.4 &&  MaxSize>10)  {
		int k = sizeof(ElemType);    //计算每个元素存储空间的长度
		list = (ElemType*)realloc(list, MaxSize*k / 2);
		//线性表动态存储空间缩减为原来的一半
		MaxSize = MaxSize / 2;    //把线性表空间人小修改为新的长度
	}
	//返回真表示删除成功
	return  true;
}

void List::SortList() {       //对L中的所有元素重新按给定条件排序
	int i, j;
	ElemType x;
	for (i = 1; i<size; i++) {   //共循环n-1次
		x = list[i];          //把无序表中的第1个元素暂存x
		for (j = i - 1; j >= 0; j--)    //向前顺序进行比较和移动
			if (x<list[j]) list[j + 1] = list[j];
			else break;
			list[j + 1] = x;         //把x写入到已经空出的j+1位置
	}
}

