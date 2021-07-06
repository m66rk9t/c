#include <stdio.h>
#include <stdlib.h>
int *make_array(int elem, int val);     /*函数原型*/
void show_array(const int ar[], int n); /*函数原型*/
int main(void)
{
    int *pa;
    int size;
    int value;

    printf("Enter the number of elements: ");
    while (scanf("%d", &size) == 1 && size > 0)
    {
        printf("Enter the initialization value: ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if (pa)
        {
            show_array(pa, size);
            free(pa);
        }
        printf("Enter the number of elements (<1 to quit): ");
    }
    printf("Done!\n");

    return 0;
}
int *make_array(int elem, int val)
{
    int *arr;

    /*创建数组*/
    arr = (int *)malloc(elem * sizeof(int));

    /*初始化数组元素*/
    for (int i = 0; i < elem; i++)
        arr[i] = val;

    return arr;
}
void show_array(const int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", ar[i]);
        if ((i + 1) % 8 == 0)
            putchar('\n');
    }
}