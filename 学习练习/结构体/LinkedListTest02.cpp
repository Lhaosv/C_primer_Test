#include <stdio.h>
#include <stdlib.h>
/*
建立动态链表
*/
#define LEN sizeof(struct Student) // 宏定义 struct Student 类型数据的长度
struct Student
{
    int num;
    char name[10];
    struct Student *next;
};
int n;
//创建链表的函数：
struct Student *creat()
{
    struct Student *head, *p1, *p2;
    n = 0;
    p1 = p2 = (struct Student *)malloc(LEN); //开辟第一个struct Student结点，并使p1 p2 指向它
    printf("请输入学号，姓名：\n");
    scanf("%d %s", &p1->num, p1->name); //读入第一个学生的数据给p1所指的第一个结点
    head = NULL;
    while (p1->num != 0) //当学号不为0时连接创建的结点
    {
        n = n + 1;
        if (n == 1)
        {
            head = p1; // 头结点也指向第一个结点
        }
        else
            p2->next = p1;                  //使第一个结点的next成员指向第二个结点，即连接第一个节点和第二个结点
        p2 = p1;                            //使p2也指向刚才新建立的那个结点
        p1 = (struct Student *)malloc(LEN); //继续开辟下一个新节点
        printf("请输入学号，姓名：\n");
        scanf("%d %s", &p1->num, p1->name);
    }
    p2->next = NULL; // p2结点始终指向末尾
    return head;     // 所有结点连接完成，返回头结点
}
int main()
{
    struct Student *pt;
    pt = creat();
    printf("学号   姓名\n");
    while (pt != NULL)
    {
        printf("%-6d%s\n", pt->num, pt->name);
        pt = pt->next;
    }
}