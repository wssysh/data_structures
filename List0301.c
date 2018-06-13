#include <stdio.h>
//#include <stdlib.h>
//#include "io.h"
//#include <math.h>
//#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

/*线性表的顺序储存结构类型描述*/
#define MAXSIZE 20 //储存空间初始分配量

typedef int ElemType;	 //假设元素类型为 int
typedef int Status;       //Status函数类型，其值为状态代码eg：OK

Status visit(ElemType e)
{
	printf("%d ", e);
	return OK;
}

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

/******************函数声明*******************/
Status InitList(SqList *L);//初始化顺序线性表
Status ListEmpty(SqList L);  //判空操作  初始条件：顺序线性表已存在
Status ClearList(SqList *L); //重置操作  初始条件：顺序线性表已存在
int ListLength(SqList L);   //取length
Status GetElem(SqList L, int i, ElemType *e);//获取第i个元素
int LocateElem(SqList L, ElemType e);      //找到元素e在L中的位置
Status ListInsert(SqList *L, int i, ElemType e);//第i个位置之前插入操作
Status ListDelete(SqList *L, int i, ElemType *e);//元素删除
Status ListTraverse(SqList L);       //对L的每个数据输出
void UnionL(SqList *La, SqList Lb);  //合并操作

int main()              //实际运用
{
	SqList L, Lb;
	ElemType e;     //temp，用来存放取得的数据元素
	Status sta;     //状态判断
	int j, k;        //循环变量 和 位置变量
	sta = InitList(&L);     //初始化L链表
	printf("初始化L后：L.length=%d\n", L.length);

	//接下来两拨骚操作
	for (j = 1; j <= 5; j++)
		sta = ListInsert(&L, 1, j);
	printf("在L的表头依次插入1~5后：L.data=");
	ListTraverse(L);
	printf("L.length=%d \n", L.length);
	sta = ListEmpty(L);
	printf("L是否空：status=%d(1:是 0:否)\n", sta);

	sta = ClearList(&L);
	printf("L是否空：status=%d(1:是 0:否)\n", sta);
	for (j = 1; j <= 10; j++)
		sta = ListInsert(&L, j, j);
	printf("在L的表尾依次插入1~10后：L.data=");
	ListTraverse(L);
	printf("L.length=%d \n", L.length);

	GetElem(L, 5, &e);
	printf("第5个元素的值为：%d\n", e);
	for (j = 6; j <= 7; j++)
	{
		k = LocateElem(L, j);
		if (k)
			printf("第%d个元素的值为：%d\n", k, j);
		else
			printf("没有值为%d的元素\n", j);
	}
	
	k = ListLength(L);        //表的长度
	printf("length = %d\n",k);
	//删除操作
	for (j = k - 4; j >= k - 5; j--)
	{
		sta = ListDelete(&L, j, &e);    //删除了第j个数据
		if (sta)
		{
			printf("删除的第%d个元素为：%d\n", j, e);
		}
		else
			printf("Fail to delete the %dth data.\n", j);
	}

	printf("Print the datas one by one:");
	ListTraverse(L);

	j = 5;
	ListDelete(&L, j, &e);    //删除第五个数据
	printf("第%d个元素的值为：%d\n", j,e);

	printf("Print the datas one by one:");
	ListTraverse(L);

	sta = InitList(&Lb);

	for (j = 1; j <= 5; j++)
		sta = ListInsert(&Lb, j, j * 17);

	UnionL(&L, Lb);
	printf("Print the datas one by one:");
	ListTraverse(L);

	return 0;

}


Status InitList(SqList *L)//初始化顺序线性表
{
	L->length = 0;
	return OK;
}

Status ListEmpty(SqList L)  //判空操作  初始条件：顺序线性表已存在
{
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

Status ClearList(SqList *L) //重置操作  初始条件：顺序线性表已存在
{
	L->length = 0;
	return OK;
}

int ListLength(SqList L)
{
	return L.length;
}

/*获取元素操作
  初始条件顺序线性表L存在1<=i<=ListLength(L)
  GetElem(L, i, &e) //用e获取第i位的元素的值*/
Status GetElem(SqList L, int i, ElemType *e)
{
	if (L.length == 0 || i<1 || i>L.length)
		return ERROR;
	*e = L.data[i - 1];
	return OK;
}
/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。
   若这样的数据元素不存在，则返回值为0 */
int LocateElem(SqList L, ElemType e)
{
	int i;
	if (L.length == 0)
		return 0;
	for (i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
			break;
	}
	if (i >= L.length)
		return 0;
	return i + 1;
}

/*ListInsert(&L, i, e) //插入操作
初始条件：顺序线性表L已存在，1<=i<=ListLength(L)
操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1*/
Status ListInsert(SqList *L, int i, ElemType e)
{
	int k;
	if (L->length == MAXSIZE)
		return ERROR;       //线性表已满
	if (i<1 || i>L->length + 1)
		return ERROR;       //i不在范围内
	if (i <= L->length)
	{
		for (k = L->length - 1; k >= i - 1; k--)
			L->data[k + 1] = L->data[k];     //插入数据不在表尾
	}
	L->data[i - 1] = e;
	L->length++;
	return OK;
}

/*	ListDelete(&L, i, &e) //删除操作，并用e返回元素的值
初始条件：顺序线性表L已存在，1<=i<=ListLength(L)
操作结果：删除L中的第i个数据元素，并用e返回其值，L的长度减1*/
Status ListDelete(SqList *L, int i, ElemType *e)
{
	int k;
	if (L->length == 0)
		return ERROR;   //线性表为空
	if (i<1 || i>L->length)
		return ERROR;   //删除位置不正确
	*e = L->data[i - 1];
	if (i < L->length)
	{
		for (k = i; k < L->length; k++)
		{
			L->data[k - 1] = L->data[k];
		}
		L->length--;
		return OK;
	}
}

Status ListTraverse(SqList L)       //对L的每个数据输出
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		visit(L.data[i]);
	}
	printf("\n");
	return OK;
}

void UnionL(SqList *La, SqList Lb)  //把Lb中和La不同的元素插入到La中
{
	int La_len, Lb_len, i;
	ElemType e;
	La_len = ListLength(*La);
	Lb_len = ListLength(Lb);
	for (i = 1; i <= Lb_len; i++)
	{
		GetElem(Lb, i, &e);
		if (!LocateElem(*La, e))
			ListInsert(La, ++La_len, e);
	}
}
