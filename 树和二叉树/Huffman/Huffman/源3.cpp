//�д��Ľ���
#include<iostream>
#include<string>
using namespace std;
struct HuffmanNode
{
	int weight;
	int parent;
	int leftchild;
	int rightchild;
};
typedef struct 
{
	char c;
	int bits[20];
	int index;
}CodeNode,*CodeNoding;
HuffmanNode* Intial(int n, CodeNoding &codes)
{
	int m = 2 * n - 1;
	HuffmanNode *node;
	node = new HuffmanNode[m];//����2n-1�����

	for (int i = 0; i < m; i++)
	{
		
		//��ʼ����־λ
		node[i].leftchild = -1;
		node[i].parent = -1;
		node[i].rightchild = -1;
		node[i].weight = -1; 
		
	}

	return node;
}
bool SearchMin(HuffmanNode *&node,int m,int &min,int &mins)
{


	int maxtemp, temp, stemp;
	maxtemp = -1;
	for (int i = 0; i < m; i++)
	{
		if (maxtemp >= node[i].weight)
			maxtemp = node[i].weight;
	}
	temp = maxtemp;
	stemp = maxtemp;
	for (int i = 0; i <m; i++)
	{
		if (node[temp].weight >= node[i].weight&&node[i].parent==-1)
			temp = i;
	}
	for (int i = 0; i <m; i++)
	{
		if (i != temp)
		{
			if (node[stemp].weight >= node[i].weight&&node[i].parent == -1)
			{

				stemp = i;
			}
		}
	}
	
    if (temp== min&&stemp == mins)
		return false;
	else
	{
		min = temp;
		mins = stemp;
		return true;
	}
}
void HuffmanCoding(HuffmanNode *Node, int n, CodeNode *&Code)
{
	//Ϊʲô���������ڴ�й¶������
	  for (int i = 0; i < n; i++)
	{

	for (int j = 0; j < 20; j++)
	Code[i].bits[j] =-1;
	}
	//�϶���Ҷ�ӽڵ�-����
	for (int i = 0; i < n; i++)
	{
		
		int tempparent = i;
		int temps = i;
		Code[i].index = 0;
		while (Node[temps].parent != -1)
		{
			
			tempparent = Node[temps].parent;
			if (Node[tempparent].leftchild == temps)
			{
			
				Code[i].bits[Code[i].index] = 1;
				Code[i].index++;
				
			}
			else
			{
				Code[i].bits[Code[i].index] = 0;
				Code[i].index++;
			}

			temps = tempparent;
		}
	}
	
	

}
//����������������
void Huffman(CodeNode *&code)
{
	int n = 0;
	cout << "������Ҫ����ĸ���"<<endl;
	cin >> n;
	//��ʼ��
   HuffmanNode *node=Intial(n,code);
   cout << "���������ַ����ƺ�Ȩ��" << endl;
   for (int i = 0; i < n; i++)
   {
	   cin >> code[i].c;
	   cin >> node[i].weight;
   }
 
   int min =-1; int mins =-1;
   for (int i = n; i <2 * n - 1; i++)
   {
	   if (SearchMin(node, i, min, mins) == true)
	   {
		   node[i].weight = node[min].weight +node[mins].weight;
		   node[min].parent = i;
		   node[mins].parent = i;
		   node[i].leftchild = min;
		   node[i].rightchild = mins;
	   }
   }
   for (int i = 0; i < 2 * n - 1;i++)
   {
	   cout << "Ȩ��" <<node[i].weight<< "  ���ڵ�" << node[i].parent << "����"
		   << node[i].leftchild << "�Һ���"
		   << node[i].rightchild << endl; 

   }
   HuffmanCoding(node, n, code);
   for (int i = 0; i < n; i++)
   {
	   cout << code[i].c<<endl;
	   for (int j = code[i].index - 1; j >= 0; j--)
		   cout << code[i].bits[j];
		   cout << endl;
   }

	  

}

void main()
{
	CodeNode *code=new CodeNode;
	Huffman(code);
	system("pause");
	
}