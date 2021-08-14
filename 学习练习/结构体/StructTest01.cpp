#include <stdio.h>
int main()
{
    struct student
    {
        int num;
        char name[20];
        float score;
    } student1, student2;
    printf("请输入两个学生的学号，姓名，分数：\n");
    scanf("%d %s %f", &student1.num, student1.name, &student1.score);
    scanf("%d %s %f", &student2.num, student2.name, &student2.score);
    printf("二者中分数较高的学生是：\n");
    if (student1.score > student2.score)
    {
        printf(student1.name);
    }
    if (student1.score < student2.score)
    {
        printf(student2.name);
    }
    else
        printf("%s和%s分相同", student1.name, student2.name);
}