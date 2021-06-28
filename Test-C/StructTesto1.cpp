#include <stdio.h>
#include <string.h>

/*
定义一个结构体，用于存放学号，姓名，三科成绩
*/
struct stu
{
    int num;
    char name[30];
    float score[3];
};

struct stu boy; //定义一个变量名为boy的结构体
void print(struct stu);

//定义一个print函数（方法）,用于输出学号，姓名，成绩，参数为结构体类型
void print(struct stu)
{
    printf("学号：%d\n", boy.num);
    printf("姓名：%s\n", boy.name);
    for (int i = 0; i < 3; i++)
    {
        printf("成绩：%f\n", boy.score[i]);
    }
}
int main(int argc, char const *argv[])
{
    boy.num = 101;
    strcpy(boy.name, "张三");
    boy.score[0] = 98.0;
    boy.score[1] = 99.0;
    boy.score[2] = 100.0;
    print(boy); //将结构体变量名作为参数传入函数print中

    return 0;
}
