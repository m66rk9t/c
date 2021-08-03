#include <stdio.h>
#include <string.h> //提供strcmp()原型
#include <stdbool.h>
#define NUM 12
struct month
{
    char name[10]; //月份名全称
    char tre[3];   //月份名缩写
    int days;      //天数
    int num;       //月份号
};                 //结构声明
const struct month months[NUM] = {
    {"January", "Jan", 31, 1},
    {"Feburary", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 30, 8},
    {"September", "Sep", 31, 9},
    {"October", "Oct", 30, 10},
    {"November", "Nov", 31, 11},
    {"December", "Dec", 30, 12}}; //声明并初始化一个结构数组
int days_to_now(const char *);    //函数原型
char *s_gets(char *st, int n);    //函数原型

int main(void)
{
    char input[10];
    bool is_exist=false;

    printf("Please enter a month (empty line to quit):");
    while (s_gets(input, 10)!=NULL && input[0] != '\0')
    {
        for (int i = 0; i < NUM; i++)
            if (strcmp(months[i].name, input) == 0)
            {
                is_exist = true;
                break;
            }
        
        if (is_exist)
        {
            printf("From %s to %s,", months[0].name, input);
            printf("there are %d days.\n", days_to_now(input));
        }
        else
            printf("Error input.\n");
        is_exist = false;
        printf("Next months:");
    }
    puts("Done!");

    return 0;
}

/*返回一年中到该月份为止的天数*/
int days_to_now(const char *str)
{
    int ret_days = 0;
    int i;
    for (i = 0; strcmp(months[i].name, str) != 0; i++)
        ret_days += months[i].days;
    return (ret_days + months[i].days);
}

/*读取输入字符串的函数定义*/
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // 查找换行符
        if (find)                // 如果地址不是 NULL，
            *find = '\0';        // 在此处放置一个空字符
        else
            while (getchar() != '\n')
                continue; // 处理输入行中剩余的字符
    }
    return ret_val;
}