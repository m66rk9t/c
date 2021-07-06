/*以十进制、八进制、十六进制格式打印十进制数100*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int x=100;

    //无前缀打印
    printf("dec= %d, octal= %o,  hex= %x\n",x,x,x);

    //显示前缀打印
    printf("dec= %d, octal= %#o, hex= %#x\n",x,x,x);

    system("pause");
    return 0;
}