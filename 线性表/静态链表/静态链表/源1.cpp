//#include<iostream>
//#include<string>
//
//using namespace std;
//const int maxSize = 100;
//typedef struct ListNode
//{
//	string data;
//	int cur;
//} StaticList[maxSize];
//void Intial(StaticList &list)
//{
//	for (int i = 0; i < maxSize - 1; i++)
//	{
//		list[i].cur = i + 1;
//	}
//	list[maxSize].cur=0;
//	
//}
//void Add(StaticList &list, int S, string data)
//{
//		int counter = 1;
//		while (list[counter].cur!=0&&list[counter].data!="")
//		{
//			counter++;
//		}
//		list[counter].cur = S;
//		list[counter].data = data;
//		list[S - 1].cur = counter ;
//	
//}	
//void deletes(StaticList &list, int S)
//{
//	int counter = 0;
//	while (list[counter].cur!= S)
//	{
//		list[counter].cur = list[S].cur;
//		counter++;
//	};
//}
//void Prints(StaticList &list)
//{
//     int  i= 0;
//	 while (list[i].cur!=0)
//	 {
//		 cout << list[list[i].cur].data<<endl;
//		 i++;
//	 }
//}
//
//void main()
//{
//	StaticList list;
//	Intial(list);
//	Add(list, 1, "100");
//	Add(list, 1, "Hello World");
//	Prints(list);
//}