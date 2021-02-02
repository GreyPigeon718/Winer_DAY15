
#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;

typedef struct BiTNode   //���������
{
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
void CreateBiTreeByPreOrder(BiTree* T)  //�������д�����   //*T(ָ���ָ��)
{
	ElemType data;
	scanf_s("%c", &data);
	if (data == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = data;
		CreateBiTreeByPreOrder(&(*T)->lchild);//����������     ddd
		CreateBiTreeByPreOrder(&(*T)->rchild);//����������
	}
}
void CreateBiTreeByInOrder(BiTree* T)           //�������д�����       
{
	ElemType data;
	scanf_s("%c", &data);
	if (data == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		CreateBiTreeByInOrder(&(*T)->lchild);
		(*T)->data = data;
		CreateBiTreeByInOrder(&(*T)->rchild);
	}
}
void CreateBiTreeByPostOrder(BiTree* T)     //�������д�����
{
	ElemType data;
	scanf_s("%c", &data);
	if (data == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		CreateBiTreeByPostOrder(&(*T)->lchild);
		CreateBiTreeByPostOrder(&(*T)->rchild);
		(*T)->data = data;
	}
}
void PreOrder(BiTree node)   //����������ǵݹ飩�ݹ��㷨����࣬�ɶ���ǿ������Ч�ʵͣ����ĵ�ʱ��ռ���Դ���϶�
{
	if (node != NULL)
	{
		printf("%d\n", node->data);
		PreOrder(node->lchild);
		PreOrder(node->rchild);
	}
}
void InOrder(BiTree node)     //������� ���ǵݹ飩
{
	if (node != NULL)
	{
		InOrder(node->lchild);
		printf("%d\n", node->data);
		InOrder(node->rchild);
	}
}
void PostOrder(BiTree node)      //�������(�ǵݹ�)
{
	if (node != NULL)
	{
		PostOrder(node->lchild);
		PostOrder(node->rchild);
		printf("%d\n", node->data);
	}
} 
//oid InOrder(BiTree T)
//{
//	BiTree* stack = (BiTree*)malloc(sizeof(BiTree));    //ջ��ָ���ָ��
//	BiTree p;   //p�Ǳ���ָ��
//	while()

//}


int main()
{
	BiTree ptree = NULL;
	CreateBiTreeByPreOrder(&ptree);
	PreOrder(ptree);
	return 0;
}


