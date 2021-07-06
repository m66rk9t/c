#include <ctype.h>
#include <stdio.h>
#include <math.h>
int myatoi(const char *str);
int main()
{
    const char Name[] = "My name is LiYifan.";
    const char ID[] = "3041 is my ID.";
    int name = myatoi(Name);
    int id = myatoi(ID);
    printf("%d\n%d", name, id);
    return 0;
}
/*实现atoi()功能的函数*/
int myatoi(const char *str)
{
    int len = 0;   /*字符串开头数字字符的个数*/
    int toi = 0;   /*储存转换后的数值*/
    int index = 0; /*指数，用于求得转换数值*/
    int value[10];

    if (!isdigit(*str))
        return 0;

    while (isdigit(*str))
        value[len++] = *(str++) - 48;

    for (int i = 0, index = len - 1; i < len; i++, index--)
        toi += value[i] * (int)pow(10, index);

    return toi;
}