//搜索子串的普通方法
#include<string>
#include<iostream>
using namespace std;
int GetLength(char *a)
{
	int i=0;
	while(*a!='\0')
	{
		i++;a++;
	}
	return i;
	}
int indexs(char *a,char *b,int pos)
{
	int sex=0;
    int aLength=GetLength(a);
	int bLength=GetLength(b);
	int i=pos;int j=1;
	while(i<aLength&&j<bLength)
	{
         if(a[i]==b[j])
		 {
			 i++;
			 j++;
		 }
		 else
		 {
			 i=i-j+2;
			 j=1;
		 }
		sex++;
	}
	cout<<"搜索了"<<sex<<"次"<<endl;
	 if(j>=bLength)
			 return i-bLength;
	 else
		 return 0;
    
}

void main()
{
	char a[]={'H','E','L','L','O','\0'};
	char b[]={'W','O','R','L','D','z','H','E','L','L','H','E','L','L','O','\0'};
	char *a1=a;
	char *b1=b;
	cout<<indexs(b1,a1,0);
	//这种搜索方法的缺陷在于当有很大程度上的重复时,重复判断的几率非常大
}