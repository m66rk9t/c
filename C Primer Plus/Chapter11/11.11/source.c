#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define LIM 10
#define SIZE 81
char *myfgets(char *str, int n);
char get_choice(void);
void menu(void);
char get_first(void);
int firstword(const char *str);
void print_1(const char (*strs)[SIZE], int n);
void print_2(const char (*strs)[SIZE], int n);
void print_3(const char (*strs)[SIZE], int n);
void print_4(const char (*strs)[SIZE], int n);
int main(void)
{
    int ct_strs = 0;      /*储存读取的字符串的个数*/
    char strs[LIM][SIZE]; /*声明二维数组，储存字符串*/
    char mychoice;        /*储存用户输入的选择字符*/

    /*读取输入字符串*/
    printf("Please enter %d strings (press Enter to end a string)\n"
    "press Ctrl+Z in a new line to stop inputting:\n",LIM);
    for (int i = 0; i < LIM; i++, ct_strs++)
        if (!myfgets(strs[i], SIZE))
            break;

    /*根据选项处理字符串输出任务*/
    while ((mychoice=get_choice())!='q'&&mychoice!='Q')
    {
        switch (mychoice)
        {
            case 'a':
            case 'A':print_1(strs,ct_strs);break;
            case 'b':
            case 'B':print_2(strs,ct_strs);break;
            case 'c':
            case 'C':print_3(strs,ct_strs);break;
            case 'd':
            case 'D':print_4(strs,ct_strs);break;
        }
    }
    puts("Done!");
    
    return 0;
}
/*读取字符串*/
char *myfgets(char *str, int n)
{
    char *temp;       /*返回值，储存输入首字符地址*/
    *str = getchar(); /*读取输入首字符*/
    /*判断首字符是否是为EOF*/
    if (*str == EOF)
        return NULL;
    /*即使首字符是换行符也储存并结束函数，返回值*/
    else if (*str == '\n')
    {
        *(str++) = '\0';
        return str;
    }
    else
    {
        temp = str++; /*储存首字符地址*/
        /*储存n-1个值*/
        for (int i = 1; i < n - 1; i++)
        {
            *str = getchar();
            /*当遇到换行符时将此位置设置为空字符*/
            if (*str == '\n')
            {
                *str = '\0';
                return temp; /*遇到换行符时停止读取输入*/
            }
            str++; /*指针递增，指向下一个元素*/
        }
        *str = '\0'; /*如果读取输入中没有换行符就将最后一个元素设置为空字符*/
        /*丢弃多余字符*/
        if (*str == '\0')
            while (getchar() != '\n')
                continue;
    }

    return temp;
}
/*提供菜单、处理错误选项、返回选项*/
char get_choice(void)
{
    char choice;          /*储存选项字符并返回*/
    menu();               /*提供菜单*/
    choice = get_first(); /*读取输入中的第一个字符*/
    /*处理错误输入*/
    while ((choice < 'a' || choice > 'd') && (choice < 'A' || choice > 'D') && choice != 'q' && choice != 'Q')
    {
        printf("Error choice, please enter a, A, c, D, q, Q.\n");
        puts("re-enter:");
        choice = get_first();
    }

    return choice; /*返回正确的选项字符*/
}
/*显示菜单*/
void menu(void)
{
    puts("Choose a printing method from the menu below or exit:");
    puts("******************************MENU*******************************");
    puts("a) Prints a list of source strings.");
    puts("b) Print strings in the order in ASCII.");
    puts("c) Print strings in increasing order of length.");
    puts("d) Print according to the length of the first word in the string.");
    puts("q) Quit.");
    puts("*****************************************************************");
    puts("Your choice:");
}
/*读取输入，返回第一个字符*/
char get_first(void)
{
    char first;        /*读取输入中的第一个字符并作为返回值*/
    first = getchar(); /*读取输入中的第一个字符*/

    while (getchar() != '\n') /*丢弃输入中的剩余字符*/
        continue;

    return first; /*返回第一个字符*/
}
/*a) 打印源字符串列表*/
void print_1(const char (*strs)[SIZE], int n)
{
    for (int i = 0; i < n; i++)
        puts(strs[n]);
    putchar('\n');
}
/*b) 以ASCII中的顺序打印字符串，用选择排序法以及strcmp()实现*/
void print_2(const char (*strs)[SIZE], int n)
{
    const char *pstr[n]; /*变长数组、指针数组*/
    const char *temp;    /*临时变量，储存待交换的指针*/

    /*设置指针指向字符串*/
    for (int i = 0; i < n; i++)
        pstr[i] = strs[i];

    /*选择排序法*/
    for (int j = 0; j < n - 1; j++)
        for (int k = j + 1; k < n; k++)
            if (strcmp(pstr[j], pstr[k]) > 0)
            {
                temp = pstr[j];
                pstr[j] = pstr[k];
                pstr[k] = temp;
            }

    /*输出排序后的字符串*/
    for (int i = 0; i < n; i++)
        puts(pstr[i]);
    putchar('\n');
}
/*c) 按长度递增顺序打印字符串，用选择排序法以及strlen()实现*/
void print_3(const char (*strs)[SIZE], int n)
{
    const char *pstr[n]; /*变长数组、指针数组*/
    const char *temp;    /*临时变量，储存待交换的指针*/

    /*设置指针指向字符串*/
    for (int i = 0; i < n; i++)
        pstr[i] = strs[i];

    /*选择排序法*/
    for (int j = 0; j < n - 1; j++)
        for (int k = j + 1; k < n; k++)
            if (strlen(pstr[j]) < strlen(pstr[k]))
            {
                temp = pstr[j];
                pstr[j] = pstr[k];
                pstr[k] = temp;
            }

    /*输出排序后的字符串*/
    for (int i = 0; i < n; i++)
        puts(pstr[i]);
    putchar('\n');
}
/*d) 按字符串中第一个单词的长度以递减顺序打印字符串，用选择排序法实现*/
void print_4(const char (*strs)[SIZE], int n)
{
    const char *pstr[n]; /*变长数组、指针数组*/
    const char *temp;    /*临时变量，储存待交换的指针*/
    int len[n];          /*变长数组，储存每个字符串第一个单词的长度*/

    /*设置指针指向字符串，统计字符串第一个单词的长度*/
    for (int i = 0; i < n; i++)
    {
        pstr[i] = strs[i];
        len[i] = firstword(pstr[i]);
    }

    /*选择排序法*/
    for (int j = 0; j < n - 1; j++)
        for (int k = j + 1; k < n; k++)
            if (len[j] < len[k])
            {
                temp = pstr[j];
                pstr[j] = pstr[k];
                pstr[k] = temp;
            }

    /*输出排序后的字符串*/
    for (int i = 0; i < n; i++)
        puts(pstr[i]);
    putchar('\n');
}
/*计算第一个单词的长度*/
int firstword(const char *str)
{
    const char *temp; /*指向第一个字母字符*/
    int len = 0;      /*第一个单词的长度*/

    /*寻找第一个字母字符*/
    while (isblank(*str))
        str++;

    /*统计第一个单词的字符数*/
    while (isalpha(*str))
    {
        len++;
        str++;
    }

    return len;
}