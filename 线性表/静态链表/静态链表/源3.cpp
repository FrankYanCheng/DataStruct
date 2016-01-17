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
//        i = L.av;//备用链表结点  
//        L.av = L.list[i].cur;  
//        return i;  
//    }  
//    /*void freenode (slinklist *L,int pos) 
//    { 
//      //空闲节点成为备用链表中的结点 
//        L.list[pos].cur  = L.list[.cur; 
//        L.av. = pos;//插入到备用里 
//    } 
//    */  
//    void insert(slinklist *L,int i,int e)  
//    {  
//        int j,k,x;  
//        k = (*L).av;//k为备用结点  
//        (*L).av = (*L).list[k].cur;  
//        (*L).list[k].data = e;  
//        j = (*L).list[0].cur;//j遍历  
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
//        //插入到备用结点中  
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
//        len = sizeof(a) /sizeof(a[0]);//求表的长度  
//       initslist(&L);  
//       for(i=1;i<len+1;i++)  
//       insert(&L,i,a[i-1]);  
//         
//       printf("静态链表中的元素为\n");  
//       printDlist(L,len);  
//      printf("\n请输入插入的元素及位置\n");  
//       scanf("%c",&e);  
//       getchar();  
//       scanf("%d",&pos);  
//       getchar();  
//       insert(&L,pos,e);  
//         
//       printDlist(L,len+1);  
//       
//         printf("\n请输入删除的位置及元素\n");  
//        
//       scanf("%d",&pos);  
//       getchar();  
//        scanf("%d",&e);  
//       getchar();  
//       del(&L,pos,e);  
//       printDlist(L,len-1);  
//       
//    }  