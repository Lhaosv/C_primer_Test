#include "math.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>

typedef int Status;
typedef int ElemType;

//定义结点类型：
typedef struct Lnode
{
    ElemType data;      //单链表中的数据域
    struct Lnode *next; //单链表中的指针域
} Lnode, *Linklist;
// *相当于定义了 (struct Lnode *) 为 Linklist，所以Linklist是 Lnode的指针
// 即 *Linklist 为 Lnode * xxx;

//单链表的初始化：
Status InitList(Linklist *list)
{
    (*list) = (Linklist)malloc(sizeof(Lnode));
    if (!(*list))
        return 0;
    (*list)->next = NULL;
    return 1;
}

//单链表的建立1，头插法建立：
Status LinklistCreatH(Linklist *list, int elemNum)
{
    srand(time(0));
    Linklist insertNodePoint, endNodePoint;
    endNodePoint = (*list)->next;
    while (endNodePoint)
    {
        insertNodePoint = (Linklist)malloc(sizeof(Lnode));
        if (!insertNodePoint)
            return 0;
        insertNodePoint->data = rand() * 100 + 1;
        insertNodePoint->next = endNodePoint;
        (*list)->next = insertNodePoint;
    }
    return 1;
}

//单链表的建立2，尾插法建立：
Linklist LinklistCreatT()
{
    Lnode *L;
    L = (Linklist)malloc(sizeof(Lnode)); //申请头结点空间
    L->next = NULL;                      //初始化一个空链表
    Lnode *r;
    r = L; // r始终指向终端结点，初始时指向头结点
    ElemType x;
    while (scanf("%d", &x) != EOF)
    {
        Lnode *p;
        p = (Linklist)malloc(sizeof(Lnode));
        p->data = x;
        r->next = p;
        r = p;
    }
    r->next = NULL;
    return L;
}

//单链表的插入，在链表的第i个位置插入x的元素：
Linklist LinklistInsert(Linklist L, int i, ElemType x)
{
    Lnode *pre; //pre为前驱结点
    pre = L;
    int j = 0;
    for (j = 1; j < i; j++)
    {
        pre = pre->next; //查找第i个元素的前驱结点
    }
    Lnode *p; //插入的结点为p
    p = (Linklist)malloc(sizeof(Lnode));
    p->data = x;
    p->next = pre->next;
    pre->next = p;
    return L;
}

Status PrintList(Linklist list)
{
    Linklist currentNodePoint = list->next;
    while (currentNodePoint)
    {
        printf("%d ", currentNodePoint->data);
        currentNodePoint = currentNodePoint->next;
    }
    return 1;
}

//单链表的删除，在链表中删除值为x的元素
// Linklist LinklistDelete(Linklist L, ElemType x)
// {
//     Lnode *pre, *p; //pre为前驱结点，p为要删除的结点
//     while (p && p->data != x)
//     {
//         pre = p;
//         p = p->next;
//     }
//     pre->next = p->next; // 将其前驱指向其后继
//     free(p);             // 删除结点p
//     return L;
// }

int main()
{
    // Linklist list, start;
    // printf("请输入单链表的数据：");
    // LinklistCreatH(list, 5);
    // for (start = list->next; start != NULL; start = start->next)
    // {
    //     printf("%d\n", start->data);
    // }
    // int i;
    // ElemType x;
    // printf("请输入要插入数据的位置：");
    // scanf("%d", &i);
    // printf("\n");
    // printf("请输入要插入的数据：");
    // scanf("%d", &x);
    // printf("\n");
    // LinklistInsert(list, i, x);
    // for (start = list->next; start != NULL; start = start->next)
    // {
    //     printf("%d\n", start->data);
    // }
    // printf("请输入要删除元素的值：");
    // scanf("%d", &x);
    // printf("\n");
    // LinklistDelete(list, x);
    // for (start = list->next; start != NULL; start = start->next)
    // {
    //     printf("%d\n", start->data);
    // }
    Linklist list;
    printf("%d\n", InitList(&list));

    printf("%d\n", LinklistCreatH(&list, 5));
    printf("%d\n", PrintList(list));

    return 0;
}
