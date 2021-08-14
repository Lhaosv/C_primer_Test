#include <stdio.h>
/*
用指向结构体变量的指针作实参，将结构体变量（或数组元素的地址）传递给形参
*/
struct Student
{
    int num;
    char name[10];
    int score[3];
    float aver;
};
int main()
{
    void input(struct Student stu[]);
    struct Student max(struct Student stu[]);
    void print(struct Student stud);
    struct Student stu[3], *p; //定义一个结构体类型数组和一个结构体类型指针变量
    p = stu;                   // 结构体指针变量p指向结构体数组
    input(p);
    print(max(p));
}
void input(struct Student stu[])
{
    printf("请输入三名学生的学号，姓名，成绩：\n");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d %s %d %d %d", &stu[i].num, stu[i].name, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
        stu[i].aver = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3;
    }
}
struct Student max(struct Student stu[])
{
    int m = 0;
    for (int i = 0; i < 3; i++)
    {
        if (stu[i].aver > stu[m].aver)
        {
            m = i;
        }
    }
    return stu[m];
}
void print(struct Student stud)
{
    printf("平均分最高的学生是：%s\n", stud.name);
    printf("成绩分别为：%-5d%-5d%-5d   平均分为：%5.2f", stud.score[0], stud.score[2], stud.score[2], stud.aver);
}
