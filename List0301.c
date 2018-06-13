#include <stdio.h>
//#include <stdlib.h>
//#include "io.h"
//#include <math.h>
//#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

/*���Ա��˳�򴢴�ṹ��������*/
#define MAXSIZE 20 //����ռ��ʼ������

typedef int ElemType;	 //����Ԫ������Ϊ int
typedef int Status;       //Status�������ͣ���ֵΪ״̬����eg��OK

Status visit(ElemType e)
{
	printf("%d ", e);
	return OK;
}

typedef struct
{
	ElemType data[MAXSIZE];
	int length;
} SqList;       //��̬����

/*
#define INITSIZE 20
typedef struct
{
	ElemType *data;     //ָʾ��̬���������ָ��
	int MAXSIZE,length; //�������������͵�ǰ����
}SeqList;               //��̬��������˳�������Ͷ���
*/
//L.data=(ElemType*)malloc(sizeof(ElemType)*INITSIZE;
//L.data=new ElemType[INITSIZE];

/******************��������*******************/
Status InitList(SqList *L);//��ʼ��˳�����Ա�
Status ListEmpty(SqList L);  //�пղ���  ��ʼ������˳�����Ա��Ѵ���
Status ClearList(SqList *L); //���ò���  ��ʼ������˳�����Ա��Ѵ���
int ListLength(SqList L);   //ȡlength
Status GetElem(SqList L, int i, ElemType *e);//��ȡ��i��Ԫ��
int LocateElem(SqList L, ElemType e);      //�ҵ�Ԫ��e��L�е�λ��
Status ListInsert(SqList *L, int i, ElemType e);//��i��λ��֮ǰ�������
Status ListDelete(SqList *L, int i, ElemType *e);//Ԫ��ɾ��
Status ListTraverse(SqList L);       //��L��ÿ���������
void UnionL(SqList *La, SqList Lb);  //�ϲ�����

int main()              //ʵ������
{
	SqList L, Lb;
	ElemType e;     //temp���������ȡ�õ�����Ԫ��
	Status sta;     //״̬�ж�
	int j, k;        //ѭ������ �� λ�ñ���
	sta = InitList(&L);     //��ʼ��L����
	printf("��ʼ��L��L.length=%d\n", L.length);

	//����������ɧ����
	for (j = 1; j <= 5; j++)
		sta = ListInsert(&L, 1, j);
	printf("��L�ı�ͷ���β���1~5��L.data=");
	ListTraverse(L);
	printf("L.length=%d \n", L.length);
	sta = ListEmpty(L);
	printf("L�Ƿ�գ�status=%d(1:�� 0:��)\n", sta);

	sta = ClearList(&L);
	printf("L�Ƿ�գ�status=%d(1:�� 0:��)\n", sta);
	for (j = 1; j <= 10; j++)
		sta = ListInsert(&L, j, j);
	printf("��L�ı�β���β���1~10��L.data=");
	ListTraverse(L);
	printf("L.length=%d \n", L.length);

	GetElem(L, 5, &e);
	printf("��5��Ԫ�ص�ֵΪ��%d\n", e);
	for (j = 6; j <= 7; j++)
	{
		k = LocateElem(L, j);
		if (k)
			printf("��%d��Ԫ�ص�ֵΪ��%d\n", k, j);
		else
			printf("û��ֵΪ%d��Ԫ��\n", j);
	}
	
	k = ListLength(L);        //��ĳ���
	printf("length = %d\n",k);
	//ɾ������
	for (j = k - 4; j >= k - 5; j--)
	{
		sta = ListDelete(&L, j, &e);    //ɾ���˵�j������
		if (sta)
		{
			printf("ɾ���ĵ�%d��Ԫ��Ϊ��%d\n", j, e);
		}
		else
			printf("Fail to delete the %dth data.\n", j);
	}

	printf("Print the datas one by one:");
	ListTraverse(L);

	j = 5;
	ListDelete(&L, j, &e);    //ɾ�����������
	printf("��%d��Ԫ�ص�ֵΪ��%d\n", j,e);

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


Status InitList(SqList *L)//��ʼ��˳�����Ա�
{
	L->length = 0;
	return OK;
}

Status ListEmpty(SqList L)  //�пղ���  ��ʼ������˳�����Ա��Ѵ���
{
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

Status ClearList(SqList *L) //���ò���  ��ʼ������˳�����Ա��Ѵ���
{
	L->length = 0;
	return OK;
}

int ListLength(SqList L)
{
	return L.length;
}

/*��ȡԪ�ز���
  ��ʼ����˳�����Ա�L����1<=i<=ListLength(L)
  GetElem(L, i, &e) //��e��ȡ��iλ��Ԫ�ص�ֵ*/
Status GetElem(SqList L, int i, ElemType *e)
{
	if (L.length == 0 || i<1 || i>L.length)
		return ERROR;
	*e = L.data[i - 1];
	return OK;
}
/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* �������������L�е�1����e�����ϵ������Ԫ�ص�λ��
   ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
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

/*ListInsert(&L, i, e) //�������
��ʼ������˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)
�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1*/
Status ListInsert(SqList *L, int i, ElemType e)
{
	int k;
	if (L->length == MAXSIZE)
		return ERROR;       //���Ա�����
	if (i<1 || i>L->length + 1)
		return ERROR;       //i���ڷ�Χ��
	if (i <= L->length)
	{
		for (k = L->length - 1; k >= i - 1; k--)
			L->data[k + 1] = L->data[k];     //�������ݲ��ڱ�β
	}
	L->data[i - 1] = e;
	L->length++;
	return OK;
}

/*	ListDelete(&L, i, &e) //ɾ������������e����Ԫ�ص�ֵ
��ʼ������˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)
���������ɾ��L�еĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1*/
Status ListDelete(SqList *L, int i, ElemType *e)
{
	int k;
	if (L->length == 0)
		return ERROR;   //���Ա�Ϊ��
	if (i<1 || i>L->length)
		return ERROR;   //ɾ��λ�ò���ȷ
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

Status ListTraverse(SqList L)       //��L��ÿ���������
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		visit(L.data[i]);
	}
	printf("\n");
	return OK;
}

void UnionL(SqList *La, SqList Lb)  //��Lb�к�La��ͬ��Ԫ�ز��뵽La��
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

