#include <stdio.h>
#include <string.h>

int main()
{
    char str[3][10];
    char string[10];
    int i;
    printf("请输入三个字符串：\n");
    for (i = 0; i < 3; i++)
    {
        gets(str[i]); // 键盘输入一个字符串按一次回车输入下一个字符串
    }
    if (strcmp(str[0], str[1]) < 0)
    {
        strcpy(string, str[1]);
    }
    else
        strcpy(string, str[0]);
    if (strcmp(string, str[2]) < 0)
    {
        strcpy(string, str[2]);
    }
    printf("最大的字符串为：\n");
    printf("%s", string);
    return 0;
}