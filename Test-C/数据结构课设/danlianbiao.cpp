#include "ctype.h"
#include "math.h"
#include "string.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int Status;
typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;
typedef struct Node *LinkList;

// LinkList L;
// ElemType e;
// Status i;

//初始化单链表：
Status InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
    if (!(*L))                           /* 存储分配失败 */
        return ERROR;
    (*L)->next = NULL; /* 指针域为空 */

    return OK;
}
Status visit(ElemType c)
{
    printf("%d ", c);
    return OK;
}

/* 初始条件：链式线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(LinkList L)
{
    int i = 0;
    LinkList p = L->next; /* p指向第一个结点 */
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}

//单链表的创建：
/*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） */
void CreateListHead(LinkList *L, int n)
{
    LinkList p;
    int i;
    srand(time(0)); /* 初始化随机数种子 */
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL; /*  先建立一个带头结点的单链表 */
    for (i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node)); /*  生成新结点 */
        p->data = rand() % 100 + 1;         /*  随机生成100以内的数字 */
        p->next = (*L)->next;
        (*L)->next = p; /*  插入到表头 */
    }
}

//单链表的插入：
/* 初始条件：链式线性表L已存在,1≤i≤ListLength(L)， */
/* 操作：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(LinkList *L, int i, ElemType e)
{
    int j;
    LinkList p, s;
    p = *L;
    j = 1;
    while (p && j < i) /* 寻找第i个结点 */
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ERROR;                   /* 第i个元素不存在 */
    s = (LinkList)malloc(sizeof(Node)); /*  生成新结点 */
    s->data = e;
    s->next = p->next; /* 将p的后继结点赋值给s的后继  */
    p->next = s;       /* 将s赋值给p的后继 */
    return OK;
}

//单链表的删除：
/* 初始条件：链式线性表L已存在，1≤i≤ListLength(L) */
/* 操作：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(LinkList *L, int i, ElemType *e)
{
    int j;
    LinkList p, q; /*p表示要删除结点的前驱结点，q表示要删除的结点*/
    p = *L;
    j = 1;
    while (p->next && j < i) /* 遍历寻找第i个元素 */
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i)
        return ERROR; /* 第i个元素不存在 */
    q = p->next;
    p->next = q->next; /* 将q的后继赋值给p的后继 */
    *e = q->data;      /* 将q结点中的数据给e */
    free(q);           /* 让系统回收此结点，释放内存 */
    return OK;
}

Status ListTraverse(LinkList L)
{
    LinkList p = L->next;
    while (p)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

//单链表的查找：
/* 初始条件：链式线性表L已存在，1≤i≤ListLength(L) */
/* 操作：查找单链表中的某个元素 ，并返回该元素再线性表中的位置i */
Status ListSearch(LinkList L, int e)
{
    int i = 0;
    LinkList p = L->next;
    while (p)
    {
        i++;
        if (p->data == e) /* 找到这样的数据元素 */
            return i;
        p = p->next;
    }

    return 0;
}

void showCreat()
{
    LinkList L;
    ElemType e;
    Status i;
    int j, k;
    i = InitList(&L);
    printf("初始化L后：ListLength(L)=%d\n", ListLength(L));
}

void showInsert()
{
    LinkList L;
    ElemType e;
    Status i;
    int j, k;
    int n;
    i = InitList(&L);
    for (j = 1; j <= 5; j++)
        i = ListInsert(&L, 1, j);
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverse(L);
    i = ListInsert(&L, 3, 7);
    printf("在第3个位置插入 7 后：L.data=");
    ListTraverse(L);
}

void showDelete()
{
    LinkList L;
    ElemType e;
    Status i;
    int j, k;
    int n;
    i = InitList(&L);
    for (j = 1; j <= 5; j++)
        i = ListInsert(&L, 1, j);
    i = ListInsert(&L, 3, 7);
    int num3;
    printf("请输入要删除的元素位置：\n");
    scanf("%d", &num3);
    i = ListDelete(&L, num3, &e); /* 删除用户输入的数据 */
    if (i == ERROR)
        printf("删除数据失败\n");
    else
        printf("删除第%d个的元素值为：%d\n", num3, e);
    printf("依次输出L的元素：");
    ListTraverse(L);
}

void showSearch()
{
    LinkList L;
    ElemType e;
    Status i;
    int j, k;
    int n;
    i = InitList(&L);
    for (j = 1; j <= 5; j++)
        i = ListInsert(&L, 1, j);
    int num4;
    printf("请输入要查找的数据：\n");
    scanf("%d", &num4);
    i = ListSearch(L, num4);
    if (i)
        printf("元素%d的位置是：第%d个\n", num4, i);
    else
        printf("没有找到该元素！");
}