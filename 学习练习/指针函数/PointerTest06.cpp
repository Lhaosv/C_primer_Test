#include <stdio.h>
#include <stdlib.h>
/*
函数指针
*/
int main()
{
    int max(int x, int y);
    int min(int x, int y);
    int a, b, c, n;
    int (*p)(int, int); // 定义一个函数指针，只能指向返回值为int类型，参数为两个int类型的函数
    printf("请输入两个整数：\n");
    scanf("%d %d", &a, &b); // scanf函数最好不要加 \n
    printf("请输入要进行的操作：1 表示求二者最大数，2 表示求二者最小数：\n");
    scanf("%d", &n);
    if (n == 1)
    {
        p = max; // 函数指针变量p指向max函数
    }
    else
        p = min;    // 函数指针变量p指向min函数
    c = (*p)(a, b); // 通过函数指针调用函数，这里不能看出p指向那个函数
    if (n == 1)
    {
        printf("二者最大数为：%d", c);
    }
    else
        printf("二者最大数为：%d", c);
}
int max(int x, int y)
{
    int z;
    if (x > y)
    {
        z = x;
    }
    else
        z = y;
    return z;
}
int min(int x, int y)
{
    int z;
    if (x > y)
    {
        z = y;
    }
    else
        z = x;
    return z;
}