#include <stdio.h>
#define LIM 5
#define SIZE 50
#define TARGCH 's'
void getword(char *arr, int n);            /*读取字符串函数定义*/
int is_within(const char *string, char ch); /*查找字符函数原型*/
int main(void)
{
    int find;
    char words[LIM][SIZE]; /*声明二维数组储存字符串*/
    /*用户输入字符串*/
    printf("Please enter %d words (press Enter to end a word):\n", LIM);
    for (int i = 0; i < LIM; i++)
        getword(words[i], SIZE);
    /*寻找字符在字符串中的位置*/
    printf("Now I will find letter %c in your words.\n", TARGCH);
    for (int i = 0; i < LIM; i++)
    {
        find = is_within(words[i], TARGCH);
        printf("%c in %s: %s\n", TARGCH, words[i], find ? "YES" : "NO");
    }
    puts("Done!");

    return 0;
}
/*读取字符串函数定义*/
void getword(char *arr, int n)
{
    int i = 0;
    char temp = getchar();
    /*处理单词前的空白字符*/
    while (temp == '\n' || temp == '\t' || temp == ' ')
        temp = getchar();
    /*如果不是空白字符就读取*/
    while (i < n && temp != '\n' && temp != '\t' && temp != ' ')
    {
        *arr++ = temp;
        i++;
        temp = getchar();
    }
    /*单词后的第一个元素设置为空字符，将其储存为字符串*/
    *arr = '\0';
    /*丢弃多余字符*/
    if (temp != '\n')
        while (getchar() != '\n')
            continue;
}
/*查好字符函数定义*/
int is_within(const char *string, char ch)
{
    /*假设待查字符不是空字符时*/
    while (*string != '\0')
    {
        /*如果有该字符就返回1*/
        if (*string == ch)
            return 1;
        string++;
    }
    if (ch == '\0') /*如果该字符是末尾空字符就返回1*/
        return 1;
    else /*没有该字符返回0*/
        return 0;
}