////���������㷨
//#include<iostream>
//using namespace std;
//const int n = 5;
//const int m = 2 * n - 1;
//const int float_max = 20;
//typedef int datatype;
//typedef struct
//{
//	float weight;			//����Ȩ��
//	int parent;				//����˫���������е��±�
//	int lchild, rchild;		//������������
//}	nodetype;				//�������
//typedef nodetype hftree[m]; //�����������ͣ������0�ŵ�Ԫ��ʼʹ��
//hftree T;					//������������
//
////���������Ĺ���
//void huffman(hftree T)
//{
//	int i, j, p1, p2;
//	float small1, small2;
//	for (i = 0; i<n; i++)        //��ʼ��
//	{
//		T[i].parent = -1;		//��˫�ף���Ϊ����㣬��δ�ϲ���
//		T[i].lchild = T[i].rchild = -1;//���Һ���ָ����Ϊ-1
//	}
//	for (i = 0; i<n; i++)
//	{
//		cin >> T[i].weight;   //����n��Ҷ�ӵ�Ȩ
//	}
//	for (i = n; i<m; i++)		//����n-1�κϲ�������n-1���½��
//	{
//		p1 = p2 = -1;
//		small1 = small2 = float_max;	//float_maxΪfloat���͵����ֵ
//		for (j = 0; j <= i - 1; j++)
//		{
//			if (T[j].parent != -1) continue;//�������Ѻϲ����ĵ�
//			if (T[j].weight<small1)			//�޸���СȨ�ʹ�СȨ��λ��
//			{
//				small2 = small1;
//				small1 = T[j].weight;
//				p2 = p1;
//				p1 = j;
//			}
//			else if (T[j].weight<small2)		//�޸Ĵ�СȨ��λ��
//			{
//				small2 = T[j].weight;
//				p2 = j;
//			}
//		}
//		T[p1].parent = T[p2].parent = i;		//�¸�
//		T[i].parent = -1;
//		T[i].lchild = p1;
//		T[i].rchild = p2;
//		T[i].weight = small1 + small2;			//�½���ȨֵΪ��СȨ���СȨ֮��
//	}
//}
//
//int main()
//{
//	hftree T;
//	cout << "          ��ӭ���ԣ�������   " << endl;
//	cout << "----------���Կ�ʼ-----------" << endl;
//	cout << "���ȵ��ù�����������ĺ�����huffman" << endl;
//	cout << "���±�˳������Ҷ�ӵ�Ȩ��:" << endl;
//	cout << " 0  1  2  3  4  5  6  7  8 " << endl;
//	huffman(T);
//	cout << "����ϲ���Ĺ������������н�㣺" << endl;
//	cout << " 0  1  2  3  4  5  6  7  8 " << endl;
//	for (int i = 0; i<m; i++)
//	{
//		cout << T[i].weight << "  ";
//	}
//	system("pause");
//	return 0;
//}