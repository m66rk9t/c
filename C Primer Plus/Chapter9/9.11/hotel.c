/*hotel.c--酒店管理函数*/
#include <stdio.h>
#include "hotel.h" //使用“hotle.h”头文件
int showmenu(void) //显示选择列表
{
    int code, status; //分别存储选项以及输入状态
    printf("\n%s%s\n", STARS, STARS);
    printf("Enter the number of the diserd hotle:\n");
    printf("1) Fairfield Arms       2) Hotle Olympic\n");
    printf("3) Chertowth Plaza      4) The Stocken\n");
    printf("5) quit\n");
    printf("%s%s\n", STARS, STARS);
    while ((status = scanf("%d", &code)) != 1 || (code < 1 || code > 5))
    {
        if (status != 1)
        {
            scanf("%*s");
        }
        printf("Enter an integer from 1 to 5, please.\n");
    }

    return code;
}

int getnights(void) //返回预定天数
{
    int nights; //存储预定天数

    printf("How many nights are needed?\n");
    while (scanf("%d", &nights) != 1)
    {
        scanf("%*s");
        printf("Please enter an integer.\n");
    }

    return nights;
}

void showprice(double rate, int nights) //根据费率、入住天数计算费用
{
    int n;
    double total = 0.0;
    double factor = 1.0;

    for (n = 1; n <= nights; n++, factor *= DISCOUNT)
    {
        total += rate * factor;
    }

    printf("The total cost will be $%0.2f\n", total);
}