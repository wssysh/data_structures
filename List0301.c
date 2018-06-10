#include <stdio.h>

/*线性表的顺序储存结构类型描述*/
#define MAXSIZE 20 //储存空间初始分配量
typedef int ElemType; //假设元素类型为 int
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} SqList;       //静态分配

/*
#define INITSIZE 20
typedef struct
{
    ElemType *data;     //指示动态分配数组的指针
    int MAXSIZE,length; //数组的最大容量和当前个数
}SeqList;               //动态分配数组顺序表的类型定义
*/
//L.data=(ElemType*)malloc(sizeof(ElemType)*INITSIZE;
//L.data=new ElemType[INITSIZE];

/*获取元素操作
  初始条件顺序线性表L存在1<=i<=ListLength(L)
  GetElem(L, i, ElemType &e) //用e获取第i位的元素的值*/
#define OK 1
#define ERROR 0
#define TURE 0
#define FALSE 0
typedef int Status      //Status函数类型，其值为状态代码eg：OK
Status GetElem(SqList, int i, ElemType *e)
{
    if(L.length == 0||i<1||i>L.length)
        return ERROR;
    *e = L.data[i-1];
    return OK;
}
/*ListInsert(&L, i, e) //插入操作
初始条件：顺序线性表L已存在，1<=i<=ListLength(L)
操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1*/
Status ListInsert(SqList *L, int i, ElemType e)
{
    int k;
    if(L.length==MAXSIZE)
        return ERROR;       //线性表已满
    if(i<1||i>L.length+1)
        return ERROR;       //i不在范围内
    if(i<=L->length)
    {
        for(k=L->length-1;k>=i-1;k--)
            L->data[k+1]=L.data[k];     //插入数据不在表尾
    }
    L.data[i-1]=e;
    L->length++;
    return OK;
}

/*	ListDelete(&L, i, &e) //删除操作，并用e返回元素的值
初始条件：顺序线性表L已存在，1<=i<=ListLength(L)
操作结果：删除L中的第i个数据元素，并用e返回其值，L的长度减1*/
Status ListDelete(SqList *L, int i, ElemType *e)
{
    int k;
    if(L.length==0)
        return ERROR;   //线性表为空
    if(i<1||i>L.length)
        return ERROR;   //删除位置不正确
    *e = L.data[i-1];
    if(i<L.length)
    {
        for(k=i;k<L.length;k++)
        {
            L.data[k-1]=L.data[k];
        }
        L.length--;
        return OK;
    }
}







