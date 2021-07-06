#include <stdio.h>
#define LIM 5
#define SIZE 20
int mystrlen(const char *str);
void subverse(char *str);
int main(void)
{
    char str[LIM][SIZE] = {
        "Actually", "Montion",
        "Iron man", "Town",
        "International"}; /*初始化源字符串*/
    /*输出源字符串*/
    puts("Before subverse:");
    for (int i = 0; i < LIM; i++)
        puts(str[i]);
    /*输出反序字符串*/
    puts("After  subverse:");
    for (int i = 0; i < LIM; i++)
    {
        subverse(str[i]);
        puts(str[i]);
    }
    puts("Done!");
    return 0;
}
/*计算字符串长度*/
int mystrlen(const char *str)
{
    int count = 0;
    while (*str++ != '\0')
        count++;
    return count;
}
/*用反序字符串代替源字符串*/
void subverse(char *str)
{
    char temp; /*临时变量，储存待交换的字符*/
    int len = mystrlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        temp = str[len - i - 1];
        str[len - i - 1] = str[i];
        str[i] = temp;
    }
}