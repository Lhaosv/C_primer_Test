#include <stdio.h>
/*
通过传入指针变量，调用函数，交换两个变量的值
*/
int main()
{
    void swap(int *p1, int *p2);
    int a, b;
    int *ponit_1, *ponit_2;
    printf("请输入两个整数：");
    scanf("%d %d", &a, &b);
    ponit_1 = &a;
    ponit_2 = &b;
    if (a < b)
    {
        swap(ponit_1, ponit_2);
    }
    printf("max is : %d, min is : %d", *ponit_1, *ponit_2);
    return 0;
}

void swap(int *p1, int *p2)
{
    int temp;
    temp = *p1; //实际上交换的是a，b
    *p1 = *p2;
    *p2 = temp;
    return;
}