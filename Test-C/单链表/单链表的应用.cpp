//链式存储实现多项式加法
#include <stdio.h>
#include <stdlib.h>

//重定义类型和声明函数
typedef struct Node *PNode;
typedef struct Node *LinkList;
typedef int Datatype;
struct Node
{
    Datatype coe;
    Datatype ind;
    struct Node *next;
};
PNode Add_POLYA(LinkList head1, LinkList head2);

LinkList setnulllist_link()
{
    LinkList head = (LinkList)malloc(sizeof(struct Node));
    if (head != NULL)
        head->next = NULL;
    else
        printf("alloc failure");
    return head;
}

void createlist_tail(struct Node *head)
{
    PNode p = NULL;
    PNode q = head;
    Datatype coe;
    Datatype ind;
    printf("please input coefficient and index:\n");
    scanf("%d,%d", &coe, &ind);
    while ((coe != 0) || (ind != 0))
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->coe = coe;
        p->ind = ind;
        p->next = NULL;
        q->next = p;
        q = p;
        scanf("%d,%d", &coe, &ind);
    }
    return;
}

void print(LinkList head)
{
    PNode p = head->next;
    while (p != NULL)
    {
        if (p->next != NULL)
        {
            printf("%d,%d ", p->coe, p->ind);
        }
        else
        {
            printf("%d,%d ", p->coe, p->ind);
        }
        p = p->next;
    }
    return;
}

void destorylist_link(LinkList head)
{
    PNode pre = head;
    PNode p = pre->next;
    while (p)
    {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
    return;
}

int main()
{
    LinkList head1 = NULL, head2 = NULL;
    head1 = setnulllist_link();
    head2 = setnulllist_link();
    createlist_tail(head1);
    createlist_tail(head2);
    Add_POLYA(head1, head2);
    print(head1);
    destorylist_link(head1);
    system("pause");
    return 0;
}

PNode Add_POLYA(LinkList head1, LinkList head2)
{
    PNode pre = NULL, p = NULL, qre = NULL, q = NULL;
    pre = head1;
    p = head1->next;
    qre = head2;
    q = head2->next;
    if (qre == NULL)
    {
        return head1;
    }
    while (p != NULL)
    {
        if (q == NULL)
        {
            return head1;
        }
        //两项和为0时
        if (p->ind == q->ind)
        {
            p->coe = q->coe + p->coe;
            if (p->coe == 0)
            {
                pre->next = p->next;
                free(p);
                p = pre->next;
                qre->next = q->next;
                free(q);
                q = qre->next;
            }
            else
            {
                pre = p;
                p = p->next;
                qre->next = q->next;
                free(q);
                q = qre->next;
            }
        }
        //多项式1的项的指数大于多项式2的项时
        else if (p->ind > q->ind)
        {
            qre->next = q->next;
            q->next = p;
            pre->next = q;
            pre = q;
            q = qre->next;
        }
        //多项式2的项指数大小在多项式1的项与下一项中间时
        else if (q->ind > p->ind && q->ind < (p->next)->ind)
        {
            qre->next = q->next;
            pre = p;
            p = p->next;
            q->next = p;
            pre->next = q;
            pre = q;
            q = qre->next;
        }
        else if (q->ind > p->ind && q->ind >= (p->next)->ind)
        {
            pre = p;
            p = p->next;
        }
    }

    return head1;
}
