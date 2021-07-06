#include <stdio.h>
#define LIM 5
#define SIZE 50
#define TARGCH 's'
void getword(char *arr, int n);              /*读取字符串函数定义*/
char *findchar(const char *string, char ch); /*查找字符函数原型*/
int main(void)
{
    char *find;            /*储存字符首次出现的位置*/
    char words[LIM][SIZE]; /*声明二维数组储存字符串*/
    /*用户输入字符串*/
    printf("Please enter %d words (press Enter to end a word):\n", LIM);
    for (int i = 0; i < LIM; i++)
        getword(words[i], SIZE);
    /*寻找字符在字符串中的位置*/
    printf("Now I will find letter %c in your words.\n", TARGCH);
    for (int i = 0; i < LIM; i++)
    {
        find = findchar(words[i], TARGCH);
        if (find)
            printf("%c in \"%s\":%p\n", TARGCH, words[i], find);
        else
            printf("%c in \"%s\":Not foundd!\n", TARGCH, words[i], find);
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
/*查找指定字符*/
char *findchar(const char *string, char ch)
{
    const char *find; /*储存字符首次出现的位置*/
    /*假设待查字符不是空字符时*/
    while (*string != '\0')
    {
        if (*string == ch)
        {
            /*返回指向首次出现的位置的指针*/
            /*通过强制类型转换取消const*/
            return (char *)string;
        }
        string++;
    }
    if (ch == '\0') /*如果是空字符，就返回指向空字符首次出现的位置的指针*/
        return (char *)string;
    else /*既不是空字符也没找到首次出现的位置就返回空指针*/
        return NULL;
}