#include <stdio.h>
#include <stdlib.h>/*提供函数原型*/
#include <string.h>
double mypow(double base, int index);
int main(int argc, char *argv[])
{
    double base = atof(argv[1]);        /*将第一个参数转换为double值，作为底数*/
    int index = atoi(argv[2]);          /*将第二个参数转换为int值，作为指数*/
    double result = mypow(base, index); /*调用递归函数求幂*/
    printf("%f\n", result);
    return 0;
}
/*递归：求幂*/
double mypow(double base, int index)
{
    double result;
    if (index == 0)
        return 1;
    else if (index == 1)
        return base;
    else
        result = base * (mypow(base, index - 1));
    return result;
}