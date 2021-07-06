#include <stdio.h>
#include <stdlib.h>   /*提供rand()原型*/
#define SIZE 100      /*明示常量*/
static int arr[SIZE]; /*静态内部链接数组*/
void desc(int *ptr);  /*函数原型*/
int main(void)
{
    /*生成随机数并填充数组*/
    for (int i = 0; i < SIZE; i++)
        arr[i] = (rand() % 10) + 1;

    /*调用排序函数*/
    desc(arr);

    /*输出排序结果*/
    for (int i = 0, j = 1; i < SIZE; i++, j++)
    {
        printf("%2d ", arr[i]);
        if (j % 10 == 0)
            putchar('\n');
    }

    return 0;
}

/*选择排序法降序排列数组元素*/
void desc(int *ptr)
{
    int temp;
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (ptr[i] < ptr[j])
            {
                temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
}