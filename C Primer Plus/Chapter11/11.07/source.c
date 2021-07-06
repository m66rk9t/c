#include <stdio.h>
#define LIM 5
#define TARGSIZE 7
#define SRCSIZE 40
int mystrlen(const char *str);                      /*函数原型*/
char *mystrncpy(char *target, char *source, int n); /*函数原型*/
int main(void)
{
    char target[LIM][TARGSIZE]; /*目标字符串数组*/
    char source[LIM][SRCSIZE] = {
        "abcde", "fghij", "klmno",
        "pqres", "tuvwxyz"}; /*初始化源字符串数组*/
    char *result;            /*储存返回值*/
    /*拷贝字符串并输出*/
    for (int i = 0; i < LIM; i++)
    {
        result = mystrncpy(target[i], source[i], TARGSIZE);
        puts(result);
    }

    return 0;
}
/*计算字符串长度函数定义*/
int mystrlen(const char *str)
{
    int count = 0;
    while (*str++ != '\0')
        count++;
    return count;
}
/*拷贝字符串函数定义*/
char *mystrncpy(char *target, char *source, int n)
{
    char *result = target;
    /*如果源字符串长度小于拷贝个数，设置空字符*/
    if (mystrlen(source) < n)
    {
        while (*source != '\0')
            *(target++) = *(source++);
        *target = '\0';
    }
    /*否则就截断源字符串并将目标数组储存为字符串*/
    else
        for (int i = 0; i < n; i++)
        {
            *(target++) = source[i];
        }
        *target='\0';
    return result;
}