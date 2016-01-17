//����������������������ķ�㷨
#include<iostream>
#include<string>
#include<queue>
#include<stack>
#define   Maxs 20;
using namespace std;
typedef struct node
{
	int adjvect;
	int cost;
	struct node *next;
}EdgeNode;
typedef struct
{
	int vertex;
	EdgeNode *firstedge;
}VertexNode;
typedef struct
{
	VertexNode vexlist[20];
	int n; int e;

}AdjGraph;
bool visited[20];//���ʱ��
int dfn[20];//�����������
int  counts= 1;
void Create(AdjGraph &G)
{
	int tail, head,weight;
	cout << "���붥��ͱ߸���" << endl;
	cin >> G.n >> G.e;
	cout << "���붥����" << endl;
	for (int i = 0; i < G.n; i++)
	{
		cin >> G.vexlist[i].vertex;
		G.vexlist[i].firstedge = NULL;
	}
	cout << "����߹�ϵ" << endl;
	for (int i = 0; i < G.e; i++)
	{
		cin >> tail >> head>>weight;
		EdgeNode *p = new EdgeNode;
		p->adjvect = head; 
		p->cost = weight;
		p->next = G.vexlist[tail].firstedge;
		G.vexlist[tail].firstedge = p;
	}
}
//�������-�ݹ��㷨
void DFSI(AdjGraph &G, int i)
{
	EdgeNode *p;
	cout << G.vexlist[i].vertex;
	visited[i] = true;
	dfn[i] = counts++;//�������ûʲô�ð�
	p = G.vexlist[i].firstedge;
	while (p)
	{
		if (!visited[p->adjvect])
			DFSI(G, p->adjvect);
		p = p->next;
	}

}
//������������ķǵݹ��㷨
void DFSIX(AdjGraph &G, int k)
{
	EdgeNode *p; int i;
	stack<int> s;
	//cout << G.vexlist[k].vertex;
	visited[k] = true;
	s.push(k);
	//while (!s.empty())
	//{
	//	i = s.top();
	//	s.pop();
	//	p = G.vexlist[i].firstedge;
	//	while (p)
	//	{
	//		//�������Ǵ�ģ����ظ��˹����������
	//		if (visited[p->adjvect] == false)
	//		{
	//			cout << G.vexlist[p->adjvect].vertex;
	//			s.push(p->adjvect);
	//			visited[p->adjvect] = true;
	//			
	//		}
	//		p = p->next;
	//		
	//	}
	//	
	//
	//	
	//}
	while (!s.empty())
	{
		i = s.top();
		p = G.vexlist[i].firstedge;
		cout << G.vexlist[i].vertex;
		s.pop();
		while (p)
		{
			if (!visited[p->adjvect])
			{
				
				visited[p->adjvect] = true;
				s.push(p->adjvect);
			}

			p = p->next;
		}
	  
	}


}
//�����������
void BFSX(AdjGraph &G,int k)
{
	int i; EdgeNode *p; queue<int> yQ;
	cout << G.vexlist[k].vertex; visited[k] = true;
	yQ.push(k);
	while (!(yQ.empty()))
	{
		i =yQ.front();//��ȡ��ͷԪ�����
		yQ.pop();
		p = G.vexlist[i].firstedge;//��ȡԪ�صĵ�һ�����
		while (p)
		{
			if (!visited[p->adjvect])
			{

				cout << G.vexlist[p->adjvect].vertex;
				visited[p->adjvect] = true;
				yQ.push(p->adjvect);
			}
			p = p->next;

		}

	}
}
//����ķ�㷨����-��Ϊ�ڽӾ���
void PrimHelp(int ** &change_int, EdgeNode *p, AdjGraph &G)
{
	for (int i = 0; i < G.n; i++)
	{
	/*bool visiteTemp[20];*/
	p = G.vexlist[i].firstedge;
	while (p)
	{
		/*if (!visiteTemp[p->adjvect])
		{*/
			change_int[i][p->adjvect] = 1;
			/*visiteTemp[p->adjvect] = true;*/
			
	/*	}*/
		p = p->next;
	
	};
}
}
//����ķ�㷨,�ӵ�K����ʼ
void Prim(AdjGraph &G,int k)
{
	

	//int lowcost[20];//��СȨֵ
	//int adjvex[19];//��С��
	int **change_int;
	EdgeNode *p=G.vexlist[k].firstedge;
	PrimHelp(change_int, p, G);
	for (int i = 0; i < G.n; i++)
	{
		for (int j= 0; j < G.n; j++)
		{
			cout << change_int[i][j];
		}
		cout << endl;
	}
	

}
void DFSTrawerse(AdjGraph &G)
{
	
	for (int i = 0; i < G.n; i++)
		visited[i] = false;
	for (int i = 0; i < G.n; i++)
	{
		if (!visited[i])
			DFSIX(G, i);//�����������ж�ͼ�Ƿ���ͨ
	}

}
//void main()
//{
//	AdjGraph G;
//	Create(G);
//	DFSTrawerse(G);
//	/*Prim(G, 0);*/
//}