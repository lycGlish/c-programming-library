#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define ERROR -1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OVERFLOW -1
#define VOID 0

typedef char Elemtype;

typedef struct
{
	Elemtype *base;
	Elemtype *top;
	int stacksize;
}SqStack;

int Init_stack(SqStack *S) 
{
	S->base = (Elemtype *)malloc(STACK_INIT_SIZE * sizeof(Elemtype));
	if (!S->base)
	{
		printf("�����ڴ�ʧ��...\n");
		return ERROR;
	}
	else 
	{
		S->top = S->base;
		S->stacksize = STACK_INIT_SIZE;
		printf("ջ��ʼ���ɹ�...\n");
	}
	return TRUE;
}//��ʼ��ջ

int Push_stack(SqStack *S,Elemtype e) 
{
	if (S->top - S->base > S->stacksize)
	{
		S->base = (Elemtype *)realloc(S->base, (S->stacksize + STACKINCREMENT * sizeof(Elemtype)));
		if (!S->base) 
		{
			printf("���...\n");
			return OVERFLOW;
		}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return TRUE;
}//��eѹ��ջ

int Pop_stack(SqStack *S,Elemtype *e)
{
	*e = *(S->top - 1);
	S->top--;
	return TRUE;
}//��ջ��Ԫ�ص���

void Print_stack(SqStack S) 
{
	Elemtype *p;
	if (S.top == S.base) 
	{
		printf("ջΪ��...\n");
	}
	else {
		printf("���ջ������... \n");
		p = S.top;
		while (p != S.base)
		{
			--p;
			printf("%d ", *p);
		}
		printf("\n");
	}
}//�������ջԪ��

int Put_stack(SqStack *S,Elemtype *out_x) 
{
	Elemtype *temp = S->top;
	if (S->top == S->base) 
	{
		printf("ջΪ��...\n");
		return ERROR;
	}
	temp--;
	*out_x = *temp;
	return TRUE;
}//���ջ��Ԫ��

void Judge_stack(SqStack *S,Elemtype *text) 
{
	int i, j;
	Elemtype temp, *x, index;
	for (i = 0; text[i] != '@'; i++) 
	{
		index = text[i];
		Push_stack(S, index);
	}
	for (j = i-1; j >= 0; j--)
	{
		temp = Pop_stack(S,x);
		if (text[j] != temp)
		{
			printf("���ǻ���\n");
			break;
		}
	}
	if (j == -1)
		printf("�ǻ���");
}//�ж������Ƿ�Ϊ����

void next() 
{
	printf("��ѡ����һ���Ĳ�����");
}

int main() {
	int temp;
	Elemtype insert_x, out_x, *delete_it;
	SqStack *S = (SqStack *)malloc(sizeof(SqStack));
	Init_stack(S);
	puts("=======================˳��ջ������=======================");
	puts("\n");
	printf("1.ѹ��ֵ     2.����ֵ     3.���ջ     4.���ջ��Ԫ��\n");
	printf("5.�����ж�   99.�˳�����\n");
	printf("������Ҫ���еĲ���:");
	while (scanf("%d",&temp))
	{
		switch (temp) 
		{
		case 1:
			printf("��������Ҫ��ջ��ֵ��");
			scanf("%d", &insert_x);
			Push_stack(S, insert_x);
			printf("��ջ�ɹ�...\n");
			next();
			break;
		case 2:
			Pop_stack(S, delete_it);
			printf("��ջ�ɹ�������ֵΪ��%d\n", delete_it);
			next();
			break;
		case 3:
			Print_stack(*S);
			next();
			break;
		case 4:
			if (!Put_stack(S, &out_x)) 
			{
				printf("ջ��Ԫ��Ϊ��%d\n", out_x);
			}
			next();
			break;
		case 5:
			Elemtype text[STACKINCREMENT];
			printf("����������...\n");
			getchar();
			gets_s(text);//����ȡ99���ַ����ɸ��Ĵ�С
			Judge_stack(S, text);
			next();
			break;
		case 99:
			free(S);
			return 0;
		default:
			printf("û���������������������.\n");
			break;
		}
	}
	return 0;
}