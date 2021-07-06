/*使用for循环设计一个计算整数的整数次幂的函数*/
#include<stdio.h>
#include<stdlib.h>
double Power(double para_base,int para_index);  //函数原型
int main(void)
{
    double base,result;
    result=00;
    int index;

    printf("Please enter an number as base:");
    scanf("%lf",&base);
    printf("Now enter an number as index:");
    scanf("%d",&index);
    result=Power(base,index);
    printf("Done! The result is %f.\n",result);

    system("pause");
    return 0;

}

double Power(double para_base,int para_index)
{
    double power=1.0;
    int i=1;
    for(;i<=para_index;i++)
    {
        power *= para_base;
    }

    return power;
}