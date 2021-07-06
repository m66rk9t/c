/*for循环打印表格*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int lower,upper;

    printf("Please enter lower and upper integer limits:");
    scanf("%d,%d",&lower,&upper);
    for(;lower<=upper;lower++)
    {
        printf("%2d\t%d\t%d\n",lower,lower*lower,lower*lower*lower);
    }
    printf("Done!\n");

    system("pause");
    return 0;
}