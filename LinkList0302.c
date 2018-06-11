#include <stdio.h>
#define OK 1
#define ERROR 0

typedef int ElemType;   //数据元素类型
typedef int Status;     //函数返回状态

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;     //线性表的单链表存储结构

typedef struct Node *LinkList;  //定义LinkList

/*单链表的读取 GetElem(LinkList L, int i, ElemType *e)
初始条件：顺序线性表L已存在，1<=i<=ListLength(L)
操作结果：用e返回L中第i个数据元素的值*/
Ststus GetElem(LinkList L, int i, ElemType *e)
{
    int j=1;        //j为计数器
    LinkList p;     //声明指针p
    p=L->next;      //让p指向链表的第i+1个结点
    while(p&&j<i)   //p不为Null且计数器j还不等于i，循环
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i)
        return ERROR;//第i个结点不存在
    *e=p.data;      //取得第i个结点
    return OK;
}
//最坏情况 时间复杂度为O(n)
