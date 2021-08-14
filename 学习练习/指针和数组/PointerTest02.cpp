#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int *p, i;
    for (p = a[0]; p < a[0] + 12; p++) //一共有12个元素
    {
        if ((p - a[0]) % 4 == 0) //控制换行
        {
            printf("\n");
        }
        printf("%4d", *p);
    }
    printf("\n");
    printf("%d", (p - a[0]));
    return 0;
}