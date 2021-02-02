
#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;

typedef struct BiTNode   //二叉树结点
{
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
void CreateBiTreeByPreOrder(BiTree* T)  //先序序列创建树   //*T(指针的指针)
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
		CreateBiTreeByPreOrder(&(*T)->lchild);//构造左子树     ddd
		CreateBiTreeByPreOrder(&(*T)->rchild);//构造右子树
	}
}
void CreateBiTreeByInOrder(BiTree* T)           //中序序列创建树       
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
void CreateBiTreeByPostOrder(BiTree* T)     //后序序列创建树
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
void PreOrder(BiTree node)   //先序遍历（非递归）递归算法：简洁，可读性强，运行效率低，消耗的时间空间资源都较多
{
	if (node != NULL)
	{
		printf("%d\n", node->data);
		PreOrder(node->lchild);
		PreOrder(node->rchild);
	}
}
void InOrder(BiTree node)     //中序遍历 （非递归）
{
	if (node != NULL)
	{
		InOrder(node->lchild);
		printf("%d\n", node->data);
		InOrder(node->rchild);
	}
}
void PostOrder(BiTree node)      //后序遍历(非递归)
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
//	BiTree* stack = (BiTree*)malloc(sizeof(BiTree));    //栈：指针的指针
//	BiTree p;   //p是遍历指针
//	while()

//}


int main()
{
	BiTree ptree = NULL;
	CreateBiTreeByPreOrder(&ptree);
	PreOrder(ptree);
	return 0;
}


