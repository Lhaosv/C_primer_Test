#include <stdio.h>
/*
    1、char 和 short类型出现在表达式或作为函数的参数时，都会被升级为int类型
    2、float类型在函数参数中时，会被升级为double类型
*/
void print(int n); //函数原型声明(也可以放在main函数开头)
int main()
{
    int times = 5;
    float f = 6.0;
    char c = '!';
    print(times);
    print(f); // 因为程序开头有函数原型声明，使得float类型被转换成合适的类型
    print(c);
    return 0;
}
void print(int n)
{
    while (n-- > 0)
    {
        printf("#");
    }
    printf("\n");
}