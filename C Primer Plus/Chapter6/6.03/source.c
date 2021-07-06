/*使用fabs()函数比较浮点数*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14159
int main(void)
{
    double input;

    printf("What is the value of PI?\n");
    scanf("%lf",&input);
    while(fabs(input-PI)>0.0001)
    {
        printf("Try again!\n");
        scanf("%lf",&input);
    }
    printf("Close enough!\n");

    system("pause");
    return 0;
}