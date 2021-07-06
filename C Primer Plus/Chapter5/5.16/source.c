/*自定义函数——求double类型数据的平方值*/
#include<stdio.h>
#include<stdlib.h>
double D_Square(double para);   //函数原型
int main(void)
{
    double input,result;

    printf("Please enter a floating-point number:\n");
    scanf("%lf",&input);
    result=D_Square(input);
    printf("The square of %f is %f.\n",input,result);

    system("pause");
    return 0;
}

double D_Square(double para)
{
    return para*para;
}