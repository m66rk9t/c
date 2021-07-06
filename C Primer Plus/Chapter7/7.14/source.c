/*纳税种类与缴纳税费*/
#include<stdio.h>
#include<stdlib.h>
#define SINGLE 17850.0                  //纳税种类“单身”的应征税的收入
#define Head_Household 23900.0          //纳税种类“户主”的应征税的收入
#define Married_Shared 29750.0          //纳税种类“已婚，共有”的应征税的收入
#define Married_Divorced 14875.0        //纳税种类“一环，离异”的应征税的收入
#define BASE1 (SINGLE*0.15)             //“单身”纳税人的基础税费
#define BASE2 (Head_Household*0.15)     //“户主”纳税人的基础税费
#define BASE3 (Married_Shared*0.15)     //“已婚，共有”纳税人的基础税费
#define BASE4 (Married_Divorced*0.15)   //“一环，离异”纳税人的基础税费
void Show_Menu(void);                   //函数原型，显示菜单
void Select_Type(char type);            //函数原型，选择纳税种类
void Taxes(double taxable_income,double base);  //函数原型，计算应缴纳税费
int main(void)
{   
    char react;     //存储选择种类的变量
    Show_Menu();    //函数表达式语句，调用显示菜单函数
    while((react=getchar())!='5')   //循环输入
    {
        Select_Type(react);    //函数表达式语句，调用选择纳税种类函数
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
    printf("Please enter the number corresponding to the option you selected:\n");
    printf("1) Single\t\t\t2) Head of Household\n");
    printf("3) Married,Shared\t\t4) Married,Divorced\n");
    printf("5) quit\n");
    printf("*****************************************************************\n");
}

void Select_Type(char type) //选择纳税种类
{
    switch(type)
    {
        case '1':
            Taxes(SINGLE,BASE1);    //函数表达式语句，调用计算应缴纳税费函数
            break;
        case '2':
            Taxes(Head_Household,BASE2);
            break;
        case '3':
            Taxes(Married_Shared,BASE3);
            break;
        case '4':
            Taxes(Married_Divorced,BASE4);
            break;
        default:
            printf("Please enter the correct selection!\n");
            break;
    }
}

void Taxes(double taxable_income,double base)   //计算应缴纳税费
{
    double income,taxes;
    printf("Please enter your income(>=%.f):\n",taxable_income);
    scanf("%lf",&income);
    taxes=base+(income-taxable_income)*0.28;
    printf("Your taxes:%f\n\n",taxes);
}