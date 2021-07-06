#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define LIM 10
#define SIZE 81
char *myfgets(char *str, int n);
void print_1(const char (*strs)[SIZE], int n);
void print_2(char (*strs)[SIZE], int n);
void print_3(char (*strs)[SIZE], int n);
int main(int args, char *argv[])
{
    char strs[LIM][SIZE]; /*二维数组，储存输入的字符串*/
    int count;            /*读取的字符串的个数*/

    printf("Please enter %d strings "
           "(press Ctrl+Z on a new line to quit):\n",
           SIZE);

    /*读取输入并计算字符串的个数*/
    for (int i = 0; i < SIZE; i++)
    {
        if (myfgets(strs[i], SIZE))
            count++;
        else
            break;
    }

    /*根据命令行参数执行指定的输出任务*/
    if (args < 2 || strcmp(argv[1], "-p") == 0)
        print_1(strs, count);
    else if (strcmp(argv[1], "-u") == 0)
        print_2(strs, count);
    else
        print_3(strs, count);
    puts("Done!");

    return 0;
}
/*实现类似fgets()功能的函数*/
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
/*命令行参数-p或无，按原样打印字符串*/
void print_1(const char (*strs)[SIZE], int n)
{
    for (int i = 0; i < n; i++)
        puts(strs[i]);
}
/*命令行参数-u，把输入全部转换成大写*/
void print_2(char (*strs)[SIZE], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (strs[i][j] == '\0')
                break;
            else/*将小写字母转换成大写*/
                strs[i][j] = toupper(strs[i][j]);
        }
        puts(strs[i]);
    }
}
/*命令行参数-l，把输入全部转换成小写*/
void print_3(char (*strs)[SIZE], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (strs[i][j] == '\0')
                break;
            else/*将大写字母转换成小写*/
                strs[i][j] = tolower(strs[i][j]);
        }
        puts(strs[i]);
    }
}