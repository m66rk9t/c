/*usehotel.c--计算房间费用程序*/
#include <stdio.h>
#include "hotel.h" //使用“hotle.h”头文件
int main(void)
{
    int nights, code;
    double hotle_rate;

    while ((code = showmenu()) != QUIT)
    {
        switch (code)
        {
        case 1:
            hotle_rate = HOTLE1;
            break;
        case 2:
            hotle_rate = HOTLE2;
            break;
        case 3:
            hotle_rate = HOTLE3;
            break;
        case 4:
            hotle_rate = HOTLE4;
            break;
        default:
            hotle_rate = 0.0;
            printf("oops!\n");
            break;
        }
        nights = getnights();
        showprice(hotle_rate, nights);
    }

    printf("Thank you and goodbye!\n");

    return 0;
}