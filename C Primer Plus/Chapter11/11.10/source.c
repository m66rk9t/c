#include <stdio.h>
#define SIZE 81
int mystrlen(const char *str);
char *findchar(const char *string, char ch);
void delspace(char *str);
char * myfgets(char *str, int n);
int main(void)
{
    char str[SIZE];
    puts("Please enter a string (press Enter in a new line to quit):");
    while (myfgets(str,SIZE)!=NULL&&str[0]!='\0')
    {
        delspace(str);
        puts("Now enter another string:");
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
/*删除字符串中的空格*/
void delspace(char *str)
{
    char *have;       /*临时变量，指向首个空格*/
    char *previous;   /*指向首个空格*/
    char *next;       /*指向*previous后的第一个字符*/
    char *last;       /*替换最后一个空格时previsou应指向的位置*/
    int len_str;      /*字符串长度*/
    int ct_space = 0; /*空格个数*/

    have = findchar(str, ' ');
    if (have)
    {
        /*计算字符串长度*/
        len_str = mystrlen(str);

        /*统计空格的个数*/
        for (int i = 0; i < len_str; i++)
            if (str[i] == ' ')
                ct_space++;

        /*设置previous以及next*/
        previous = have;
        next = previous + 1;

        /*设置last*/
        last = str + (len_str - ct_space - 1);

        /*删除空格*/
        while (previous <= last)
        {
            while (*next == ' ')
                next++;
            *previous = *next;
            *next = ' ';
            previous++;
            next++;
        }

        /*将空格替换成空字符*/
        while (*previous != '\0')
            *previous++ = '\0';

        /*输出替换后的结果*/
        puts("After remove the space:");
        puts(str);
    }
    else
        printf("There are no space in \"%s\".\n", str);
}
/*实现类似fgets()功能的函数*/
char * myfgets(char *str, int n)
{
    char * temp;/*返回值，储存输入首字符地址*/
    *str=getchar();/*读取输入首字符*/
    /*判断首字符是否是为EOF*/
    if (*str==EOF)
        return NULL;
    /*即使首字符是换行符也储存并结束函数，返回值*/
    else if(*str=='\n')
    {
        *(str++)='\0';
        return str;
    }
    else
    {
        temp=str++;/*储存首字符地址*/
        /*储存n-1个值*/
        for (int i = 1; i < n-1; i++)
        {
            *str=getchar();
            /*当遇到换行符时将此位置设置为空字符*/
            if (*str=='\n')
            {
                *str='\0';
                return temp;/*遇到换行符时停止读取输入*/
            }
            str++;/*指针递增，指向下一个元素*/
        }
        *str='\0';/*如果读取输入中没有换行符就将最后一个元素设置为空字符*/
        /*丢弃多余字符*/
        if (*str=='\0')
            while (getchar()!='\n')
                continue;
    }

    return temp;
}