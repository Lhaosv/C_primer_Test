#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(poly)
typedef struct term
{
    int coef;
    int expn;
    struct term *next;
} poly, *link;
void createpolyn(link *p, int m);
void printpolyn(link p);
int cmp(link p1, link p2);
link addpolyn(link pa, link pb);

void showyingyong1()
{
    link p1, p2;
    int l1, l2;
    printf("请输入第一个多项式的项数:");
    scanf("%d", &l1);
    createpolyn(&p1, l1);
    printf("第一个多项式为:");
    printpolyn(p1);
    printf("请输入第二个多项式的项数:");
    scanf("%d", &l2);
    createpolyn(&p2, l2);
    printf("第二个多项式为:");
    printpolyn(p2);
    printf("\n");
    printf("两个多项式相加的结果为：");
    printpolyn(addpolyn(p1, p2));
}

void createpolyn(link *p, int m)
{
    link r, s;
    int i;
    *p = (link)malloc(LEN);
    r = *p;
    for (i = 0; i < m; i++)
    {
        s = (link)malloc(LEN);
        printf("请输入系数和指数（以空格隔开）:");
        scanf("%d %d", &s->coef, &s->expn);
        r->next = s;
        r = s;
    }
    r->next = NULL;
}
void printpolyn(link p)
{
    link s;
    s = p->next;
    while (s)
    {
        printf("%d X^%d", s->coef, s->expn);
        s = s->next;
        if (s != NULL)
            if (s->coef >= 0)
                printf("+");
    }
    printf("\n");
}
int cmp(link a, link b)
{
    if (a->expn < b->expn)
        return -1;
    else if (a->expn == b->expn)
        return 0;
    else
        return 1;
}
link addpolyn(link pa, link pb)
{
    link newp, p, q, s, pc;
    float sum;
    p = pa->next;
    q = pb->next;
    newp = (link)malloc(LEN);
    pc = newp;
    while (p && q)
    {
        switch (cmp(p, q))
        {
        case -1:
            s = (link)malloc(LEN);
            s->coef = p->coef;
            s->expn = p->expn;
            pc->next = s;
            pc = s;
            p = p->next;
            break;
        case 0:
            sum = p->coef + q->coef;
            if (sum != 0.00)
            {
                s = (link)malloc(LEN);
                s->coef = sum;
                s->expn = p->expn;
                pc->next = s;
                pc = s;
            }
            p = p->next;
            q = q->next;
            break;
        case 1:
            s = (link)malloc(LEN);
            s->coef = q->coef;
            s->expn = q->expn;
            pc->next = s;
            pc = s;
            q = q->next;
            break;
        }
    }
    while (p)
    {
        s = (link)malloc(LEN);
        s->coef = p->coef;
        s->expn = p->expn;
        pc->next = s;
        pc = s;
        p = p->next;
    }
    while (q)
    {
        s = (link)malloc(LEN);
        s->coef = q->coef;
        s->expn = q->expn;
        pc->next = s;
        pc = s;
        q = q->next;
    }
    pc->next = NULL;
    return newp;
}