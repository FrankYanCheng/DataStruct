//#include<string>
//#include<iostream>
//#include<stdlib.h>
//using namespace std;
//typedef  struct	 Element
//{
//	int data;
//	Element *next;
//}Element, *Links;
//void Intial_Test(Links &l)
//{
//	l = (Links)malloc(sizeof(Element));
//	l->data = 0;
//	l->next = NULL;
//}
//void DestoryLinks(Links &l)
//{
//	Links t,q;
//	q=l->next;
//	while (q)
//	{
//		t = q->next;
//		free(q);
//		q = t;
//	}
//	l->data = 0;
//	l->next = NULL;
//	 
//}
//bool Adding(Links &l,int pos,int value)
//{
//	Links  p = l;
//	int counter=0;
//	if (pos <=-1)
//	{
//		cerr << "Î»ÖÃ´íÎó" << endl;
//	}
//	while (p&&counter<pos-1)
//	{
//	    p=p->next;
//		counter++;
//	}
//	Links q = (Links)malloc(sizeof(Element));
//	q->next = p->next;
//	q->data = value;
//	p->next = q;
//	l->data++;
//	return true;
//
//}
////É¾³ý
//bool Delete(Links &l, int pos)
//{
//	int counter=0;
//	Links q = l;
//	while (q&&counter < pos-1)
//	{
//		q = q->next;
//		counter++;
//	}
//	Links s = q->next;
//	q->next = s->next;
//	free(s);
//	l->data--;
//	return true;
//}
//void main()
//{
//	Links t;
//	Intial_Test(t);
//	Adding(t, 1, 3);
//	Adding(t, 1, 4);
//	Adding(t, 2, 5);
//	Delete(t, 3);
//	DestoryLinks(t);
//	t = t->next;
//	while (t)
//	{
//	cout<<t->data<<endl;
//    t=t->next;
//	}
//}