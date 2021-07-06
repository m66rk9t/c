/*符号常量与格式字符串的神奇组合*/
#include<stdio.h>
#include<stdlib.h>
#define FORMAT "%s! LYFNB!\n"   //符号常量，字符串
int main(void)
{
    printf(FORMAT,FORMAT);

    system("pause");
    return 0;
}