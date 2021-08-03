/* funds1.c -- 把结构成员作为参数传递 */
#include <stdio.h>
#define FUNDLEN 50
struct funds
{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
}; //结构声明

double sum(double, double);

int main(void)
{
    struct funds stan = {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Savings and Loan",
        8543.94}; //声明并初始化一个结构变量

    printf("Stan has a total of $%.2f.\n",
           sum(stan.bankfund, stan.savefund)); //把结构成员作参数传递
    return 0;
}

double sum(double x, double y)
{
    return (x + y);
}
