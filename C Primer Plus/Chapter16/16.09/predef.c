/*predef.c -- 使用预定义宏和预定义标识符*/
#include <stdio.h>
void why_me();

int main()
{
    /*使用预定义宏*/
    printf("The file is %s.\n", __FILE__);
    printf("The date is %s.\n", __DATE__);
    printf("The time is %s.\n", __TIME__);
    printf("The version is %ld.\n", __STDC_VERSION__);
    printf("This is line %d.\n", __LINE__);
    /*使用预定义标识符*/
    printf("This function is %s\n", __func__);
    why_me();

    return 0;
}

void why_me()
{
    printf("This function is %s\n", __func__); //使用预定义标识符
    printf("This is line %d.\n", __LINE__);    //使用预定义宏
}
