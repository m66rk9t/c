/*购物结算程序*/
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#define ARTICHOKE 2.05      //洋蓟售价（每磅）
#define BEET 1.15           //甜菜售价（每磅）
#define CARROT 1.09         //胡萝卜售价（每磅）
#define DISCOUNT 0.95       //折扣
#define BREAK1 5            //计费标准1
#define BREAK2 20           //计费标准2
#define Freight_Packing1 6.5    //计费标准1下的运费、包装费
#define Freight_Packing2 14     //计费标准2下的运费、包装费
#define RENEWAL_COST 0.5    //续重费用
void Show_Menu(void);       //函数原型，显示商品菜单
/*函数原型，计算未打折的订单费用*/
double OrderFee(double weight_artichoke, double weight_beet,double weight_carrot);
double Freight_Packaging_Fees(double order_weight);    //函数原型，计算运费和包装费
double Total_Cost(double total_order_cost, double freight_packing);  //函数原型，计算费用总额
/*显示订单及费用总额*/
void Show_Order(bool discount,double weight_artichoke,double weight_beet,double weight_carrot,double order_weight,double order_fee,double after_discount,double freight_packing,double total_cost);
int main(void)
{
    char react;             //待输入的菜单选项
    double input,weight_artichoke,weight_beet,weight_carrot,order_weight,order_fee,after_discount,freight_packing,total_cost;
    weight_artichoke=weight_beet=weight_carrot=order_weight=0.0;
    bool discount=false;    //判断是否打折

    Show_Menu();            //函数表达式语句，调用显示商品菜单函数
    while((react=getchar())!='q')
    {
        switch(react)       //选择购买的商品并输入购买的磅数
        {
            case 'a':
            case 'A':
                printf("Please enter the pound of the artichoke you want to buy:\n");
                scanf("%lf",&input);
                weight_artichoke+=input;
                order_weight+=input;
                break;
            case 'b':
            case 'B':
                printf("Please enter the pound of beets you want to buy:\n");
                scanf("%lf",&input);
                weight_beet+=input;
                order_weight+=input;
                break;
            case 'c':
            case 'C':
                printf("Please enter the pounds of carrots you want to buy:\n");
                scanf("%lf",&input);
                weight_carrot+=input;
                order_weight+=input;
                break;
            default:
                printf("Please enter the correct option!\n");
                break;
        }
        printf("Please enter another product option(enter 'q' to quit):\n");
        while (getchar()!='\n')     //丢弃无效字符和换行符
            continue;
    }
    if(weight_artichoke!=0||weight_beet!=0||weight_carrot!=0)
    order_fee=OrderFee(weight_artichoke,weight_beet,weight_carrot); //求订单费用，未打折
    if(order_fee>=100)  //判断是否符合打折条件
    {
        after_discount=order_fee*DISCOUNT;  //折后费用
        discount=true;                      //标记变量，该订单可打折
    }
    else
        after_discount=order_fee;           //标记变量，该订单不可打折
    freight_packing=Freight_Packaging_Fees(order_weight);   //求运费和包装费
    total_cost=Total_Cost(after_discount,freight_packing);  //求费用总额，应付款
    /*显示订单*/
    Show_Order(discount,weight_artichoke,weight_beet,weight_carrot,order_weight,order_fee,after_discount,freight_packing,total_cost);

    printf("Done!\n");

    system("pause");
    return 0;

}

void Show_Menu(void)        //显示商品菜单
{
    printf("*******************************M*E*N*U*******************************\n");
    printf("Please enter the option corresponding to the product you want to buy:\n");
    printf("a) Artichoke\t\tb) Beet\t\tc) Carrot\tq) Quit\n");
    printf("*********************************************************************\n");
}

/*计算订单总费用，未打折前*/
double OrderFee(double weight_artichoke, double weight_beet,double weight_carrot)
{
    return weight_artichoke*ARTICHOKE+weight_beet*BEET+weight_carrot*CARROT;
}

/*计算运费*/
double Freight_Packaging_Fees(double order_weight)
{
    double fee;
    if(order_weight<=BREAK1)        //计费标准1
    {
        fee=Freight_Packing1;
    }
    else if(order_weight<=BREAK2)   //计费标准2
    {
        fee=Freight_Packing2;
    }
    else    //超过计费标准，续重求费用
    {
        fee=Freight_Packing2+(order_weight-BREAK2)*RENEWAL_COST;
    }
    
    return fee;
}

/*计算费用总额*/
double Total_Cost(double total_order_cost, double freight_packing)
{
    return total_order_cost+freight_packing;    //订单总费用（可能是折后价）+运费和包装费
}

/*显示订单及费用总额*/
void Show_Order(bool discount,double weight_artichoke,double weight_beet,double weight_carrot,double order_weight,double order_fee,double after_discount,double freight_packing,double total_cost)
{
    printf("******************************O*R*D*E*R******************************\n");
    printf("Artichoke:%f\tBeet:%f\tCarrot:%f\t\n\n",weight_artichoke,weight_beet,weight_carrot);
    printf("The cost of the meat you ordered:%f\n",weight_artichoke*ARTICHOKE);
    printf("The total weight of the goods you purchased: %f pounds\n",order_weight);
    printf("The cost of the vegetables you ordered:%f\n",weight_beet*BEET+weight_carrot*CARROT);
    printf("The total cost of your order:%f\n",order_fee);
    if(discount)
    {
        printf("You have a coupon to use.Total order cost after discount:%f\n",after_discount);
    }
    else
    {
        printf("Sorry,you cannot use coupons.\n");
    }
    printf("Freight and packaging fees:%f\n",freight_packing);
    printf("                                             To be paid:%13f\n",total_cost);
    printf("*********************************************************************\n");
}