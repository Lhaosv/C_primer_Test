#include <stdio.h>
/*
静态链表
*/
struct Student
{
    int num;
    int score;
    struct Student *next;
};
int main()
{
    struct Student a, b, c, *head, *p;
    a.num = 101, a.score = 97;
    b.num = 102, b.score = 94;
    c.num = 103, c.score = 99;
    head = &a;
    a.next = &b;
    b.next = &c;
    c.next = NULL;
    p = head;
    while (p != NULL)
    {
        printf("%-6d%-5d\n", p->num, p->score);
        p = p->next;
    }
}