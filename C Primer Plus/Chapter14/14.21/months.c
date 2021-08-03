#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 12
struct month{
    char name[10]; //月份名全称
    char tre[4];   //月份名缩写
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
void makemonth(void);
void eatline(void);
char *s_gets(char *st, int n);

int main(void)
{

    int yy,mm,dd,choice;
    char * monthname;
    int counts = 0;//统计天数

    /*输入日*/
    printf("Please enter the day:");
    scanf("%d", &dd);
    eatline();

    /*输入月份*/
    printf("Please enter the month (1-month number 2-month name 3-month name(abb)):");
    scanf("%d", &choice);
    eatline();
    while (choice!=1&&choice!=2&&choice!=3)
    {
        printf("Please enter 1, 2 or 3:");
        scanf("%d", &choice);
        eatline();
    }
    switch (choice)
    {
        case 1:printf("Enter the integer month number:");
                scanf("%d", &mm);eatline();break;
        case 2:printf("Enter the month name:");
                monthname = malloc(10);s_gets(monthname, 10);break;
        case 3:printf("Enter the abbreviation of the month name:");
                monthname = malloc(4);s_gets(monthname, 4);break;
    }

    /*输入年份*/
    printf("Please enter the year:");
    scanf("%d", &yy);

    if (choice == 1)
    {
        for (int i = 0; i < NUM; i++)
        {
            if (mm == months[i].num)
                break;
            counts += months[i].days;
        }
        counts += dd;
    }
    else if (choice == 2)
    {
        for (int i = 0; i < NUM; i++)
        {
            if (strcmp(monthname, months[i].name) == 0)
                break;
            counts += months[i].days;
        }
        counts += dd;
    }
    else
    {
        for (int i = 0; i < NUM; i++)
        {
            if (strcmp(monthname, months[i].tre) == 0)
                break;
            counts += months[i].days;
        }
        counts += dd;
    }
    
    printf("From %d.1.1 to now, there are %d days.\n", yy, counts);

    return 0;
}

void eatline(void)
{
    while (getchar()!='\n')
        continue;    
}

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