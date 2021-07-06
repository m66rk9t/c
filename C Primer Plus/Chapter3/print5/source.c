/*打印浮点型值*/
#define __USE_MINGW_ANSI_STDIO 1    //启用MinGW标准输入输出函数
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    float fl = 32000.0F; //单精度浮点型，一般计数法
    double db = 2.14E9;     //双精度浮点型，指数计数法
    long double ldb = 5.32e-5L; //长双精度浮点型，指数计数法

    //打印
    printf("%f can be written %e\n",fl,fl);
    printf("%f can be written %e\n",db,db);
    printf("%Lf can be written %Le\n",ldb,ldb);

    system("pause");
    return 0;
}