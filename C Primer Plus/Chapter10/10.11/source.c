#include<stdio.h>
void doubled(int (*arr)[5],int rows);/*将源数组元素值翻倍的函数原型*/
void show_arr(int (*arr)[5],int rows);/*显示数组内容的函数原型*/
int main(void)
{
    int arr[3][5]={
        {1,3,4,6,7},
        {9,2,5,8,10},
        {7,5,3,1,9}
    };/*声明并初始化二维数组*/

    /*函数调用*/
    printf("Original:\n");
    show_arr(arr,3);
    doubled(arr,5);
    printf("Doubled:\n");
    show_arr(arr,3);

    return 0;
}
/*函数定义*/
void doubled(int (*arr)[5],int rows)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < 5; j++)
            arr[i][j]*=2;
}
void show_arr(int (*arr)[5],int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 5; j++)
            printf("%4d ",arr[i][j]);
        printf("\n");
    }
}