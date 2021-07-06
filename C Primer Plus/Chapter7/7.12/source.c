/*税收与净收入进阶版*/
#include<stdio.h>
#include<stdlib.h>
#define Basic_Wage1 8.75    //第一等级工资
#define Basic_Wage2 9.33    //第二等级工资
#define Basic_Wage3 10.00   //第三等级工资
#define Basic_Wage4 11.20   //第四等级工资
#define BREAK1 300  //第一阶税收标准
#define BREAK2 450  //第二阶税收标准
#define RATE1 0.15  //第一节内税率
#define RATE2 0.2   //第二阶内税率
#define RATE3 0.25  //超第二阶税率
#define BASE1 (BREAK1*RATE1)    //工资300美元的税金
#define BASE2 (BASE1+(BREAK2-BREAK1)*RATE2) //工资450美元的税金
void Show_Menu(void);   //函数原型
void Switch_Wage(char wage);    //函数原型
void Hours_Wage_Taxes_NetIncome(double base);   //函数原型
int main(void)
{
    char react;     //待输入的菜单选项
    Show_Menu();    //函数表达式语句，调用显示菜单函数
    while((react=getchar())!='5')
    {
        Switch_Wage(react);    //函数表达式语句，调用选择工资等级函数
        while (getchar()!='\n')     //丢弃换行符
            continue;
        Show_Menu();    //函数表达式语句，调用显示菜单函数
    }
    printf("Done!\n");

    system("pause");
    return 0;
}

void Show_Menu(void)    //显示菜单
{
    printf("*****************************M*E*N*U*****************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $8.75/hr\t\t\t2) $9.33/hr\n");
    printf("3) $10.00/hr\t\t\t4) $11.20/hr\n");
    printf("5) quit\n");
    printf("*****************************************************************\n");
}

void Switch_Wage(char wage) //选择工资等级
{
    switch(wage)
        {
            case '1':
                Hours_Wage_Taxes_NetIncome(Basic_Wage1);    //计算工资、税金和净收入
                break;
            case '2':
                Hours_Wage_Taxes_NetIncome(Basic_Wage2);
                break;
            case '3':
                Hours_Wage_Taxes_NetIncome(Basic_Wage3);
                break;
            case '4':
                Hours_Wage_Taxes_NetIncome(Basic_Wage4);
                break;
            default:
                printf("Please enter the correct selection!\n");
                break;
        }
}

void Hours_Wage_Taxes_NetIncome(double base)    //计算工资、税金和净收入
{
    double hours,wage,taxes,net_income;
    wage=taxes=net_income=0;
    printf("Please enter the number of hours you work in a week:\n");
    scanf("%lf",&hours);
    if(hours>40)        //判断是否加班
        hours*=1.5;
    wage=hours*base;    //工资
    if(wage<=300)       //第一阶工资税金
        taxes=wage*RATE1;
    else if(wage<=450)  //第二阶工资税金
        taxes=(BASE1+(wage-BREAK1)*RATE2);
    else                //超第二阶工资税金
        taxes=(BASE2+(wage-BREAK2)*RATE3);
    net_income=wage-taxes;  //净收入
    printf("Wage:%f\nTaxes:%f\nNet income:%f\n\n",wage,taxes,net_income);
}