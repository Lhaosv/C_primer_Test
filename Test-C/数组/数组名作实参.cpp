#include <stdio.h>
/*
数组长度不同时，数组名做实参
*/
int main()
{
    float average(int a[], int n);
    int x[5] = {1, 6, 5, 8, 9};
    int y[10] = {2, 36, 14, 25, 88, 11, 15, 65, 47, 10};
    float aver1, aver2;
    aver1 = average(x, 5);
    aver2 = average(y, 10);
    printf("第一组的平均数是：%f\n", aver1);
    printf("第二组的平均数是：%f\n", aver2);
}

float average(int a[], int n)
{
    float aver;
    int i, sum = a[0];
    for (i = 1; i < n; i++)
    {
        sum = sum + a[i];
    }
    aver = sum / n;
    return aver;
}