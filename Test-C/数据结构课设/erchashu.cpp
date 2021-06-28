#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100       /* 存储空间初始分配量 */
#define MAX_TREE_SIZE 100 /* 二叉树的最大结点数 */

typedef int Status;
typedef char TElemType;
typedef TElemType SqBiTree[MAX_TREE_SIZE]; /* 0号单元存储根结点  */

int treeIndex = 1;
typedef char String[24]; /*  0号单元存放串的长度 */
String str;

Status StrAssign(String T, char *chars)
{
    int i;
    if (strlen(chars) > MAXSIZE)
        return ERROR;
    else
    {
        T[0] = strlen(chars);
        for (i = 1; i <= T[0]; i++)
            T[i] = *(chars + i - 1);
        return OK;
    }
}
TElemType Nil = ' '; /* 字符型以空格符为空 */

Status visit4(TElemType e)
{
    printf("%c ", e);
    return OK;
}

typedef struct BiTNode /* 结点结构 */
{
    TElemType data;                  /* 结点数据 */
    struct BiTNode *lchild, *rchild; /* 左右孩子指针 */
} BiTNode, *BiTree;

/* 构造空二叉树T */
Status InitBiTree(BiTree *T)
{
    *T = NULL;
    return OK;
}

/* 二叉树T存在 */
/* 若T为空二叉树,则返回TRUE,否则FALSE */
Status BiTreeEmpty(BiTree T)
{
    if (T)
        return FALSE;
    else
        return TRUE;
}

/* 二叉树T存在。返回T的根 */
int root(BiTree T)
{
    if (BiTreeEmpty(T))
        return Nil;
    else
        return T->data;
}

/* 按前序输入二叉树中结点的值（一个字符） */
/* #表示空树，构造二叉链表表示二叉树T。 */
void CreateBiTree(BiTree *T)
{
    TElemType ch;

    //scanf("%c", &ch);
    ch = str[treeIndex++];

    if (ch == '#')
        *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        // if (!*T)
        //     exit(OVERFLOW);
        (*T)->data = ch;             /* 生成根结点 */
        CreateBiTree(&(*T)->lchild); /* 构造左子树 */
        CreateBiTree(&(*T)->rchild); /* 构造右子树 */
    }
}

/* 返回T的深度 */
int BiTreeDepth(BiTree T)
{
    int i, j;
    if (!T)
        return 0;
    if (T->lchild)
        i = BiTreeDepth(T->lchild);
    else
        i = 0;
    if (T->rchild)
        j = BiTreeDepth(T->rchild);
    else
        j = 0;
    return i > j ? i + 1 : j + 1;
}

/*  前序递归遍历 T */
void PreOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    printf("%c", T->data);       /* 显示结点数据，可以更改为其它对结点操作 */
    PreOrderTraverse(T->lchild); /* 再先序遍历左子树 */
    PreOrderTraverse(T->rchild); /* 最后先序遍历右子树 */
}

/* 中序递归遍历 T */
void InOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    InOrderTraverse(T->lchild); /* 中序遍历左子树 */
    printf("%c", T->data);      /* 显示结点数据，可以更改为其它对结点操作 */
    InOrderTraverse(T->rchild); /* 最后中序遍历右子树 */
}

/*  后序递归遍历 T */
void PostOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    PostOrderTraverse(T->lchild); /* 先后序遍历左子树  */
    PostOrderTraverse(T->rchild); /* 再后序遍历右子树  */
    printf("%c", T->data);        /* 显示结点数据，可以更改为其它对结点操作 */
}

int a;
BiTree T;
TElemType e1;

static void showcreatTree()
{
    InitBiTree(&T);
    StrAssign(str, "ABDH#K###E##CFI###G#J##");
    CreateBiTree(&T);
    printf("\n树是否为空？%d   (1:是 0:否)\n", BiTreeEmpty(T));
    e1 = root(T);
    printf("二叉树的根为: %c\n", e1);
}

void showbianli()
{
    printf("\n前序遍历二叉树:");
    PreOrderTraverse(T);
    printf("\n中序遍历二叉树:");
    InOrderTraverse(T);
    printf("\n后序遍历二叉树:");
    PostOrderTraverse(T);
}

void showdepth()
{
    printf("\n树的深度=%d\n", BiTreeDepth(T));
}
