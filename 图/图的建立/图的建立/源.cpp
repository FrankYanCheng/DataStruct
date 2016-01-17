//深度搜索、广度搜索、普里姆算法
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
bool visited[20];//访问标记
int dfn[20];//顶点的先深编号
int  counts= 1;
void Create(AdjGraph &G)
{
	int tail, head,weight;
	cout << "输入顶点和边个数" << endl;
	cin >> G.n >> G.e;
	cout << "输入顶点编号" << endl;
	for (int i = 0; i < G.n; i++)
	{
		cin >> G.vexlist[i].vertex;
		G.vexlist[i].firstedge = NULL;
	}
	cout << "输入边关系" << endl;
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
//深度搜索-递归算法
void DFSI(AdjGraph &G, int i)
{
	EdgeNode *p;
	cout << G.vexlist[i].vertex;
	visited[i] = true;
	dfn[i] = counts++;//这个东西没什么用啊
	p = G.vexlist[i].firstedge;
	while (p)
	{
		if (!visited[p->adjvect])
			DFSI(G, p->adjvect);
		p = p->next;
	}

}
//深度优先搜索的非递归算法
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
	//		//这样做是错的，又重复了广度优先搜索
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
//广度优先搜索
void BFSX(AdjGraph &G,int k)
{
	int i; EdgeNode *p; queue<int> yQ;
	cout << G.vexlist[k].vertex; visited[k] = true;
	yQ.push(k);
	while (!(yQ.empty()))
	{
		i =yQ.front();//获取对头元素序号
		yQ.pop();
		p = G.vexlist[i].firstedge;//获取元素的第一个结点
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
//普里姆算法帮助-变为邻接矩阵
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
//普里姆算法,从第K个开始
void Prim(AdjGraph &G,int k)
{
	

	//int lowcost[20];//最小权值
	//int adjvex[19];//最小边
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
			DFSIX(G, i);//可以在这里判断图是否联通
	}

}
//void main()
//{
//	AdjGraph G;
//	Create(G);
//	DFSTrawerse(G);
//	/*Prim(G, 0);*/
//}