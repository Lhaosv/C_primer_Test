#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;
typedef int SElemType;

typedef struct
{
    SElemType data[MAXSIZE];
    int top; /* 用于栈顶指针 */
} SqStack;

Status visit2(SElemType c)
{
    printf("%d ", c);
    return OK;
}

/* 从栈底到栈顶依次对栈中每个元素显示 */
Status StackTraverse(SqStack S)
{
    int i;
    i = 0;
    while (i <= S.top)
    {
        visit2(S.data[i++]);
    }
    printf("\n");
    return OK;
}

/*  构造一个空栈S */
Status InitStack(SqStack *S)
{
    S->top = -1;
    return OK;
}

int StackLength(SqStack S)
{
    return S.top + 1;
}

/* 插入元素e为新的栈顶元素 (入栈)*/
Status Push(SqStack *S, SElemType e)
{
    if (S->top == MAXSIZE - 1) /* 栈满 */
    {
        return ERROR;
    }
    S->top++;            /* 栈顶指针增加一 */
    S->data[S->top] = e; /* 将新插入元素赋值给栈顶空间 */
    return OK;
}

/* 若栈不空，删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR (出栈)*/
Status Pop(SqStack *S, SElemType *e)
{
    if (S->top == -1)
        return ERROR;
    *e = S->data[S->top]; /* 将要删除的栈顶元素赋值给e */
    S->top--;             /* 栈顶指针减一 */
    return OK;
}

/* 若栈不空，用e返回S的栈顶元素，并返回OK；否则返回ERROR(读取栈顶元素) */
Status GetTop(SqStack S, SElemType *e)
{
    if (S.top == -1)
        return ERROR;
    else
        *e = S.data[S.top];
    return OK;
}

int j;
SqStack s;
int e;

void showPush()
{
    if (InitStack(&s) == OK)
        for (j = 1; j <= 10; j++)
            Push(&s, j);
    printf("栈中元素依次为：");
    StackTraverse(s);
}

void showPop()
{
    Pop(&s, &e);
    printf("弹出的栈顶元素 e=%d\n", e);
    StackTraverse(s);
}

void showGetTop()
{
    GetTop(s, &e);
    printf("栈顶元素 e=%d 栈的长度为%d\n", e, StackLength(s));
}