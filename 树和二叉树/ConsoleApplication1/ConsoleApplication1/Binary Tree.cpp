////////���������ʵ��
//////#include<iostream>
//////#include<string>
//////using namespace std;
//////typedef int TElemType;
//////typedef struct BiTNode {
//////	TElemType data;
//////	struct BiNode *lchild, *rchild;
//////}BiNode,*BiTree;
//////void CreateBiTree(BiTree &T,int datas)
//////{
//////  
//////}
//#include<iostream>
//using namespace std;
//struct tree
//{
//	int data;
//	tree *left, *right;
//};
//class Btree
//{
//	static int n;
//	static int m;
//public:
//	tree *root;
//	Btree()
//	{
//		root = NULL;
//	}
//	void create_Btree(int);
//	void Preorder(tree *);                  //�������
//	void inorder(tree *);                   //�������
//	void Postorder(tree *);                 //�������
//	void display1() { Preorder(root); cout << endl; }
//	void display2() { inorder(root); cout << endl; }
//	void display3() { Postorder(root); cout << endl; }
//	int count(tree *);                      //����������ĸ���
//	int findleaf(tree *);                   //�������Ҷ�ӵĸ���
//	int findnode(tree *);                   //��������ж���Ϊ1�Ľ������,���ǵ��������ݽṹʱ������һ����Ŀ
//};
//int Btree::n = 0;
//int Btree::m = 0;
//void Btree::create_Btree(int x)
//{
//	tree *newnode = new tree;
//	newnode->data = x;
//	newnode->right = newnode->left = NULL;
//	if (root == NULL)
//		root = newnode;
//	else
//	{
//		tree *back;
//		tree *current = root;
//		while (current != NULL)
//		{
//			back = current;
//			if (current->data>x)
//				current = current->left;
//			else
//				current = current->right;
//		}
//		if (back->data>x)
//			back->left = newnode;
//		else
//			back->right = newnode;
//	}
//}
//int Btree::count(tree *p)
//{
//	if (p == NULL)
//		return 0;
//	else
//		return count(p->left) + count(p->right) + 1;      //���������˺���Ƕ�׼��ݹ�ķ�����
//}
//void Btree::Preorder(tree *temp)    //������������������������˵ݹ�ķ�����
//{
//	if (temp != NULL)
//	{
//		cout << temp->data << " ";
//		Preorder(temp->left);
//		Preorder(temp->right);
//	}
//}
//void Btree::inorder(tree *temp)      //������������������������˵ݹ�ķ�����
//{
//	if (temp != NULL)
//	{
//		inorder(temp->left);
//		cout << temp->data << " ";
//		inorder(temp->right);
//	}
//}
//void Btree::Postorder(tree *temp)     //���Ǻ�������������������˵ݹ�ķ�����
//{
//	if (temp != NULL)
//	{
//		Postorder(temp->left);
//		Postorder(temp->right);
//		cout << temp->data << " ";
//	}
//}
//int Btree::findleaf(tree *temp)
//{
//	if (temp == NULL)return 0;
//	else
//	{
//		if (temp->left == NULL&&temp->right == NULL)return n += 1;
//		else
//		{
//			findleaf(temp->left);
//			findleaf(temp->right);
//		}
//		return n;
//	}
//}
//int Btree::findnode(tree *temp)
//{
//	if (temp == NULL)return 0;
//	else
//	{
//		if (temp->left != NULL&&temp->right != NULL)
//		{
//			findnode(temp->left);
//			findnode(temp->right);
//		}
//		if (temp->left != NULL&&temp->right == NULL)
//		{
//			m += 1;
//			findnode(temp->left);
//		}
//		if (temp->left == NULL&&temp->right != NULL)
//		{
//			m += 1;
//			findnode(temp->right);
//		}
//	}
//	return m;
//}
//
//
//void main()
//{
//	Btree A;
//	int array[] = { 7,4,2,3,15,35,6,45,55,20,1,14,56,57,58 };
//	int k;
//	k = sizeof(array) / sizeof(array[0]);
//	cout << "�������������˳��: " << endl;
//	for (int i = 0; i<k; i++)
//	{
//		cout << array[i] << " ";
//		A.create_Btree(array[i]);
//	}
//	cout << endl;
//	cout << "�������ڵ������ " << A.count(A.root) << endl;
//	cout << "������Ҷ�Ӹ�����" << A.findleaf(A.root) << endl;
//	cout << "�������ж���Ϊ1�Ľ�������Ϊ��" << A.findnode(A.root) << endl;
//	cout << endl << "�����������: " << endl;
//	A.display1();
//	cout << endl << "�����������: " << endl;
//	A.display2();
//	cout << endl << "�����������: " << endl;
//	A.display3();
//}