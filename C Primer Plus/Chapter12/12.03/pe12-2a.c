#include <stdio.h>
static void show_info(int mode, double distance, double fuel); /*函数原型*/

/*根据用户输入的模式提示用户输入相应数据并调用计算油耗函数*/
void get_show(int mode)
{
    double distance, fuel;
    if (mode == 0)
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", &fuel);
        show_info(mode, distance, fuel);
    }
    else
    {
        printf("Enter distance traveled in miles: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", &fuel);
        show_info(mode, distance, fuel);
    }
}

/*本文件私有，根据设置的模式计算并显示油耗*/
static void show_info(int mode, double distance, double fuel)
{
    if (mode == 0)
        printf("Fule consumption is %.2f liters per 100 km.\n",
               fuel / (distance / 100));
    else
        printf("Fule consumption is %.1f miles per gallons.\n",
               distance / fuel);
}