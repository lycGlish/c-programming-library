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
	printf("初始化...\n");
	L->elem = (ElemType*)malloc(MAX_LIST * sizeof(ElemType));
	if (!L->elem)
		return ERROR;
	L->length = 0;
	L->listsize = MAX_LIST;
	for (i = 0; i < n; i++)
	{
		printf("请输入第%d个数\n", i + 1);
		scanf("%d", &iTemp);
		L->elem[L->length] = iTemp;
		++L->length;
	}
	printf("初始化成功...\n");
	return TRUE;
}//初始化线性表

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
}//将数据插入线性表

int Delete_Sqlist(SqList *L, int index) 
{
	int i;
	for (i = L->length; i>index; i--) 
	{
		L->elem[i - 1] = L->elem[i];
	}
	L->length--;
	return TRUE;
}//删除线性表中数据

int SearchList(SqList *L, ElemType x)
{
	for (int i = 0; i < L->length; i++)
	{
		if (x == L->elem[i])
			return i;
	}
	return NOFOUND;
}//在线性表中寻找元素

void printf_Sqlist(SqList *L) 
{
	int i;
	if (L->length == 0)
		printf("线性表为空! \n");
	else 
	{
		for (i = 0; i<L->length; i++) 
		{
			printf("%d \t", L->elem[i]);
		}
	}
	printf("\n");
}//输出线性表

void Clear_Sqlist(SqList *L) 
{
	L->length = 0;
}//清空线性表

int Get_Sqlist(SqList *L)
{
	return L->length;
}//获取线性表长度

void Ex_Sqlist(SqList *L)
{
	int i, temp;
	for (i = 0; i < L->length / 2; i++) 
	{
		temp = L->elem[i];
		L->elem[i] = L->elem[L->length - i - 1];
		L->elem[L->length - i - 1] = temp;
	}
}//线性表的就地逆转

void Check_Increase(SqList *L)
{
	int i;
	for (i = 0; i < L->length-1; i++) 
	{
		if (L->elem[i] > L->elem[i + 1]) 
		{
			printf("线性表不为递增./n");
			break;
		}
	}
	if (i == L->length-1) {
		printf("线性表为递增.\n");
	}
}//判断线性表中数据特性

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
}//冒泡排序

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
}//奇数放左，偶数放右

void next() 
{
	printf("请选择下一个操作：");
	return;
}

int main()
{
	int temp, insert_x, delete_it, search, search_it, n;
	printf("请输入你想创建的线性表大小：\n");
	scanf("%d", &n);
	SqList *L = (SqList *)malloc(sizeof(SqList));
	Init_Sqlist(L, n);
	puts("==========================线性表的操作============================");
	puts("\n");
	printf("1.插入值       2.删除值        3.查找元素      4.读取线性表长度.\n");
	printf("5.输出线性表   6.清空线性表    7.特殊操作      99.结束程序.\n");
	printf("请输入要选择的操作：");
	while (scanf("%d", &temp))
	{
		switch (temp)
		{
		case 1:
			printf("请输入你要插入的位置：");
			scanf("%d", &temp);
			printf("请输入你要插入的值：");
			scanf("%d", &insert_x);
			Insert_Sqlist(L, temp, insert_x);
			next();
			break;
		case 2:
			printf("请输入你要删除值的位置：");
			scanf("%d", &delete_it);
			Delete_Sqlist(L, delete_it);
			next();
			break;
		case 3:
			printf("请输入你要查找的元素");
			scanf("%d", &search);
			search_it = SearchList(L, search);
			if (search_it == NOFOUND)
				printf("线性表中没有这个元素!\n");
			else
				printf("%d在线性表第%d个位置.\n", search, search_it + 1);
			next();
			break;
		case 4:
			printf("线性表长度为：%d\n", Get_Sqlist(L));
			next();
			break;
		case 5:
			printf_Sqlist(L);
			puts("");
			next();
			break;
		case 6:
			Clear_Sqlist(L);
			printf("线性表已清空.\n");
			next();
			break;
		case 7:
			puts("====================线性表的特殊操作=======================");
			puts("\n");
			printf("1.线性表就地逆转   2.线性表的递增判断   3.冒泡排序.\n");
			printf("4.奇偶分配.\n");
			printf("请输入你要进行的特殊操作：");
			scanf("%d", &temp);
			switch (temp) 
			{
			case 1:
				Ex_Sqlist(L);
				printf("线性表就地逆转成功.\n");
				next();
				break;
			case 2:
				Check_Increase(L);
				next();
				break;
			case 3:
				Bubb_Sqlist(L);
				printf("冒泡排序成功...\n");
				next();
				break;
			case 4:
				Check_Odevity(L);
				printf("奇偶左右已分配好...\n");
				next();
				break;
			default:
				printf("没有这个操作，请重新输入\n");
				break;
			}
			break;
		case 99:
			free(L);
			return 0;
		default:
			printf("没有这个操作，请重新输入\n");
			break;
		}
	}
	return 0;
}