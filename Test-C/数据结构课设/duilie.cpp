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
typedef int QElemType;
/* 循环队列的顺序存储结构 */
typedef struct
{
    QElemType data[MAXSIZE];
    int front; /* 头指针 */
    int rear;  /* 尾指针，若队列不空，指向队列尾元素的下一个位置 */
} SqQueue;

Status visit3(QElemType c)
{
    printf("%d ", c);
    return OK;
}

/* 返回Q的元素个数，也就是队列的当前长度 */
int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

/* 初始化一个空队列Q */
Status InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

/* 若队列未满，则插入元素e 为Q新的队尾元素 (入列)*/
Status InQueue(SqQueue *Q, QElemType e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front) /* 队列满的判断 */
        return ERROR;
    Q->data[Q->rear] = e;              /* 将元素e赋值给队尾 */
    Q->rear = (Q->rear + 1) % MAXSIZE; /* rear指针向后移一位置， */
                                       /* 若到最后则转到数组头部 */
    return OK;
}

/* 若队列不空，则删除Q中队头元素，用e返回其值 (出列)*/
Status OutQueue(SqQueue *Q, QElemType *e)
{
    if (Q->front == Q->rear) /* 队列空的判断 */
        return ERROR;
    *e = Q->data[Q->front];              /* 将队头元素赋值给e */
    Q->front = (Q->front + 1) % MAXSIZE; /* front指针向后移一位置， */
                                         /* 若到最后则转到数组头部 */
    return OK;
}

/* 若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR (取队头元素) */
Status GetHead(SqQueue Q, QElemType *e)
{
    if (Q.front == Q.rear) /* 判断队列是否空 */
        return ERROR;
    *e = Q.data[Q.front];
    return OK;
}

/* 若队列不空,则用e返回Q的队尾元素,并返回OK,否则返回ERROR (取队尾元素) */
Status GetReal(SqQueue Q, QElemType *e)
{
    if (Q.front == Q.rear) /* 判断队列是否空 */
        return ERROR;
    *e = Q.data[Q.rear - 1];
    return OK;
}

/* 从队头到队尾依次对队列Q中每个元素输出 */
Status QueueTraverse(SqQueue Q)
{
    int i;
    i = Q.front;
    while ((i + Q.front) != Q.rear)
    {
        visit3(Q.data[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
    return OK;
}

Status j3;
char c;
int i = 0, l;
QElemType d;
SqQueue Q;

static void showInqueue()
{
    InitQueue(&Q);
    printf("请输入整型队列元素(不超过%d个),-1为提前结束符: ", MAXSIZE - 1);
    do
    {
        scanf("%d", &d);
        //d = i + 100;
        if (d == -1)
            break;
        i++;
        InQueue(&Q, d);
    } while (i < MAXSIZE - 1);
    printf("队列长度为: %d\n", QueueLength(Q));
    printf("队列元素为：\n");
    QueueTraverse(Q);
}

static void showOutqueue()
{
    int num;
    QueueTraverse(Q);
    printf("请输入需要出列元素的个数:");
    scanf("%d", &num);
    for (l = 1; l <= num; l++)
    {
        OutQueue(&Q, &d);
    }
    printf("出列后队伍的长度为：%d\n", QueueLength(Q));
}

void showGetHead()
{
    QueueTraverse(Q);
    j3 = GetHead(Q, &d);
    if (j3)
        printf("现在队头元素为: %d\n", d);
}

void showGetReal()
{
    QueueTraverse(Q);
    j3 = GetReal(Q, &d);
    if (j3)
        printf("现在队尾元素为: %d\n", d);
}