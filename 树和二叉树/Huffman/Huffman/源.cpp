////哈夫曼树算法
//#include<iostream>
//using namespace std;
//const int n = 5;
//const int m = 2 * n - 1;
//const int float_max = 20;
//typedef int datatype;
//typedef struct
//{
//	float weight;			//定义权重
//	int parent;				//定义双亲在向量中的下标
//	int lchild, rchild;		//定义左右子树
//}	nodetype;				//结点类型
//typedef nodetype hftree[m]; //哈夫曼树类型，数组从0号单元开始使用
//hftree T;					//哈夫曼树向量
//
////哈夫曼树的构造
//void huffman(hftree T)
//{
//	int i, j, p1, p2;
//	float small1, small2;
//	for (i = 0; i<n; i++)        //初始化
//	{
//		T[i].parent = -1;		//无双亲，即为根结点，尚未合并过
//		T[i].lchild = T[i].rchild = -1;//左右孩子指针置为-1
//	}
//	for (i = 0; i<n; i++)
//	{
//		cin >> T[i].weight;   //输入n个叶子的权
//	}
//	for (i = n; i<m; i++)		//进行n-1次合并，产生n-1个新结点
//	{
//		p1 = p2 = -1;
//		small1 = small2 = float_max;	//float_max为float类型的最大值
//		for (j = 0; j <= i - 1; j++)
//		{
//			if (T[j].parent != -1) continue;//不考虑已合并过的点
//			if (T[j].weight<small1)			//修改最小权和次小权及位置
//			{
//				small2 = small1;
//				small1 = T[j].weight;
//				p2 = p1;
//				p1 = j;
//			}
//			else if (T[j].weight<small2)		//修改次小权及位置
//			{
//				small2 = T[j].weight;
//				p2 = j;
//			}
//		}
//		T[p1].parent = T[p2].parent = i;		//新根
//		T[i].parent = -1;
//		T[i].lchild = p1;
//		T[i].rchild = p2;
//		T[i].weight = small1 + small2;			//新结点的权值为最小权与次小权之和
//	}
//}
//
//int main()
//{
//	hftree T;
//	cout << "          欢迎测试！！！！   " << endl;
//	cout << "----------测试开始-----------" << endl;
//	cout << "首先调用哈夫曼树构造的函数：huffman" << endl;
//	cout << "按下标顺序输入叶子的权重:" << endl;
//	cout << " 0  1  2  3  4  5  6  7  8 " << endl;
//	huffman(T);
//	cout << "输出合并后的哈夫曼树的所有结点：" << endl;
//	cout << " 0  1  2  3  4  5  6  7  8 " << endl;
//	for (int i = 0; i<m; i++)
//	{
//		cout << T[i].weight << "  ";
//	}
//	system("pause");
//	return 0;
//}