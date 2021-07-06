/*分别使用转义序列、十进制值、八进制字符常量、十六进制字符常量将回车字符赋给字符常量*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    char ch_es,ch_dec,ch_otcal,ch_hex;
    ch_es='\r';     //转义序列
    ch_dec=13;      //十进制值
    ch_otcal='\015';//八进制字符常量
    ch_hex='\xd';   //十六进制字符常量

    system("pause");
    return 0;
}