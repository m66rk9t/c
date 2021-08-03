/* funds3.c -- 传递一个结构 */
#include <stdio.h>
#define FUNDLEN 50

struct funds
{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
}; //结构声明

double sum(struct funds moolah); /*参数是一个结构*/

int main(void)
{
    struct funds stan = {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Savings and Loan",
        8543.94}; //声明并初始化结构变量

    printf("Stan has a total of $%.2f.\n", sum(stan)); //将结构作为参数传递

    return 0;
}

double sum(struct funds moolah)
{
    return (moolah.bankfund + moolah.savefund);
}
