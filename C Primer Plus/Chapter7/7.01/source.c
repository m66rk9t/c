/*计算电费*/
#include<stdio.h>
#include<stdlib.h>
#define BREAK1 360.0    //第一阶最大用电量
#define BREAK2 468.0    //第二阶最大用电量
#define BREAK3 720.0    //第三阶最大用电量
#define RATE1 0.13230   //第一阶电费（<=360）
#define RATE2 0.15040   //第二阶电费（[361,468]]）
#define RATE3 0.30025   //第三阶电费（[469,720]）
#define RATE4 0.34025   //超过第三阶电量电费（>=721）
/*使用360kWh的电费*/
#define BASE1 (BREAK1*RATE1)
/*使用468kWH的电费*/
#define BASE2 (BASE1+RATE2*(BREAK2-BREAK1))
/*使用720kWH的电费*/
#define BASE3 (BASE2+RATE3*(BREAK3-BREAK2))
int main(void)
{
    double kWh;     //用电量（kWH）
    double bill;    //电费

    printf("Electricity bill list(kWh)：\n");
    printf("First 360kWh:      $0.13230/kWh\n");
    printf("Renew 108kWh:      $0.15040/kWh\n");
    printf("Renew 252kWh:      $0.30025/kWh\n");
    printf("Exceed 720kWh:     $0.34025/kWh\n");

    printf("\nPlease enter the kWh used:\n");
    scanf("%lf",&kWh);
    if(kWh<=BREAK1) //用电量在第一阶内
    {
        bill=kWh*RATE1;
    }
    else if(kWh<=BREAK2)    //用电量在第二阶内
    {
        bill=(BASE1+RATE2*(kWh-BREAK1));
    }
    else if(kWh<=BREAK3)    //用电量在第三阶内
    {
        bill=(BASE2+RATE3*(kWh-BREAK2));
    }
    else    //用电量超过720kWh
    {
        bill=(BASE3+RATE4*(kWh-BREAK3));
    }
    printf("The charge for %.2fkWh is $%.2f.\n",kWh,bill);

    system("pause");
    return 0;
}