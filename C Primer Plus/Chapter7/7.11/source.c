/*税收与净收入*/
#include<stdio.h>
#include<stdlib.h>
#define BREAK1 300  //第一阶税收标准
#define BREAK2 450  //第二阶税收标准
#define RATE1 0.15  //第一节内税率
#define RATE2 0.2   //第二阶内税率
#define RATE3 0.25  //超第二阶税率
#define BASE 10.00  //基本工资10.00美元/小时
#define BASE1 (BREAK1*RATE1)    //工资300美元的税金
#define BASE2 (BASE1+(BREAK2-BREAK1)*RATE2) //工资450美元的税金
int main(void)
{
    double hours,wage,taxes,net_income;
    wage=taxes=net_income=0;
    printf("Please enter the number of hours you work in a week:\n");
    scanf("%lf",&hours);
    if(hours>40)    //判断是否加班
        hours*=1.5;
    wage=hours*BASE;    //工资
    if(wage<=300)       //第一阶工资税金
        taxes=wage*RATE1;
    else if(wage<=450)  //第二阶工资税金
        taxes=(BASE1+(wage-BREAK1)*RATE2);
    else                //超第二阶工资税金
        taxes=(BASE2+(wage-BREAK2)*RATE3);
    net_income=wage-taxes;  //净收入
    printf("Wage:%f\nTaxes:%f\nNet income:%f\n",wage,taxes,net_income);

    system("pause");
    return 0;
}