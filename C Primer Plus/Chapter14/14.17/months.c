#include <stdio.h>
#define NUM 12
struct month{
    char name[10]; //月份名全称
    char tre[3];   //月份名缩写
    int days;      //天数
    int num;       //月份号
};//结构声明
const struct month months[NUM] = {
    {"January",   "Jan", 31, 1},
    {"Feburary",  "Feb", 28, 2},
    {"March",     "Mar", 31, 3},
    {"April",     "Apr", 30, 4},
    {"May",       "May", 31, 5},
    {"June",      "Jun", 30, 6},
    {"July",      "Jul", 31, 7},
    {"August",    "Aug", 30, 8},
    {"September", "Sep", 31, 9},
    {"October",   "Oct", 30, 10},
    {"November",  "Nov", 31, 11},
    {"December",  "Dec", 30, 12}
}; //声明并初始化一个结构数组
int days_to_now(int);//函数原型
int main(void)
{
    int input;
    printf("Please enter a month:");
    scanf("%d", &input);
    printf("From %s to %s,", months[0].name, months[input-1].name);
    printf("there are %d days.\n", days_to_now(input));

    return 0;
}

/*返回一年中到该月份为止的天数*/
int days_to_now(int num)
{
    int ret_days = 0;

    for (int i = 0; i < num; i++)
        ret_days += months[i].days;
    
    return ret_days;
}