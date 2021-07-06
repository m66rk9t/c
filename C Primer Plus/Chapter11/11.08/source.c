#include<stdio.h>
#define LIM 5
#define SIZE 20
#define TAR "tion"
int mystrlen(const char *str);
char *string_in(const char *str, const char *tar);
int main(void)
{
    char str[LIM][SIZE]={
        "Actually","Montion",
        "Iron man","Town",
        "International"
    };
    char *result;
    for (int i = 0; i < LIM; i++)
    {
        result=string_in(str[i],TAR);
        printf("%s in %13s: %s\n",TAR,str[i],result?"FOUND":"NOT FOUND");
    }
    puts("Done!");

    return 0;
}
/*计算字符串长度*/
int mystrlen(const char *str)
{
    int count=0;
    while (*str++!='\0')
        count++;
    return count;
}
/*判断目标字符串是否包含指定的字符串*/
char *string_in(const char *str, const char *tar)
{
    char * include=NULL;/*返回值，储存首字符第一次出现的位置*/
    int str_len=mystrlen(str);/*计算目标字符串的长度*/
    int tar_len=mystrlen(tar);/*计算指定字符串的长度*/
    
    for (int i = 0; i < str_len; i++)/*外循环*/
    {
        if (str[i]==*tar)/*如果某个字符与指定首字符相同就进入内循环*/
        {
            for (int j = 1; j < tar_len; j++)/*内循环*/
            {
                if(str[i+j]==tar[j])
                    include=(char *)tar;
                else/*一旦有一个字符不同就结束内循环*/
                    break;
            }
        }
    }
    return include;
}