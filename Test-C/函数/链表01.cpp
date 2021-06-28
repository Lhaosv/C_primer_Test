#include <stdio.h>

struct stu
{
    int num;
    int score;
    struct stu *next;
};
int main(int argc, char const *argv[])
{
    struct stu a, b, c, *head;
    a.num = 101;
    a.score = 98;
    b.num = 102;
    b.score = 99;
    c.num = 103;
    c.score = 100;

    head = &a;
    a.next = &b;
    b.next = &c;
    c.next = NULL;
    while (head)
    {
        printf("学号:%d  成绩：%d\n", head->num, head->score);
        head = head->next;
    }

    return 0;
}
