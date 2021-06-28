#include <stdio.h>

int main()
{
    int a[10];
    int t;
    printf("请输入要排序的10个数字：");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\n");
    int i, j;
    for (j = 0; j < 9; j++)
    {
        for (i = 0; i < 9 - j; i++)
        {
            if (a[i] > a[i + 1])
            {
                t = a[i], a[i] = a[i + 1], a[i + 1] = t;
            }
        }
    }
    printf("排序后的数字为：\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}