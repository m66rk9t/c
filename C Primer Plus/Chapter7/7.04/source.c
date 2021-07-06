/*油漆罐问题*/
#include<stdio.h>
#include<stdlib.h>
#define COVERAGE 350    //每罐油漆可粉刷的面积（平方英尺）
int main(void)
{
    int sq_feet;        //需要粉刷的面积
    int cans;           //需要购买的油漆罐数

    printf("Enter number of square feet to be painted:\n");
    while(scanf("%d",&sq_feet)==1)
    {
        cans=sq_feet/COVERAGE;              //计算整罐数
        cans+=(sq_feet%COVERAGE==0)?0:1;    //计算判断是否需要多买一罐
        printf("You need %d %s of paint.\n",cans,(cans==1)?"can":"cans");
        printf("Enter the next number of square feet to be paint(enter 'q' to quit):\n");
    }
    printf("Done!\n");

    system("pause");
    return 0; 
}