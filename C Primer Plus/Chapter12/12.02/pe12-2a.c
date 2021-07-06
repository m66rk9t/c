#include <stdio.h>
/*静态内部链接，定义式声明*/
static int input_mode;
static double distance;
static double fuel;

/*设置输入模式*/
void set_mode(int mode)
{
    static int status;
    if (mode > 1)
    {
        printf("Invalid mode specified. Mode %d(%s) used.\n",
               status, status ? "US" : "metric");
        input_mode = status;
    }
    else
    {
        input_mode = mode;
        status = mode;
    }
}

/*根据用户输入的模式提示用户输入相应数据并储存*/
void get_info(void)
{
    if (input_mode == 0)
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", &fuel);
    }
    else
    {
        printf("Enter distance traveled in miles: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", &fuel);
    }
}

/*根据设置的模式计算并显示油耗*/
void show_info(void)
{
    if (input_mode == 0)
        printf("Fule consumption is %.2f liters per 100 km.\n",
               fuel / (distance / 100));
    else
        printf("Fule consumption is %.1f miles per gallons.\n",
               distance / fuel);
}