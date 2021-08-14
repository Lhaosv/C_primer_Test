#include <stdio.h>
#include <stdlib.h>
/*
Putchar和getchar的使用
*/
int main()
{
    int ch;
    int i;
    while ((ch = getchar()) != EOF)
    {
        putchar(ch);
    }
    printf("请输入：");
    scanf("%d", &i);
    printf("%d", i);
    printf("EOF!");
}