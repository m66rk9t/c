/*printf()函数返回值*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int result;
    result=printf("UnicornBettle LYF!\n");  //计算打印的字符数量，包括空格以及换行符'\n'
    printf("The printf() function printde %d characters.\n",result);

    system("pause");
    return 0;
}