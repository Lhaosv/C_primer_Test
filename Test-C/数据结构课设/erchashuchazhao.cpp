#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE_ 150       /* 存储空间初始分配量 */
#define MAX_TREE_SIZE_ 150 /* 二叉树的最大结点数 */

typedef int Status;                         /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int TelemType;                      /* 树结点的数据类型，目前暂定为整型 */
typedef TelemType SqBitree[MAX_TREE_SIZE_]; /* 0号单元存储根结点  */

typedef struct
{
    int level, order; /* 结点的层,本层序号(按满二叉树计算) */
} Position;

TelemType nil = 0; /*  设整型以0为空 */

/* 构造空二叉树T。因为T是固定数组，不会改变，故不需要 & */
Status InitBiTree(SqBitree T)
{
    int i;
    for (i = 0; i < MAX_TREE_SIZE_; i++)
        T[i] = nil; /* 初值为空 */
    return OK;
}

Status CreateBiTree(SqBitree T)
{
    int i = 0;
    while (i < 10)
    {
        T[i] = i + 1;

        if (i != 0 && T[(i + 1) / 2 - 1] == nil && T[i] != nil) /* 此结点(不空)无双亲且不是根 */
        {
            printf("出现无双亲的非根结点%d\n", T[i]);
            exit(ERROR);
        }
        i++;
    }
    while (i < MAX_TREE_SIZE_)
    {
        T[i] = nil; /* 将空赋值给T的后面的结点 */
        i++;
    }

    return OK;
}

/* 查找双亲 */
/* 若e是T的非根结点,则返回它的双亲,否则返回＂空＂ */
TelemType Parent(SqBitree T, TelemType e)
{
    int i;
    if (T[0] == nil) /* 空树 */
        return nil;
    for (i = 1; i <= MAX_TREE_SIZE_ - 1; i++)
        if (T[i] == e) /* 找到e */
            return T[(i + 1) / 2 - 1];
    return nil; /* 没找到e */
}

/* 查找左孩子 */
/* 返回e的左孩子。若e无左孩子,则返回＂空＂ */
TelemType LeftChild(SqBitree T, TelemType e)
{
    int i;
    if (T[0] == nil) /* 空树 */
        return nil;
    for (i = 0; i <= MAX_TREE_SIZE_ - 1; i++)
        if (T[i] == e) /* 找到e */
            return T[i * 2 + 1];
    return nil; /* 没找到e */
}

/* 查找右孩子*/
/* 返回e的右孩子。若e无右孩子,则返回＂空＂ */
TelemType RightChild(SqBitree T, TelemType e)
{
    int i;
    if (T[0] == nil) /* 空树 */
        return nil;
    for (i = 0; i <= MAX_TREE_SIZE_ - 1; i++) /* T[0]为根结点，从T[0]开始 */
        if (T[i] == e)                        /* 找到e */
            return T[i * 2 + 2];
    return nil; /* 没找到e */
}

/* 查找左兄弟 */
/* 返回e的左兄弟。若e是T的左孩子或无左兄弟,则返回＂空＂ */
TelemType LeftSibling(SqBitree T, TelemType e)
{
    int i;
    if (T[0] == nil) /* 空树 */
        return nil;
    for (i = 1; i <= MAX_TREE_SIZE_ - 1; i++)
        if (T[i] == e && i % 2 == 0) /* 找到e且其序号为偶数(是右孩子) */
            return T[i - 1];
    return nil; /* 没找到e */
}

/* 查找右兄弟 */
/* 返回e的右兄弟。若e是T的右孩子或无右兄弟,则返回＂空＂ */
TelemType RightSibling(SqBitree T, TelemType e)
{
    int i;
    if (T[0] == nil) /* 空树 */
        return nil;
    for (i = 1; i <= MAX_TREE_SIZE_ - 1; i++)
        if (T[i] == e && i % 2 != 0) /* 找到e且其序号为奇数(是左孩子) */
            return T[i + 1];
    return nil; /* 没找到e */
}

Status b;
Position p;
TelemType ee;
SqBitree t;

void showParent()
{
    InitBiTree(t);
    CreateBiTree(t);
    int x;
    printf("请输入结点的位置(1~11的整数):");
    scanf("%d", &x);
    printf("结点%d的双亲为%d", x, Parent(t, x));
}

void showBrother()
{
    InitBiTree(t);
    CreateBiTree(t);
    int x;
    printf("请输入结点的位置(1~11的整数):");
    scanf("%d", &x);
    printf("结点%d左兄弟为%d\n", x, LeftSibling(t, x));
    printf("结点%d右兄弟为%d", x, RightSibling(t, x));
}

void showChild()
{
    InitBiTree(t);
    CreateBiTree(t);
    int x;
    printf("请输入结点的位置(1~11的整数):");
    scanf("%d", &x);
    printf("结点%d的左右孩子分别为:%d  %d\n", x, LeftChild(t, x), RightChild(t, x));
}