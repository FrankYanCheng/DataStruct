#include <iostream>
#include <stdlib.h>
#include <stdarg.h>
#include "../Head.h"

using namespace std;
//数组的顺序存储表示和实现

const int MAX_ARRAY_DIM=8;
typedef int ElemType ;

typedef struct Array{
    ElemType *base; //数组元素基址，由InitArray()分配
    int dim;  //数组维数
    int *bounds;    //数组维界基址，由InitArray()分配
    int *constants;    //数组映像函数常量基址，由InitArray()分配
    Array(){
        base=NULL;
        dim=0;
        bounds=NULL;
        constants=NULL;
    }
}Array;

Status InitArray(Array &A,int dim,...){   //省略号为int型的各维界长度
    int elemtotal;  //元素总数
    //若数组dim和各维长度合法，则构造相应的数组A，并返回OK
    if(dim<1||dim>MAX_ARRAY_DIM) return ERROR;
    A.dim=dim;
    A.bounds=(int *)malloc(dim*sizeof(int));
    if(!A.bounds) exit(OVERFLOW);
    //若各维长度合法，则存入A.bounds,并求出A的元素总数elemtotal
    elemtotal=1;
    va_list ap;  //stdarg.h 中的类型
    va_start(ap,dim);
    for(int i=0;i<dim;++i){
        A.bounds[i]=va_arg(ap,int);
        if(A.bounds[i]<0) return ERROR;
        elemtotal*=A.bounds[i];
    }
    va_end(ap);
    A.base=(ElemType*)malloc(elemtotal*sizeof(ElemType));
    if(!A.base) exit(OVERFLOW);
    //求映像函数的常数ci,并存入A。bounds[i-1],i=1,...dim
    A.constants=(int *) malloc(dim*sizeof(int));
    if(!A.constants) exit(OVERFLOW);
    A.constants[dim-1]=1;  //L=1,指针的增减以元素的大小为单位
    for(int i=dim-2;i>=0;--i)
        A.constants[i]=A.bounds[i+1]*A.constants[i+1];
    return OK;
}

Status DestroyArray(Array & A){
    //销毁数组A
    if(!A.base) return ERROR;
    free(A.base); A.base=NULL;

    if(!A.bounds) return ERROR;
    free(A.bounds); A.bounds=NULL;

    if(!A.constants) return ERROR;
    free(A.constants); A.constants=NULL;

    return OK;
}

Status Locate(Array A,va_list ap,int & off){
    //若ap指示的各下标值合法，则求出该元素在A中的相对地址off
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
    //A是n维数组，e为元素变量，随后是n个下标值
    //若各维下标不超界，则e赋值为所指定的A的下标值，并返回OK
    int off;//相对地址
    int result;
    va_list ap;
    va_start(ap,e);
    if((result=Locate(A,ap,off))<=0) return result;
    e=*(A.base+off);
    return OK;
}

Status Assign(Array & A,ElemType e,...){
    //A是n维数组，e为元素变量，随后是n个下标值
    //若各维下标不超界，则把e赋给所指定的A的元素，并返回OK
    int off;//相对地址
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
    InitArray(a,3,3,3,3);//构造一个3*3*3的三维数组
    Assign(a,5,2,2,2);
    int value;
    Value(a,value,2,2,2);
    cout<<value<<endl;
    DestroyArray(a);
    return 0;
}