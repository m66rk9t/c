/*使用while循环打印A~G*/
#include<stdio.h>
#include<stdlib.h>
#define ASCII_G 71  //符号常量
int main(void)
{
    int i=64;   //'@'的ASCII码值是64

    while(i++ < ASCII_G)    //迭代语句
    {
        printf("%c ",i);
    }   //复合语句（代码块）
    printf("\n");

    system("pause");
    return 0;
}