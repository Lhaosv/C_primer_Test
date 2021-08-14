#include <stdio.h>
#include <stdlib.h>
/*
形参是数组时，指针变量作实参
*/
int main()
{
    void fun(int *x, int n);
    int arr[10], i;
    int *p;
    p = arr;
    printf("请输入10个数字：\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("互换之后的数为：\n");
    fun(p, 10); //将指针变量p作实参传入，p为数组首元素地址。
    for (p = arr; p < arr + 10; p++)
    {
        printf("%d ", *p);
    }
    return 0;
}
void fun(int x[], int n) //形参时数组
{
    int *i, *j, temp;
    i = x, j = x + (n - 1); //i表示数组首元素地址，j表示数组n-1号元素地址，也就是数组最后一个元素的地址。
    for (; i < j; i++, j--)
    {
        temp = *i, *i = *j, *j = temp;
    }
}