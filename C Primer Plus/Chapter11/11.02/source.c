#include<stdio.h>
#include<ctype.h>
#define SIZE 5
int getnchr(char * arr, int n);
int main(void)
{
    char arr[SIZE];
    printf("Please enter %d characters (include blank characters),\n"
            ,SIZE-1);
    int input=getnchr(arr,SIZE-1);
    puts("Your characters are:");
    for (int i=0;i<input;i++)
        putchar(arr[i]);
    putchar('\n');
    return 0;
}
int getnchr(char * arr, int n)
{
    int input=0;/*储存读取的字符*/
    for (int i = 0; i < n-1; i++)
    {
        arr[i]=getchar();/*从输入中读取字符*/
        if(arr[i]!='\n'&&arr[i]!='\t'&&arr[i]!=' ')
            input++;/*如果没读到空白字符，读取计数加一*/
        else
            break;/*读取到空白字符则退出循环，停止读取*/
    }
    /*丢弃多余字符*/
    while (getchar()!='\n')
        continue;
    
    return input;
}