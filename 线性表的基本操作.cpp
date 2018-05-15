#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define ERROR 0
#define MAX_LIST 100
#define OVERFLOW -1
#define NOFOUND -1

typedef int ElemType;

typedef struct sqlist 
{
	ElemType *elem;
	int length;
	int listsize;
} SqList;

int Init_Sqlist(SqList *L, int n) 
{
	int i, iTemp;
	printf("��ʼ��...\n");
	L->elem = (ElemType*)malloc(MAX_LIST * sizeof(ElemType));
	if (!L->elem)
		return ERROR;
	L->length = 0;
	L->listsize = MAX_LIST;
	for (i = 0; i < n; i++)
	{
		printf("�������%d����\n", i + 1);
		scanf("%d", &iTemp);
		L->elem[L->length] = iTemp;
		++L->length;
	}
	printf("��ʼ���ɹ�...\n");
	return TRUE;
}//��ʼ�����Ա�

int Insert_Sqlist(SqList *L, int index, ElemType x)
{
	int i;
	for (i = L->length; i >= index; i--) 
	{
		L->elem[i + 1] = L->elem[i];
	}
	L->elem[index] = x;
	L->length++;
	return TRUE;
}//�����ݲ������Ա�

int Delete_Sqlist(SqList *L, int index) 
{
	int i;
	for (i = L->length; i>index; i--) 
	{
		L->elem[i - 1] = L->elem[i];
	}
	L->length--;
	return TRUE;
}//ɾ�����Ա�������

int SearchList(SqList *L, ElemType x)
{
	for (int i = 0; i < L->length; i++)
	{
		if (x == L->elem[i])
			return i;
	}
	return NOFOUND;
}//�����Ա���Ѱ��Ԫ��

void printf_Sqlist(SqList *L) 
{
	int i;
	if (L->length == 0)
		printf("���Ա�Ϊ��! \n");
	else 
	{
		for (i = 0; i<L->length; i++) 
		{
			printf("%d \t", L->elem[i]);
		}
	}
	printf("\n");
}//������Ա�

void Clear_Sqlist(SqList *L) 
{
	L->length = 0;
}//������Ա�

int Get_Sqlist(SqList *L)
{
	return L->length;
}//��ȡ���Ա���

void Ex_Sqlist(SqList *L)
{
	int i, temp;
	for (i = 0; i < L->length / 2; i++) 
	{
		temp = L->elem[i];
		L->elem[i] = L->elem[L->length - i - 1];
		L->elem[L->length - i - 1] = temp;
	}
}//���Ա�ľ͵���ת

void Check_Increase(SqList *L)
{
	int i;
	for (i = 0; i < L->length-1; i++) 
	{
		if (L->elem[i] > L->elem[i + 1]) 
		{
			printf("���Ա�Ϊ����./n");
			break;
		}
	}
	if (i == L->length-1) {
		printf("���Ա�Ϊ����.\n");
	}
}//�ж����Ա�����������

void Bubb_Sqlist(SqList *L)	
{
	int i, j, temp, flag = 1;
	for (i = 0; (i < L->length-1)&&flag==1; i++)
	{
		flag = 0;
		for (j = 0; j < L->length-1-i; j++)
		{
			if (L->elem[j] > L->elem[j + 1])
			{
				flag = 1;
				temp = L->elem[j];
				L->elem[j] = L->elem[j + 1];
				L->elem[j + 1] = temp;
			}
		}
	}
}//ð������

void Check_Odevity(SqList *L)
{
	int i = 0, temp, j;
	while(i<=L->length-1)
	{
		if (L->elem[i] % 2 == 0)
		{
			temp = L->elem[i];
			for (j = i; j < L->length-1; j++)
			{
				L->elem[j] = L->elem[j + 1];
			}
			L->elem[L->length-1] = temp;
			continue;
		}
		i++;
	}
}//��������ż������

void next() 
{
	printf("��ѡ����һ��������");
	return;
}

int main()
{
	int temp, insert_x, delete_it, search, search_it, n;
	printf("���������봴�������Ա��С��\n");
	scanf("%d", &n);
	SqList *L = (SqList *)malloc(sizeof(SqList));
	Init_Sqlist(L, n);
	puts("==========================���Ա�Ĳ���============================");
	puts("\n");
	printf("1.����ֵ       2.ɾ��ֵ        3.����Ԫ��      4.��ȡ���Ա���.\n");
	printf("5.������Ա�   6.������Ա�    7.�������      99.��������.\n");
	printf("������Ҫѡ��Ĳ�����");
	while (scanf("%d", &temp))
	{
		switch (temp)
		{
		case 1:
			printf("��������Ҫ�����λ�ã�");
			scanf("%d", &temp);
			printf("��������Ҫ�����ֵ��");
			scanf("%d", &insert_x);
			Insert_Sqlist(L, temp, insert_x);
			next();
			break;
		case 2:
			printf("��������Ҫɾ��ֵ��λ�ã�");
			scanf("%d", &delete_it);
			Delete_Sqlist(L, delete_it);
			next();
			break;
		case 3:
			printf("��������Ҫ���ҵ�Ԫ��");
			scanf("%d", &search);
			search_it = SearchList(L, search);
			if (search_it == NOFOUND)
				printf("���Ա���û�����Ԫ��!\n");
			else
				printf("%d�����Ա��%d��λ��.\n", search, search_it + 1);
			next();
			break;
		case 4:
			printf("���Ա���Ϊ��%d\n", Get_Sqlist(L));
			next();
			break;
		case 5:
			printf_Sqlist(L);
			puts("");
			next();
			break;
		case 6:
			Clear_Sqlist(L);
			printf("���Ա������.\n");
			next();
			break;
		case 7:
			puts("====================���Ա���������=======================");
			puts("\n");
			printf("1.���Ա�͵���ת   2.���Ա�ĵ����ж�   3.ð������.\n");
			printf("4.��ż����.\n");
			printf("��������Ҫ���е����������");
			scanf("%d", &temp);
			switch (temp) 
			{
			case 1:
				Ex_Sqlist(L);
				printf("���Ա�͵���ת�ɹ�.\n");
				next();
				break;
			case 2:
				Check_Increase(L);
				next();
				break;
			case 3:
				Bubb_Sqlist(L);
				printf("ð������ɹ�...\n");
				next();
				break;
			case 4:
				Check_Odevity(L);
				printf("��ż�����ѷ����...\n");
				next();
				break;
			default:
				printf("û���������������������\n");
				break;
			}
			break;
		case 99:
			free(L);
			return 0;
		default:
			printf("û���������������������\n");
			break;
		}
	}
	return 0;
}