/*对整数使用精度和0标记*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    printf("*%5d*\n",7);    //使用字段宽度，用空格填充宽度
    printf("*%5.2d*\n",7);  //使用精度，生成足够的前导0满足精度要求
    printf("*%05d*\n",7);   //使用0标记生成足够的前导0代替空格填充字段宽度
    printf("*%05.3d*\n",7); //忽略0标记，生成足够的前导0满足精度要求
    printf("*%-05d*\n",7);  //忽略0标记，左对齐打印格式并用空格填充宽度

    system("pause");
    return 0;
}