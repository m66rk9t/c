/* funds2.c -- 传递指向结构的指针 */
#include <stdio.h>
#define FUNDLEN 50

struct funds
{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
}; //结构声明

double sum(const struct funds *); /*参数是指向结构的指针*/

int main(void)
{
    struct funds stan = {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Savings and Loan",
        8543.94}; //声明并初始化funds类型的结构变量

    printf("Stan has a total of $%.2f.\n", sum(&stan));//将指向结构的指针作为参数传递

    return 0;
}

double sum(const struct funds *money)
{
    return (money->bankfund + money->savefund);
}
