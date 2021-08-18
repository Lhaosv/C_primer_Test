#include <ctype.h>
#include <stdio.h> //  字符函数，专门用来处理字符的函数，ctype.h头文件中包含了这些函数的原型。
int main()
{
    char ch;
    ch = getchar(); //只处理字符，他从输入队列中返回下一个元素
    while (ch != '\n')
    {
        ch = toupper(ch); //  ctype.h 头文件中的函数，将小写字母转换成大写字母
        putchar(ch);      // 一次只能打印一个字符
        ch = getchar();
    }
    putchar(ch); // 此时跳出while循环，ch = '\n'，即打印换行符
    return 0;
}