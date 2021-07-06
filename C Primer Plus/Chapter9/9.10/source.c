/*递归：斐波那契数列*/
#include<stdio.h>
#include<stdlib.h>
void Fibonacci(int item);   /*函数原型*/
int main(void)
{
    int item;   /*存储待输入的项数*/
    printf("Please enter the number of items(press Ctrl+Z to end):\n");
    while (scanf("%d",&item)!=-1)
    {   printf("Result:\n");
        Fibonacci(item);
        printf("\nPlease enter the number of items(press Ctrl+Z to end):\n");
    }
    printf("Done!\n");

    system("pause");
    return 0;
}

void Fibonacci(int item)
{
    int n1=1,n2=1,next;
    for (int i = 1; i <= item; i++)
    {
        if (i==1||i==2)
        {
            next=1;
        }
        else
        {
            next=n1+n2;
            n1=n2;
            n2=next;
        }
        printf("%d ",next);
    }
}