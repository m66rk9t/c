#include <stdio.h>
#include <stdlib.h>                        //提供malloc()以及free()原型
#include <stdarg.h>                        //提供va_list定义以及va_start()、va_arg()、va_end()宏
void show_array(const double ar[], int n); //打印数组内容的函数原型
double *new_d_array(int n, ...);           //使用可变数量参数初始化数组的函数原型

int main()
{
    double *p1; //指向第一个数组
    double *p2; //指向第二个数组

    /*使用可变数量参数初始化两个数组*/
    p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
    /*打印两个数组的内容*/
    show_array(p1, 5);
    show_array(p2, 4);
    /*释放两个数组的内存*/
    free(p1);
    free(p2);

    return 0;
}

/*使用可变数量参数初始化数组的函数定义*/
double *new_d_array(int n, ...)
{
    double *arr;
    va_list vl;

    arr = (double *)malloc(n * sizeof(double)); //为数组分配内存
    va_start(vl, n);                  //初始化参数列表

    for (int i = 0; i < n; i++)
        arr[i] = va_arg(vl, double);
    va_end(vl); //释放储存参数的内存

    return arr;
}

/*打印数组内容的函数定义*/
void show_array(const double ar[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%g ", ar[i]);
    putchar('\n');
}
