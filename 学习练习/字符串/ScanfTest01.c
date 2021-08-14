#include <stdio.h>
#define String "hello world"
int main()
{
    char name[20];
    printf("what is your name:\n");
    scanf("%s", name);
    printf("hello,%s  %s", name, String);
}