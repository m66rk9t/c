/*mems.c -- 使用memcpy()和memmove()*/
#include <stdio.h>
#include <string.h> //提供memcpy()和memmove()原型
#include <stdlib.h>
#define SIZE 10                         //数组长度
void show_array(const int ar[], int n); //打印数组内容的函数原型
//如果编译器不支持C11的_Static_assert，可以注释掉下面这一行
_Static_assert(sizeof(double) == 2 * sizeof(int), "double not twice int size");
int main()
{
    int values[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};//声明并初始化int数组
    int target[SIZE];//声明int数组，储存拷贝内容
    double curious[SIZE / 2] = {2.0, 2.0e5, 2.0e10, 2.0e20, 5.0e30};//声明并初始化double数组

    puts("memcpy() used:");
    puts("values (original data): ");
    show_array(values, SIZE);//打印values数组内容
    memcpy(target, values, SIZE * sizeof(int));//将values数组的内容全部拷贝到target数组
    puts("target (copy of values):");
    show_array(target, SIZE);//打印target数组内容

    puts("\nUsing memmove() with overlapping ranges:");
    memmove(values + 2, values, 5 * sizeof(int));//将索引0-4位置上的5个元素拷贝到索引2-6位置
    puts("values -- elements 0-5 copied to 2-7:");
    show_array(values, SIZE);//打印拷贝后的values数组内容

    puts("\nUsing memcpy() to copy double to int:");
    memcpy(target, curious, (SIZE / 2) * sizeof(double));//将double类型数组的内容拷贝到int类型数组
    puts("target -- 5 doubles into 10 int positions:");
    show_array(target, SIZE / 2);
    show_array(target + 5, SIZE / 2);

    return 0;
}

/*打印数组内容的函数定义*/
void show_array(const int ar[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", ar[i]);
    putchar('\n');
}
