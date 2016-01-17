#include <iostream>
#include <stdlib.h>
#include <stdarg.h>
#include "../Head.h"

using namespace std;
//�����˳��洢��ʾ��ʵ��

const int MAX_ARRAY_DIM=8;
typedef int ElemType ;

typedef struct Array{
    ElemType *base; //����Ԫ�ػ�ַ����InitArray()����
    int dim;  //����ά��
    int *bounds;    //����ά���ַ����InitArray()����
    int *constants;    //����ӳ����������ַ����InitArray()����
    Array(){
        base=NULL;
        dim=0;
        bounds=NULL;
        constants=NULL;
    }
}Array;

Status InitArray(Array &A,int dim,...){   //ʡ�Ժ�Ϊint�͵ĸ�ά�糤��
    int elemtotal;  //Ԫ������
    //������dim�͸�ά���ȺϷ���������Ӧ������A��������OK
    if(dim<1||dim>MAX_ARRAY_DIM) return ERROR;
    A.dim=dim;
    A.bounds=(int *)malloc(dim*sizeof(int));
    if(!A.bounds) exit(OVERFLOW);
    //����ά���ȺϷ��������A.bounds,�����A��Ԫ������elemtotal
    elemtotal=1;
    va_list ap;  //stdarg.h �е�����
    va_start(ap,dim);
    for(int i=0;i<dim;++i){
        A.bounds[i]=va_arg(ap,int);
        if(A.bounds[i]<0) return ERROR;
        elemtotal*=A.bounds[i];
    }
    va_end(ap);
    A.base=(ElemType*)malloc(elemtotal*sizeof(ElemType));
    if(!A.base) exit(OVERFLOW);
    //��ӳ�����ĳ���ci,������A��bounds[i-1],i=1,...dim
    A.constants=(int *) malloc(dim*sizeof(int));
    if(!A.constants) exit(OVERFLOW);
    A.constants[dim-1]=1;  //L=1,ָ���������Ԫ�صĴ�СΪ��λ
    for(int i=dim-2;i>=0;--i)
        A.constants[i]=A.bounds[i+1]*A.constants[i+1];
    return OK;
}

Status DestroyArray(Array & A){
    //��������A
    if(!A.base) return ERROR;
    free(A.base); A.base=NULL;

    if(!A.bounds) return ERROR;
    free(A.bounds); A.bounds=NULL;

    if(!A.constants) return ERROR;
    free(A.constants); A.constants=NULL;

    return OK;
}

Status Locate(Array A,va_list ap,int & off){
    //��apָʾ�ĸ��±�ֵ�Ϸ����������Ԫ����A�е���Ե�ַoff
    off=0;
    int ind;
    for(int i=0;i<A.dim;++i){
        ind=va_arg(ap,int);
        if(ind<0||ind>A.bounds[i]) return OVERFLOW;
        off+=A.constants[i]*ind;
    }
    return OK;
}

Status Value(Array A,ElemType &e,...){
    //A��nά���飬eΪԪ�ر����������n���±�ֵ
    //����ά�±겻���磬��e��ֵΪ��ָ����A���±�ֵ��������OK
    int off;//��Ե�ַ
    int result;
    va_list ap;
    va_start(ap,e);
    if((result=Locate(A,ap,off))<=0) return result;
    e=*(A.base+off);
    return OK;
}

Status Assign(Array & A,ElemType e,...){
    //A��nά���飬eΪԪ�ر����������n���±�ֵ
    //����ά�±겻���磬���e������ָ����A��Ԫ�أ�������OK
    int off;//��Ե�ַ
    int result;
    va_list ap;
    va_start(ap,e);
    if((result=Locate(A,ap,off))<=0) return result;
    *(A.base+off)=e;
    return OK;
}

int main()
{
    Array a;
    InitArray(a,3,3,3,3);//����һ��3*3*3����ά����
    Assign(a,5,2,2,2);
    int value;
    Value(a,value,2,2,2);
    cout<<value<<endl;
    DestroyArray(a);
    return 0;
}