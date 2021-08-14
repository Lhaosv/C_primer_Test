#include <stdio.h>
#include <string.h>
/*
strcpy(目的字符串，源字符串)，直接覆盖掉源字符串
strncpy(目的字符串，源字符串，n)，表示把源字符串中的前n个字符复制到目的字符串中的前n个，目的字符串的后面字符串还在。
*/
int main()
{
    char a[10] = "hello!";
    char b[10] = "wor";
    //printf("%s", strcpy(a, b));   // 结果：wor
    printf("%s", strncpy(a, b, 2)); // 结果：wollo!
}