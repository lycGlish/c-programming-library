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
		printf("分配内存失败...\n");
		return ERROR;
	}
	else 
	{
		S->top = S->base;
		S->stacksize = STACK_INIT_SIZE;
		printf("栈初始化成功...\n");
	}
	return TRUE;
}//初始化栈

int Push_stack(SqStack *S,Elemtype e) 
{
	if (S->top - S->base > S->stacksize)
	{
		S->base = (Elemtype *)realloc(S->base, (S->stacksize + STACKINCREMENT * sizeof(Elemtype)));
		if (!S->base) 
		{
			printf("溢出...\n");
			return OVERFLOW;
		}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return TRUE;
}//将e压入栈

int Pop_stack(SqStack *S,Elemtype *e)
{
	*e = *(S->top - 1);
	S->top--;
	return TRUE;
}//将栈顶元素弹出

void Print_stack(SqStack S) 
{
	Elemtype *p;
	if (S.top == S.base) 
	{
		printf("栈为空...\n");
	}
	else {
		printf("输出栈的内容... \n");
		p = S.top;
		while (p != S.base)
		{
			--p;
			printf("%d ", *p);
		}
		printf("\n");
	}
}//输出所有栈元素

int Put_stack(SqStack *S,Elemtype *out_x) 
{
	Elemtype *temp = S->top;
	if (S->top == S->base) 
	{
		printf("栈为空...\n");
		return ERROR;
	}
	temp--;
	*out_x = *temp;
	return TRUE;
}//输出栈顶元素

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
			printf("不是回文\n");
			break;
		}
	}
	if (j == -1)
		printf("是回文");
}//判断输入是否为回文

void next() 
{
	printf("请选择下一步的操作：");
}

int main() {
	int temp;
	Elemtype insert_x, out_x, *delete_it;
	SqStack *S = (SqStack *)malloc(sizeof(SqStack));
	Init_stack(S);
	puts("=======================顺序栈的运算=======================");
	puts("\n");
	printf("1.压入值     2.弹出值     3.输出栈     4.输出栈顶元素\n");
	printf("5.回文判断   99.退出程序\n");
	printf("请输入要进行的操作:");
	while (scanf("%d",&temp))
	{
		switch (temp) 
		{
		case 1:
			printf("请输入需要入栈的值：");
			scanf("%d", &insert_x);
			Push_stack(S, insert_x);
			printf("入栈成功...\n");
			next();
			break;
		case 2:
			Pop_stack(S, delete_it);
			printf("出栈成功，弹出值为：%d\n", delete_it);
			next();
			break;
		case 3:
			Print_stack(*S);
			next();
			break;
		case 4:
			if (!Put_stack(S, &out_x)) 
			{
				printf("栈顶元素为：%d\n", out_x);
			}
			next();
			break;
		case 5:
			Elemtype text[STACKINCREMENT];
			printf("请输入文字...\n");
			getchar();
			gets_s(text);//仅读取99个字符，可更改大小
			Judge_stack(S, text);
			next();
			break;
		case 99:
			free(S);
			return 0;
		default:
			printf("没有这个操作，请重新输入.\n");
			break;
		}
	}
	return 0;
}