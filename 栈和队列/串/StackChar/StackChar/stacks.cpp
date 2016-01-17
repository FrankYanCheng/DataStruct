#include<iostream>
#include<string>
using namespace std;
typedef struct
{
	char *ch;
	int length;
}HString;
void Intials(HString &T,char *chars)
{
	if(!T.ch)
		free(T.ch);

		int i;
		char *c=chars;
	for(i=0;*c!='\0';c++,i++);
	T.length=i+1;
	    	T.ch=(char*)malloc(i*sizeof(char));
  for(int j=0;j<i;j++)
  {
	  T.ch[j]=chars[j];
  }

}
void Concact(HString &T,HString t1,HString t2)
{
	if(!T.ch)
		free(T.ch);
	T.ch=(char*)malloc((t1.length+t2.length-1)*(sizeof(char)));
	for(int i=0;i<t1.length-1;i++)
		T.ch[i]=t1.ch[i];
	for(int j=0;j<t2.length;j++)
	{
		T.ch[j+t1.length-1]=t2.ch[j];
	}	T.length=t1.length+t2.length-1;
	


}
void prints(HString &T)
{
	cout<<"³¤¶È"<<T.length-1<<endl;
	for(int i=0;i<T.length-1;i++)
     cout<<T.ch[i];
	cout<<"---------------"<<endl;
}
void main()
{
	char c[]={'H','E','L','L','O','\0'};
	char *ct1=c;
	HString Test;
	Intials(Test,ct1);

	char c2[]={'W','O','R','l','D','Q','\0'};
    char *ct2=c2;
		HString Test2;
	Intials(Test2,ct2);

    	HString Test3;
   Concact(Test3,Test,Test2);
  	prints(Test2);
}
