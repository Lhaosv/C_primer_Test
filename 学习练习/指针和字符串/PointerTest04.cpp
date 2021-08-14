#include <stdio.h>
#include <stdlib.h>
/*
通过指针进对字符串数组进行复制
*/
int main()
{
    char a[] = "I am Chinese!", b[20], *p1, *p2;
    p1 = a, p2 = b;
    printf("a数组为：%s \n", a); //%s直接输出整个字符串
    for (; *p1 != '\0'; p1++, p2++)
    {
        *p2 = *p1;
    }
    printf("b数组为：");
    for (p2 = b; *p2 != '\0'; p2++)
    {
        printf("%c", *p2);
    }
    printf("\n");
}