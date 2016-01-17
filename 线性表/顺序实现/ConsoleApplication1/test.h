#include <iostream>
#include <stdlib.h>
#include<vector>
typedef int ElemType;

class List  {
private:
	ElemType *list;        //�����Ա�Ԫ�صĶ�̬�洢�ռ��ָ��
	int size;              //�����Ա���
	int MaxSize;          //�涨list����ĳ���
public:
	List();                //��ʼ��LΪ��
	~List();    //���L�е�����Ԫ��
	int LengthList();      //����L�ĳ���
	bool EmptyList();      //�ж�L�Ƿ�Ϊ��
	ElemType GetList(int pos);  //����L�е�pos��Ԫ�ص�ֵ
	void TraverseList();    //�������L�е�����Ԫ��
	bool FindList(ElemType &item);//��L�в��Ҳ�����Ԫ��
	bool UpdateList(const ElemType &item,const ElemType Number);   //�޸�L��Ԫ��
	bool InsertList(ElemType item, int pos);//��L����Ԫ��
	bool DeleteList(ElemType &item, int pos);//��Lɾ��Ԫ��
	void SortList();     //��L�е�����Ԫ�����°�������������
};
List::List()
{

	// ��ʼ�������鳤��Ϊ10���Ժ�����������߸���һ���βθ�����ʼ���鳤��
		MaxSize = 10;
	//��̬�洢�ռ����
	list = new  ElemType[MaxSize];
	if (list == NULL)  {
		cout << "��̬�ɷ���Ĵ洢�ռ����꣬�˳�����! " << endl;
		exit(1);
	}
	//�����Ա���Ϊ0����Ϊ�ձ�
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
		cerr << "���ݴ���";
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
bool List::FindList(ElemType &item)//��L�в��Ҳ�����Ԫ��
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
bool List::UpdateList(const ElemType &item, const ElemType Number)  //�޸�L��Ԫ��
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

bool List:: InsertList(ElemType item, int pos)//��L����Ԫ��
{
	if (pos<-1 && pos>size + 1)
		cerr << "�����ַ����";

	if (pos ==-1)
	{
		pos = size + 1;
	}
	if (size == MaxSize)
	{
		int k = sizeof(ElemType);  //����ÿ��Ԫ�ش洢�ռ�ĳ���
		list = (ElemType*)realloc(list, MaxSize * 2 * k);

	}
	if (list == NULL)
	{
		cerr << "���з���ռ����" << endl;
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
	//������Ա��Ƿ�Ϊ�գ��������޷�ɾ�������ؼ�
	if (size == 0)  {
		cout << "���Ա�Ϊ�գ�ɾ����Ч!" << endl;
		return  false;
	}
	//���posֵ�Ƿ���Ч������Ч���޷�ɾ�£����ؼ�
	if (pos<-1 || pos>size) {
		cout << "posֵ��Ч!" << endl;
		return  false;
	}
	//�����ֵɾ��ʱitem��ɾ��λ�ã�ʹ֮���浽pos��
	int i;
	if (pos == 0)  {
		for (i = 0; i<size; i++)
			if (item == list[i])  break;
		if (i == size)  return false;  //��Ԫ�ؿ�ɾ���ؼ�
		pos = i + 1;
	}
	//�õ���βԪ�ص���ţ���������pos��
	else if (pos == -1)  pos = size;
	//�ѱ�ɾ��Ԫ�ص�ֵ�������item����
	item = list[pos - 1];
	//����ɾ��Ԫ��λ�ú��������Ԫ�ش�ǰ�������ǰ��һ��λ��
	for (i = pos; i<size; i++)
		list[i - 1] = list[i];
	//���Ա��ȼ�l
	size--;
	//�����Ա�洢�ռ����̫�࣬������ʵ�����
	if (float(size) / MaxSize<0.4 &&  MaxSize>10)  {
		int k = sizeof(ElemType);    //����ÿ��Ԫ�ش洢�ռ�ĳ���
		list = (ElemType*)realloc(list, MaxSize*k / 2);
		//���Ա�̬�洢�ռ�����Ϊԭ����һ��
		MaxSize = MaxSize / 2;    //�����Ա�ռ���С�޸�Ϊ�µĳ���
	}
	//�������ʾɾ���ɹ�
	return  true;
}

void List::SortList() {       //��L�е�����Ԫ�����°�������������
	int i, j;
	ElemType x;
	for (i = 1; i<size; i++) {   //��ѭ��n-1��
		x = list[i];          //��������еĵ�1��Ԫ���ݴ�x
		for (j = i - 1; j >= 0; j--)    //��ǰ˳����бȽϺ��ƶ�
			if (x<list[j]) list[j + 1] = list[j];
			else break;
			list[j + 1] = x;         //��xд�뵽�Ѿ��ճ���j+1λ��
	}
}

