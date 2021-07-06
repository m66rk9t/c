/*使用for循环打印序数对应的立方值*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int x;
    const int i;
    long result=1;

    printf("Please enter an integer number as the Timer:");
    scanf("%d",&i);
    printf("value of x  cubic of x\n");
    for(x=1;x<=i;x++)
    {
        result=x*x*x;
        printf("%-d\t\t%6d\n",x,result);
    }
    printf("Done!\n");

    system("pause");
    return 0;
}