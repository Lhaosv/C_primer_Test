#include <stdio.h>
/*
输入a，b两个整数
不交换整型变量的值，而是交换两个指针变量的值
*/
int main()
{
    int a, b;
    int *p1, *p2, *p; //定义三个指针变量
    printf("请输入两个整数：");
    scanf("%d %d", &a, &b);
    p1 = &a; // 把a的地址赋给p1，p1指向a
    p2 = &b; // 把b的地址赋给p2，p2指向b
    if (a < b)
    {
        // p = p1, p1 = p2, p2 = p; //交换，p1指向b，p2指向a
        p1 = &b, p2 = &a; //结果和上面一样
    }
    printf("a = %d,b = %d\n", a, b);
    printf("%d,%d \n", *p1, *p2);
    return 0;
}