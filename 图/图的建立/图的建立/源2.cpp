//迪克斯特算法
#include<iostream>
#include<string>
using namespace std;
int MinCost(int *D, bool *&S,int n)
{
	int temp = 10000;
	int w = 2;
	for (int  i = 1; i < n; i++)
	{
		if (!S[i] && D[i] < temp)
		{
			temp = D[i];
			w = i;
		}
	}
	return w;
}
void Dijkstra(int C[200][200], int D[100], int P[100], bool S[100],int n)
{
	int w = -1; int sum = 10000;
	for (int i = 0; i < n; i++)
	{
		D[i] = C[0][i]; S[i] = false;
		P[i] = 0;
	}
	S[0] = true;
	for (int i = 0; i < n; i++)
	{   
		w = MinCost(D, S,n);
		cout << w << endl;
		S[w] = true;
		for (int j = 1; j < n; j++)
		{
			if (S[j] != true)
			{
				if (C[w][j] != 10000)
				sum = D[w] + C[w][j];
				if (sum < D[j])
				{ 
				
					D[j] = sum; P[j] = w;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << P[i] << "------" << endl;
	}
	
}
void main()
{
	int Graphics[200][200];
	int n;
	cout << "输入顶点个数" << endl;
	cin >> n;
	int temps = 0;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> temps;
			if (temps == 0)
				Graphics[i][j] = 10000;
			else
			 Graphics[i][j]=temps;
		}
	}
	int D[100]; bool S[100]; int P[100];
	Dijkstra(Graphics, D, P, S, n);


}