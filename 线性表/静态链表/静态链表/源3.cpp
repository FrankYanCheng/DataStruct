//    #include <stdio.h>  
//    #include <stdlib.h>  
//#include<iostream>
//using namespace std;
//    #define listsize 10  
//    typedef struct  
//    {  
//     int data;  
//     int cur;  
//    }slinknode;  
//    typedef struct  
//    {  
//      slinknode list[listsize];  
//      int av;  
//    }slinklist;  
//    void initslist(slinklist *L)  
//    {  
//        int i;  
//          
//        for(i=0;i<listsize -1;i++)  
//       
//        (*L).list[i].cur = i+1;  
//           
//        (*L).list[listsize-1].cur = 0;  
//        (*L).av = 1;  
//    }  
//    int  assignode(slinklist &L)  
//    {  
//        int i;  
//        i = L.av;//����������  
//        L.av = L.list[i].cur;  
//        return i;  
//    }  
//    /*void freenode (slinklist *L,int pos) 
//    { 
//      //���нڵ��Ϊ���������еĽ�� 
//        L.list[pos].cur  = L.list[.cur; 
//        L.av. = pos;//���뵽������ 
//    } 
//    */  
//    void insert(slinklist *L,int i,int e)  
//    {  
//        int j,k,x;  
//        k = (*L).av;//kΪ���ý��  
//        (*L).av = (*L).list[k].cur;  
//        (*L).list[k].data = e;  
//        j = (*L).list[0].cur;//j����  
//        for(x=1;x<i-1;x++)  
//            j =(*L).list[j].cur;  
//        (*L).list[k].cur = (*L).list[j].cur;  
//        (*L).list[j].cur = k;  
//          
//        //------------------------------------  
//        //k->next = j->next;  
//        //j->next = k;  
//        //-----------------------------------  
//    }  
//    void del(slinklist *L,int i,char &e)  
//    {  
//        int j,k,x;  
//        j = (*L).list[0].cur;  
//        for(x=1;x<i-1;x++)  
//          j =(*L).list[j].cur;  
//          
//        k = (*L).list[j].cur;  
//        (*L).list[j].cur = (*L).list[k].cur;  
//        //freenode (&L,k);  
//        //------------------------------------  
//        //j->next = k->next;  
//        //  
//        //-----------------------------------  
//        (*L).list[k].cur = (*L).av;  
//        e= (*L).list[k].data;  
//         (*L).av = k;  
//        //���뵽���ý����  
//    }  
//    void printDlist(slinklist L,int n)  
//    {  
//    int j,k;  
//    k = (L).list[0].cur;  
//    for(j=1;j<=n;j++)  
//    {  
//       printf("%3c",(L).list[k]);  
//      k = (L).list[k].cur;  
//    }  
//    }  
//    void main()  
//    {  
//        slinklist L;  
//        int i,pos;  
//        int len;  
//        char e;  
//        char a[] = {'A','B','c','D','E','F','H'};  
//        len = sizeof(a) /sizeof(a[0]);//���ĳ���  
//       initslist(&L);  
//       for(i=1;i<len+1;i++)  
//       insert(&L,i,a[i-1]);  
//         
//       printf("��̬�����е�Ԫ��Ϊ\n");  
//       printDlist(L,len);  
//      printf("\n����������Ԫ�ؼ�λ��\n");  
//       scanf("%c",&e);  
//       getchar();  
//       scanf("%d",&pos);  
//       getchar();  
//       insert(&L,pos,e);  
//         
//       printDlist(L,len+1);  
//       
//         printf("\n������ɾ����λ�ü�Ԫ��\n");  
//        
//       scanf("%d",&pos);  
//       getchar();  
//        scanf("%d",&e);  
//       getchar();  
//       del(&L,pos,e);  
//       printDlist(L,len-1);  
//       
//    }  