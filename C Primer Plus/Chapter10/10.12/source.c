#include<stdio.h>
#define MONTHS 12   /*明示常量，一年月份数*/
#define YEARS  5    /*明示常量，调查的年数*/
/*函数原型：计算并输出各年总降水量、5年总降水量以及5年平均值*/
void avg_years(const double (*ptr)[MONTHS],int months,int years);
/*函数原型：计算并输出各月5年总降水量的平均值*/
void avg_months(const double (*ptr)[MONTHS],int months,int years);
int main(void)
{
    const double rain[YEARS][MONTHS]=
    {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2},
    };  /*使用初始化列表进行初始化*/

    /*函数调用*/
    avg_years(rain,MONTHS,YEARS);
    avg_months(rain,MONTHS,YEARS);

    return 0;
}
/*函数定义*/
void avg_years(const double (*ptr)[MONTHS],int months,int years)
{
    int month,year;         /*控制变量*/
    double one_year,total;  /*1年的总降水量，总降水量*/

    printf("\nYEAR    RAINFALL (inches)\n");
    for ( year = 0, total=0; year < years; year++)              /*控制年份*/
    {
        for ( month = 0, one_year=0; month < months; month++)   /*控制月份*/
        {
            one_year+=ptr[year][month];                        /*使用指针求一年各月份总降水量*/
        }
        printf("%d          %.1f\n",2010+year,one_year);
        total+=one_year;                                        /*求5年的总降水量*/
    }
    printf("\nTotal precipitation in 5 years is %.1f inches.\n",total);
    printf("The yearly average is %.1f inches.\n",total/years);
}
void avg_months(const double (*ptr)[MONTHS],int months,int years)
{
    int month,year;
    double total;

    printf("\nMONTHLY AVERAGES:\n");
    printf("Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");
    for ( month = 0; month < months; month++)                   /*控制月份*/
    {
        for ( year = 0, total = 0; year < years; year++)        /*控制年份*/
        {
            total+=ptr[year][month];                           /*使用指针求每个月5年的总降水量*/
        }
        printf("%.1f ",total/years);
    }
}