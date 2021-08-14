#include <stdio.h>
#include <string.h>
/*
结构体指针变量和结构体数组
*/
struct Student
{
    int num;
    char name[10];
    char sex;
    int age;
} stu[3] = {{101, "zhangsan", 'M', 18}, {102, "lisi", 'M', 19}, {103, "wangwu", 'W', 17}};
int main()
{
    struct Student *p;
    printf("学号   姓名          性别   年龄   \n");
    for (p = stu; p < stu + 3; p++)
    {
        printf("%-6d%-16s%-7c%d\n", p->num, p->name, p->sex, p->age);
    }
}