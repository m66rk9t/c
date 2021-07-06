/*打印字符串格式*/
#include<stdio.h>
#include<stdlib.h>
#define STR "UnicornBettle LYF" //符号常量，字符串
int main(void)
{
    printf("[%2s]\n",STR);
    printf("[%24s]\n",STR);
    printf("[%24.7s]\n",STR);
    printf("[%-24.7s]\n",STR);

    system("pause");
    return 0;
}