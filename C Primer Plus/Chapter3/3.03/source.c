/*读取一个浮点数，打印为一般计数法、指数计数法、p计数法*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    float x;
    printf("Please enter a floating-point number\n");
    scanf("%f",&x);
    printf("fixed-point nation:%f\n",x);    //一般计数法
    printf("exponential nation:%e\n",x);    //指数计数法
    printf("p nation:%a\n",x);              //p计数法

    system("pause");
    return 0;
}