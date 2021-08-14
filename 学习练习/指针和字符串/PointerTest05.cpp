#include <stdio.h>
#include <stdlib.h>
int main()
{
    void string_copy(char from[], char to[]);
    void string_copy2(char *from, char *to);
    char a[] = "I am a student!";
    char b[] = "You are a teacher!";
    //也可以这也定义a b字符串数组：
    //char *a = "I am a student!";
    //char *b = "You are a teacher!";
    char *p1 = a, *p2 = b;
    printf("复制之前a为；%s\nb为：%s\n", a, b);
    printf("把a复制到b之后：\n");
    //string_copy(a, b);
    string_copy2(p1, p2);
    printf("a为：%s\nb为：%s\n", a, b);
}
//参数为数组时候：
void string_copy(char from[], char to[])
{
    int i = 0;
    while (from[i] != '\0')
    {
        to[i] = from[i];
        i++;
    }
    to[i] = '\0';
}
//参数为指针变量的时候：
void string_copy2(char *from, char *to)
{
    while (*from != '\0')
    {
        *to = *from;
        from++, to++;
    }
    *to = '\0';
}