#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define ERROR 0
#define MAX_NODE 100

typedef char Elemtype;

typedef struct BTNode
{
	Elemtype data;
	BTNode *Rchild, *Lchild;
}BTNode;

BTNode *InitNode(Elemtype e) 
{
	BTNode *node = (BTNode *)malloc(sizeof(BTNode));
	node->data = e;
	node->Lchild = NULL;
	node->Rchild = NULL;
	return node;
}

int PreorderTraverse(BTNode  *T) 
{
	/*if (T != NULL) {
	printf("%c ", T->data);
	PreorderTraverse(T->Lchild);
	PreorderTraverse(T->Rchild);
	}*/
	BTNode  *stack[MAX_NODE], *p = T, *q;
	int top = 0;
	if (T == NULL) 
	{
		printf("��Ϊ�գ�\n");
	}
	else 
	{
		do 
		{
			printf("%c", p->data);
			q = p->Rchild;
			if (q != NULL) 
			{
				stack[++top] = q;
			}
			p = p->Lchild;
			if (p == NULL) 
			{
				if (top!=0) 
				{
					p = stack[top];
					top--;
					//������ printf("%d", top);
				}
			}
		} while (p != NULL);
	}
	return 0;
}//�������

int InorderTraverse(BTNode  *T) 
{
	/*if (T != NULL) {
	InorderTraverse(T->Lchild);
	printf("%c",T->data);
	InorderTraverse(T->Rchild);
	}*/
	BTNode  *stack[MAX_NODE], *p = T;
	int  top = 0, judge = 1;
	if (T == NULL)
		printf("��Ϊ�գ�\n");
	else 
	{
		do 
		{
			while (p != NULL) 
			{
				stack[++top] = p;  p = p->Lchild;
			}
			if (top == 0)  judge = 0;
			else {
				p = stack[top];
				top--;
				printf("%c", p->data);
				p = p->Rchild;
			}
		} while (judge != 0);
	}
	return 0;
}//�������

int  PostorderTraverse(BTNode  *T) {
	/*if (T != NULL)
	{
	PostorderTraverse(T->Lchild);
	PostorderTraverse(T->Rchild);
	printf("%c",T->data);
	}*/
	BTNode  *S1[MAX_NODE], *p = T;
	int S2[MAX_NODE], top = 0, judge = 1;
	if (T == NULL)
		printf("��Ϊ�գ�\n");
	else {
		do {
			while (p != NULL) {
				S1[++top] = p;
				S2[top] = 0;
				p = p->Lchild;
			}
			if (top == 0)
				judge = 0;
			else if (S2[top] == 0) {
				p = S1[top]->Rchild;
				S2[top] = 1;
			}
			else {
				p = S1[top];
				top--;
				printf("%c", p->data);
				p = NULL;
			}
		} while (judge != 0);
	}
	return 0;
}//�������

int Insert_LNode(BTNode *T, BTNode *C) {
	char temp;
	if (T->Lchild != NULL) {
		printf("�����Ѵ��ڣ��Ƿ񸲸ǣ�Y/N\n");
		scanf("%c", temp);
		if (temp == 'y' || temp == 'Y') {
			T->Lchild = C;
			printf("�������ӳɹ�...\n");
			return 0;
		}
		else if (temp == 'n' || temp == 'N') {
			printf("������ֹ...\n");
			return 0;
		}
		else {
			printf("û�����ѡ�������ѡ�����\n");
			return 0;
		}
	}
	T->Lchild = C;
	return 0;
}//��������

int Insert_RNode(BTNode *T, BTNode *C) {
	char temp;
	if (T->Rchild != NULL) {
		printf("�Һ����Ѵ��ڣ��Ƿ񸲸ǣ�Y/N\n");
		scanf("%c", temp);
		if (temp == 'y' || temp == 'Y') {
			T->Rchild = C;
			printf("�����Һ��ӳɹ�...\n");
			return 0;
		}
		else if (temp == 'n' || temp == 'N') {
			printf("������ֹ...\n");
			return 0;
		}
		else {
			printf("û�����ѡ�������ѡ�����\n");
			return 0;
		}
	}
	T->Rchild = C;
	return 0;
}//�����Һ���

void next() {
	printf("��������һ��������\n");
}

int main() {
	int temp;
	Elemtype index, test;
	BTNode *father, *front, *LNext, *RNext;
	printf("��������ڵ㣺");
	scanf("%c", &index);
	BTNode *root = InitNode(index);
	father = root;
	puts("==============================================������������==============================================");
	puts("\n");
	printf("1.��������    2.�����Һ���  3. �ƶ�������  4. �ƶ����Һ���\n");
	printf("5.������һ�ڵ�  6.�������    7.�������       8.�������\n");
	printf("9.���ظ��ڵ�    99.��������\n");
	printf("��������еĲ�����");
	while (scanf("%d", &temp))
	{
		switch (temp)
		{
		case 1:
			getchar();
			printf("������ýڵ�ֵ��");
			scanf("%c", &index);
			LNext = InitNode(index);
			Insert_LNode(father, LNext);
			next();
			break;
		case 2:
			getchar();
			printf("������ýڵ�ֵ��");
			scanf("%c", &index);
			RNext = InitNode(index);
			Insert_RNode(father, RNext);
			next();
			break;
		case 3:
			getchar();
			printf("ֻ�ܷ�����һ�ڵ�һ�Σ��Ƿ��ƶ���Y/N\n");
			scanf("%c", &test);
			if (test == 'Y' || test == 'y') {
				front = father;
				father = LNext;
				printf("�ƶ��ɹ�...\n");
				next();
				break;
			}
			else if (test == 'N' || test == 'N') {
				printf("�ƶ���ֹ...\n");
				next();
				break;
			}
			else {
				printf("û�����ѡ�������ѡ�����\n");
				break;
			}
		case 4:
			getchar();
			printf("ֻ�ܷ�����һ�ڵ�һ�Σ��Ƿ��ƶ���Y/N\n");
			scanf("%c", &test);
			if (test == 'Y' || test == 'y') {
				front = father;
				father = RNext;
				printf("�ƶ��ɹ�...\n");
				next();
				break;
			}
			else if (test == 'N' || test == 'N') {
				printf("�ƶ���ֹ...\n");
				next();
				break;
			}
			else {
				printf("û�����ѡ�������ѡ�����\n");
				break;
			}
		case 5:
			father = front;
			printf("������һ�ڵ�ɹ�...\n");
			next();
			break;
		case 6:
			PreorderTraverse(root);
			printf("\n");
			next();
			break;
		case 7:
			InorderTraverse(root);
			printf("\n");
			next();
			break;
		case 8:
			PostorderTraverse(root);
			printf("\n");
			next();
			break;
		case 9:
			front = father;
			father = root;
			printf("���ظ��ڵ�ɹ�...\n");
			next();
			break;
		case 99:
			return 0;
		default:
			printf("û�����ѡ�����������.\n");
			break;
		}
	}
	return 0;
}