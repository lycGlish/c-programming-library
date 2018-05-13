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
		printf("树为空！\n");
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
					//错误检查 printf("%d", top);
				}
			}
		} while (p != NULL);
	}
	return 0;
}//先序遍历

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
		printf("树为空！\n");
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
}//中序遍历

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
		printf("树为空！\n");
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
}//后序遍历

int Insert_LNode(BTNode *T, BTNode *C) {
	char temp;
	if (T->Lchild != NULL) {
		printf("左孩子已存在，是否覆盖？Y/N\n");
		scanf("%c", temp);
		if (temp == 'y' || temp == 'Y') {
			T->Lchild = C;
			printf("插入左孩子成功...\n");
			return 0;
		}
		else if (temp == 'n' || temp == 'N') {
			printf("插入终止...\n");
			return 0;
		}
		else {
			printf("没有这个选项，请重新选择操作\n");
			return 0;
		}
	}
	T->Lchild = C;
	return 0;
}//插入左孩子

int Insert_RNode(BTNode *T, BTNode *C) {
	char temp;
	if (T->Rchild != NULL) {
		printf("右孩子已存在，是否覆盖？Y/N\n");
		scanf("%c", temp);
		if (temp == 'y' || temp == 'Y') {
			T->Rchild = C;
			printf("插入右孩子成功...\n");
			return 0;
		}
		else if (temp == 'n' || temp == 'N') {
			printf("插入终止...\n");
			return 0;
		}
		else {
			printf("没有这个选项，请重新选择操作\n");
			return 0;
		}
	}
	T->Rchild = C;
	return 0;
}//插入右孩子

void next() {
	printf("请输入下一步操作：\n");
}

int main() {
	int temp;
	Elemtype index, test;
	BTNode *father, *front, *LNext, *RNext;
	printf("请输入根节点：");
	scanf("%c", &index);
	BTNode *root = InitNode(index);
	father = root;
	puts("==============================================二叉树的运算==============================================");
	puts("\n");
	printf("1.插入左孩子    2.插入右孩子  3. 移动到左孩子  4. 移动到右孩子\n");
	printf("5.返回上一节点  6.先序遍历    7.中序遍历       8.后序遍历\n");
	printf("9.返回根节点    99.结束程序\n");
	printf("请输入进行的操作：");
	while (scanf("%d", &temp))
	{
		switch (temp)
		{
		case 1:
			getchar();
			printf("请输入该节点值：");
			scanf("%c", &index);
			LNext = InitNode(index);
			Insert_LNode(father, LNext);
			next();
			break;
		case 2:
			getchar();
			printf("请输入该节点值：");
			scanf("%c", &index);
			RNext = InitNode(index);
			Insert_RNode(father, RNext);
			next();
			break;
		case 3:
			getchar();
			printf("只能返回上一节点一次，是否移动？Y/N\n");
			scanf("%c", &test);
			if (test == 'Y' || test == 'y') {
				front = father;
				father = LNext;
				printf("移动成功...\n");
				next();
				break;
			}
			else if (test == 'N' || test == 'N') {
				printf("移动终止...\n");
				next();
				break;
			}
			else {
				printf("没有这个选项，请重新选择操作\n");
				break;
			}
		case 4:
			getchar();
			printf("只能返回上一节点一次，是否移动？Y/N\n");
			scanf("%c", &test);
			if (test == 'Y' || test == 'y') {
				front = father;
				father = RNext;
				printf("移动成功...\n");
				next();
				break;
			}
			else if (test == 'N' || test == 'N') {
				printf("移动终止...\n");
				next();
				break;
			}
			else {
				printf("没有这个选项，请重新选择操作\n");
				break;
			}
		case 5:
			father = front;
			printf("返回上一节点成功...\n");
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
			printf("返回根节点成功...\n");
			next();
			break;
		case 99:
			return 0;
		default:
			printf("没有这个选项，请重新输入.\n");
			break;
		}
	}
	return 0;
}