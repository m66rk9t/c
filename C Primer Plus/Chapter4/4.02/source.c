/*字段宽度，整数类型*/
#include<stdio.h>
#include<stdlib.h>
#define BIRTHDAY 19990928
int main(void)
{
    printf("*%ld*\n",BIRTHDAY);     //默认打印格式
    printf("*%2ld*\n",BIRTHDAY);    //最小字段宽度为2
    printf("*%10ld*\n",BIRTHDAY);   //最小字段宽度为10
    printf("*%-10ld*\n",BIRTHDAY);  //最小字段宽度为10且左对齐打印

    system("pause");
    return 0;
}