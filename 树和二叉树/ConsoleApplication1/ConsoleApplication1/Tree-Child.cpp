//���ں��ӱ�ʾ������ʽ�ṹ
//�����������
#include<iostream>
#include<string>
using namespace std;
typedef char ElementData;
typedef struct CTNode
{
	CTNode *next;
	ElementData data;

}CTNode,*CTNode_part;
void PreOrder(CTNode_part nodelinks,CTNode_part original,int n)
{
	if (nodelinks!= NULL&&nodelinks->data!=NULL)
	{
		int counts = 0;
		CTNode_part templinks = original;
		while (templinks->data != nodelinks->data)
		{
			counts++;
			if (counts == n)
			{
				cout << nodelinks->data << endl;
				break;
			}
			else
			{
				templinks++;
			}
			
		} 

		PreOrder(nodelinks->next, original,n);
	}
}
void ChildAdd(CTNode_part &node)
{
	cout << "������" << node->data << "�ĺ��ӽ��" << "���û������#����" << endl;
	ElementData data;
	CTNode_part temp = node;
	while (temp->next!= NULL)
		temp = temp->next;
	while (cin >> data)
	{
		if (data != '#')
		{
			CTNode_part nodes = (CTNode_part)malloc(sizeof(CTNode));
			nodes->data = data;
			temp->next = nodes;
		}
		else
			break;
	}
}


//void main()
//{
//	cout <<"����Ԫ�ظ���" <<endl;
//	int n=0;
//	cin >> n;
//	CTNode *nodelinks=new CTNode[n];
//	//��ʱ���
//	CTNode *templink = nodelinks;
//	ElementData data;
//	for (int i = 0; i < n; i++)
//	{
//		cout << "������" << i << endl;
//		cin >> data;
//		templink->data= data;
//		ChildAdd(templink);
//		*templink++;
//	}
//	PreOrder(nodelinks->next, nodelinks, n);
//	
//
//
//
//
//}