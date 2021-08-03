/* funds4.c -- 使用结构数组的函数 */
#include <stdio.h>
#define FUNDLEN 50
#define N 2

struct funds
{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
}; //结构声明

double sum(const struct funds money[], int n); //第一个参数是指向结构数组首元素的指针

int main(void)
{
    struct funds jones[N] = {
        {"Garlic-Melon Bank",
         4032.27,
         "Lucky's Savings and Loan",
         8543.94},
        {"Honest Jack's Bank",
         3620.88,
         "Party Time Savings",
         3802.91}}; //声明并初始化结构数组

    printf("The Joneses have a total of $%.2f.\n",
           sum(jones, N));

    return 0;
}

double sum(const struct funds money[], int n)
{
    double total;
    int i;

    /*访问结构成员*/
    for (i = 0, total = 0; i < n; i++)
        total += money[i].bankfund + money[i].savefund;

    return (total);
}
