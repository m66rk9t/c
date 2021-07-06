/*for循环设置数组元素的值*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 8
int main(void)
{
    int outer,inner,array[SIZE];

    for(outer=0;outer<SIZE;outer++)
    {
        array[outer]=2;
        for(inner=0;inner<outer;inner++)
        {
            array[outer]*=2;
        }
    }

    outer=0;
    do
    {
        printf("%d\n",array[outer++]);
    }while(outer<SIZE);

    system("pause");
    return 0;
    
}