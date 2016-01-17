//有待改进啊
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
	node = new HuffmanNode[m];//生成2n-1个结点

	for (int i = 0; i < m; i++)
	{
		
		//初始化标志位
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
	//为什么这里会出现内存泄露的问题
	  for (int i = 0; i < n; i++)
	{

	for (int j = 0; j < 20; j++)
	Code[i].bits[j] =-1;
	}
	//肯定是叶子节点-编码
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
//哈夫曼编码主方法
void Huffman(CodeNode *&code)
{
	int n = 0;
	cout << "输入需要编码的个数"<<endl;
	cin >> n;
	//初始化
   HuffmanNode *node=Intial(n,code);
   cout << "输入编码的字符名称和权重" << endl;
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
	   cout << "权重" <<node[i].weight<< "  父节点" << node[i].parent << "左孩子"
		   << node[i].leftchild << "右孩子"
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