#include <stdio.h>
/*
运用函数递归的调用求n的阶乘
*/
int main()
{
    int fac(int n);
    int x, y;
    printf("请输入一个非负整数:\n");
    scanf("%d", &x);
    while (x < 0)
    {
        printf("输入的值有误，请输入非负整数：\n");
        scanf("%d", &x);
    }

    y = fac(x);
    printf("%d 的阶乘是：%d\n", x, y);
}

int fac(int n)
{
    int f;
    if (n == 0 || n == 1)
        f = 1;
    else
        f = fac(n - 1) * n;
    return f;
}