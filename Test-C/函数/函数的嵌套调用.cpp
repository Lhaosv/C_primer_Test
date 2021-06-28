#include <stdio.h>
/*
给出四个数，通过函数的嵌套调用，输入四个数中最大的数
*/
int main()
{
    int max4(int a, int b, int c, int d);
    int x, y, z, w, max;
    printf("请输入4个数字：\n");
    scanf("%d %d %d %d", &x, &y, &z, &w);
    max = max4(x, y, z, w);
    printf("最大的数是：%d\n", max);
}

int max4(int a, int b, int c, int d)
{
    int m;
    int max2(int a, int b);
    m = max2(a, b);
    m = max2(m, c);
    m = max2(m, d);
    return m;
}

int max2(int a, int b)
{
    int max(int a, int b);
    return (max(a, b));
}
int max(int a, int b)
{
    return (a > b ?: a, b);
}
