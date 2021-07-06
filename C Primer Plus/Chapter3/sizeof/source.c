/*使用sizeof运算符打印数据类型的大小*/
#define __USE_MINGW_ANSI_STDIO 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 
int main(void)
{
    /*C99为数据类型大小提供%zd转换说明*/
    printf("Type int has a size of %zd bytes.\n",sizeof(int));
    printf("Type short has a size of %zd bytes.\n",sizeof(short));
    printf("Type long has a size of %zd bytes.\n",sizeof(long));
    printf("Type long long has a size of %zd bytes.\n",sizeof(long long));
    printf("Type char has a size of %zd bytes.\n",sizeof(char));
    printf("Type _Bool has a size of %zd bytes.\n",sizeof(_Bool));
    printf("Type float has a size of %zd bytes.\n",sizeof(float));
    printf("Type double has a size of %zd bytes.\n",sizeof(double));
    printf("Type long double has a size of %zd bytes.\n",sizeof(long double));

    system("pause");
    return 0;
}