//��³�տ����㷨
#include<iostream>
#include<string>
using namespace std;
typedef struct edge
{
	int begin, end, weight;

}Edge;

void Sort(Edge *&edges,int n)
{
	edge temp;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (edges[i].weight >edges[j].weight)
			{
				temp = edges[i];
				edges[i]= edges[j];
				edges[j] = temp;
			}
		}
	}

}
//�Ҹ��ڵ�
int find(int father[], int v)
{
	int f = v;
	while (father[f] > 0)
		f = father[f];
	return f;
}
void Kraskal(Edge edge[],int e,int n)
{
	int father[20];
	int bnf,end;
	for (int i = 0; i < e; i++)
	{
		father[i] = 0;
	}
	Sort(edge, e);
	for (int i = 0; i < e; i++)
	{
		cout << edge[i].weight << endl;
		bnf = find(father, edge[i].begin);
		end = find(father, edge[i].end);
		if (bnf != end)
		{
			if (father[edge[i].begin] == 0)
			{
				father[edge[i].begin] = edge[i].end;

			}
			if (father[edge[i].begin] != 0 && father[edge[i].end]==0)
			{
				father[edge[i].end] = edge[i].begin;	
				
			}
		}
	}

 
	int temp = 0;
	for (int i = 0; i < n-1; i++)
		cout << i << "," << father[i] << endl;



}
//void main()
//{
//	
//	int e,n;
//	cout << "����ߵĽ����" << endl;
//	cin >> n;
//	cout << "����ߵ�����" << endl;
//	cin >> e;
//	cout << "����߶�Ӧ����ʼ�ڵ���ս�㣬��0��n" << endl;
//	Edge edge[100];
//	for (int i = 0; i < e; i++)
//	{
//		cout << "��" << i << "��" << endl; 
//		cout << "��ʼ�ڵ�" << endl;
//		cin >> edge[i].begin;
//		cout << "�սڵ�" << endl;
//		cin >> edge[i].end;
//		cout << "Ȩ��" << endl;
//		cin >> edge[i].weight;
//	}
//	Kraskal(edge, e,n);
//}