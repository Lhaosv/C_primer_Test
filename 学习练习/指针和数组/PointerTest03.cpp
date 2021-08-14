#include <stdio.h>
#include <stdlib.h>
int main()
{
    void average(int *p, int n);
    void search(int(*p)[4], int n); // 行指针
    int score[3][4] = {{71, 58, 60, 78}, {65, 96, 74, 57}, {88, 97, 99, 92}};
    average(*score, 12); // *scoer 表示 score[0][0]的地址
    search(score, 2);    // score 表示 score[0]的地址（也就是二维数组首行地址）
}
void average(int *p, int n)
{
    int *p_end;
    int sum = 0;
    float aver;
    p_end = p + n - 1;
    for (; p <= p_end; p++)
    {
        sum = sum + (*p);
    }
    aver = sum / n;
    printf("平均成绩为：%f\n", aver);
}
void search(int (*p)[4], int n)
{
    int i;
    printf("编号为%d学生的成绩为：\n", n);
    for (i = 0; i < 4; i++)
    {
        printf("%d ", *(*(p + n) + i));
    }
    printf("\n");
}