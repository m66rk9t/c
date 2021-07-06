#include<stdio.h>
#define SIZE 50
void getword(char * arr);
int main(void)
{
    char arr[SIZE];
    printf("Please enter a word:\n");
    getword(arr);
    puts(arr);
    return 0;
}
void getword(char * arr)
{
    char temp=getchar();
    /*处理单词前的空白字符*/
    while (temp=='\n'||temp=='\t'||temp==' ')
        temp=getchar();
    /*如果不是空白字符就读取*/
    while (temp!='\n'&&temp!='\t'&&temp!=' ')
    {
        *arr++=temp;
        temp=getchar();
    }
    /*单词后的第一个元素设置为空字符，将其储存为字符串*/
    *arr='\0';
    /*丢弃多余字符*/
    if (temp!='\n')
        while (getchar()!='\n')
            continue;
}