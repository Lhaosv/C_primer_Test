#include "danlianbiao.cpp"
#include "danlianbiaoyingyong.cpp"
#include "duilie.cpp"
#include "erchashu.cpp"
#include "erchashuchazhao.cpp"
#include "tu.cpp"
#include "zhan.cpp"
#include <stdio.h>
void ShowMainMenu()
{
    printf("\n");
    printf("*******************算法与数据结构******************\n");
    printf("* 1  单链表的基本操作及应用                       *\n");
    printf("* 2  栈的基本操作及应用                           *\n");
    printf("* 3  队列的基本操作及应用                         *\n");
    printf("* 4  二叉树的基本操作及应用                       *\n");
    printf("* 5  图的基本操作及应用                           *\n");
    printf("* 6  退出                                         *\n");
    printf("***************************************************\n");
}

void Linklist()
{
    int n;
    do
    {
        printf("\n");
        printf("**************单链表的基本操作及应用***************\n");
        printf("* 1  创建                                         *\n");
        printf("* 2  插入                                         *\n");
        printf("* 3  删除                                         *\n");
        printf("* 4  查找                                         *\n");
        printf("* 5  应用                                         *\n");
        printf("* 6  退出                                         *\n");
        printf("***************************************************\n");
        printf("请选择：");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            //printf("--------创建单链表---------");
            showCreat();
            break;
        case 2:
            //printf("--------插入元素-------");
            showInsert();
            break;
        case 3:
            //printf("--------删除元素-------");
            showDelete();
            break;
        case 4:
            //printf("--------查找元素-------");
            showSearch();
            break;
        case 5:
            //printf("--------应用---------");
            showyingyong1();
            break;
        case 6:
            break;
        default:
            printf("ERROR!");
            break;
        }
    } while (n != 6);
}

void Stack()
{
    int n;
    do
    {
        printf("\n");
        printf("****************栈的基本操作及应用*****************\n");
        printf("* 1  进栈                                         *\n");
        printf("* 2  出栈                                         *\n");
        printf("* 3  取栈顶元素                                   *\n");
        // printf("* 4  应用                                         *\n");
        printf("* 4  退出                                         *\n");
        printf("***************************************************\n");
        printf("请选择：");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            //printf("--------进栈-------");
            showPush();
            break;
        case 2:
            //printf("--------出栈-------");
            showPop();
            break;
        case 3:
            //printf("--------取栈顶元素-------");
            showGetTop();
            break;
        // case 4:
        //     //printf("--------应用-------");
        //     //showyingyong2();
        //     break;
        case 4:
            break;
        default:
            printf("ERROR!");
            break;
        }
    } while (n != 4);
}

void Queue()
{
    int n;
    do
    {
        printf("\n");
        printf("*************队列的基本操作及应用**************\n");
        printf("* 1  入列                                     *\n");
        printf("* 2  出列                                     *\n");
        printf("* 3  取队头元素                               *\n");
        printf("* 4  取队尾元素                               *\n");
        // printf("* 5  应用                                     *\n");
        printf("* 5  退出                                     *\n");
        printf("***********************************************\n");
        printf("请选择：");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            //printf("---------入列-------");
            showInqueue();
            break;
        case 2:
            //printf("---------出列-------");
            showOutqueue();
            break;
        case 3:
            //printf("---------取队头元素-------");
            showGetHead();
            break;
        case 4:
            //printf("---------取队尾元素-------");
            showGetReal();
            break;
        // case 5:
        //     printf("---------应用-------");
        //     break;
        case 5:
            break;
        default:
            printf("ERROR!");
            break;
        }
    } while (n != 5);
}

void BITree()
{
    int n;
    do
    {
        printf("\n");
        printf("**************二叉树的基本操作及应用***************\n");
        printf("* 1  创建                                         *\n");
        printf("* 2  遍历（先/中/后）                             *\n");
        // printf("* 3  求结点个数                                   *\n");
        printf("* 3  求树的深度                                   *\n");
        printf("* 4  查找双亲                                     *\n");
        printf("* 5  查找兄弟（左/右）                            *\n");
        printf("* 6  查找孩子（左/右）                            *\n");
        // printf("* 7  应用                                         *\n");
        printf("* 7  退出                                         *\n");
        printf("***************************************************\n");
        printf("请选择：");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            //printf("---------创建--------");
            showcreatTree();
            break;
        case 2:
            //printf("---------遍历（先/中/后）-------");
            showbianli();
            break;
        // case 3:
        //     printf("---------求结点个数-------");
        //     break;
        case 3:
            //printf("---------求树的深度-------");
            showdepth();
            break;
        case 4:
            //printf("---------查找双亲-------");
            showParent();
            break;
        case 5:
            //printf("---------查找兄弟（左/右）-------");
            showBrother();
            break;
        case 6:
            //printf("---------查找孩子（左/右）-------");
            showChild();
            break;
        // case 8:
        //     //printf("---------应用-------");
        //     break;
        case 7:
            break;
        default:
            printf("ERROR!");
            break;
        }
    } while (n != 7);
}

void Graph()
{
    int n;
    do
    {
        printf("\n");
        printf("****************图的基本操作及应用*****************\n");
        printf("* 1  创建（邻接矩阵/邻接表）                      *\n");
        printf("* 2  遍历（深度/广度）                            *\n");
        printf("* 3  定位                                         *\n");
        // printf("* 4  找第一个邻接点                               *\n");
        // printf("* 5  找下一个邻接点                               *\n");
        printf("* 4  插入（点/边）                                *\n");
        printf("* 5  删除（点/边）                                *\n");
        // printf("* 6  应用                                         *\n");
        printf("* 6  退出                                         *\n");
        printf("***************************************************\n");
        printf("请选择：");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            //printf("---------创建（邻接矩阵/邻接表）-------");
            showCreattu();
            break;
        case 2:
            //printf("---------遍历（深度/广度）-------");
            shouwshendu();
            break;
        case 3:
            //printf("---------定位-------");
            showdingwei();
            break;
        // case 4:
        //     //printf("---------找第一个邻接点-------");
        //     showfirstdian();
        //     break;
        // case 5:
        //     //printf("---------找下一个邻接点-------");
        //     //shownextdian();
        //     break;
        case 4:
            //printf("---------插入（点/边）-------");
            showcharudian();
            break;
        case 5:
            //printf("---------删除（点/边）-------");
            showshanchudian();
            break;
        // case 6:
        //     //printf("---------应用-------");
        //     showinyong();
        //     break;
        case 6:
            break;
        default:
            printf("ERROR!");
            break;
        }
    } while (n != 6);
}

int main()
{
    int n;
    do
    {
        ShowMainMenu();
        printf("请选择：");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            Linklist();
            break;
        case 2:
            Stack();
            break;
        case 3:
            Queue();
            break;
        case 4:
            BITree();
            break;
        case 5:
            Graph();
            break;
        case 6:
            break;
        default:
            printf("ERROR!");
            break;
        }
    } while (n != 6);
    return 0;
}