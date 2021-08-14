/*qsorter.c -- 使用qsort()快速排序*/
#include <stdio.h>
#include <stdlib.h> //提供qsort()和rand()原型

#define NUM 40                              //数组长度
void fillarray(double ar[], int n);         //初始化数组的函数原型
void showarray(const double ar[], int n);   //打印数组内容的函数原型
int mycomp(const void *p1, const void *p2); //比较两项大小的函数原型

int main(void)
{
    double vals[NUM];     //声明double类型数组
    fillarray(vals, NUM); //初始化数组
    puts("Random list:");
    showarray(vals, NUM);                     //打印初始数组内容
    qsort(vals, NUM, sizeof(double), mycomp); //升序排序
    puts("\nSorted list:");
    showarray(vals, NUM); //打印排序后的内容
    return 0;
}

/*初始化数组内容的函数定义*/
void fillarray(double ar[], int n)
{
    int index;

    for (index = 0; index < n; index++)
        ar[index] = (double)rand() / ((double)rand() + 0.1);
}

/*打印数组内容的函数定义*/
void showarray(const double ar[], int n)
{
    int index;

    for (index = 0; index < n; index++)
    {
        printf("%9.4f ", ar[index]);
        if (index % 6 == 5) //每行打印6个值
            putchar('\n');
    }
    if (index % 6 != 0)
        putchar('\n');
}

/*比较两项大小的函数定义*/
int mycomp(const void *p1, const void *p2)
{
    /*使用指向double的指针访问两个参数值*/
    const double *a1 = (const double *)p1;
    const double *a2 = (const double *)p2;

    if (*a1 < *a2) //第1项小于第2项
        return -1;
    else if (*a1 == *a2) //第1项等于第2项
        return 0;
    else //第1项大于第2项
        return 1;
}
