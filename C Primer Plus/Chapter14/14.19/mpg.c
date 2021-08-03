#include <stdio.h>
struct gas
{
    float distance;
    float gals;
    float mpg;
};                           //结构声明
struct gas fun1(struct gas); //a.函数原型
float fun2(struct gas);      //b.函数原型

int main(void)
{
    struct gas car; //声明gas类型的结构变量
    printf("Please enter the miles:");
    scanf("%f", &car.distance);
    printf("Please enter the gals:");
    scanf("%f", &car.gals);
    car = fun1(car); //调用a.函数
    //car.mpg = fun2(car);调用b.函数
    printf("Miles per gallon：%f\n", car.mpg);

    return 0;
}
struct gas fun1(struct gas para) //a.函数定义
{
    para.mpg = para.distance / para.gals;
    return para;
}
float fun2(struct gas para) //b.函数定义
{
    return (para.distance / para.gals);
}