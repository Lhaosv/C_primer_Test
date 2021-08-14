#include <stdio.h>
#include <string.h>
/*
结构体数组
*/
int main()
{
    int i, j;
    char leader_name[10];
    struct Person
    {
        char name[10];
        int count;
    } leader[3] = {"张三", 0, "李四", 0, "王五", 0}; //定义了一个结构体类型数组leader【3】
    printf("请输入你要投票人的姓名（10次）:\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%s", leader_name);
        for (j = 0; j < 3; j++)
        {
            if (strcmp(leader_name, leader[j].name) == 0)
            {
                leader[j].count++;
            }
        }
    }
    printf("张三：%d\n", leader[0].count);
    printf("李四：%d\n", leader[1].count);
    printf("王五：%d\n", leader[2].count);
}