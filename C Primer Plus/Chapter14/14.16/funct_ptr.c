/* func_ptr.c -- 使用函数指针 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81
char showmenu(void);                      //显示菜单的函数原型
void eatline(void);                       //清理输入行的函数原型
void show(void (*fp)(char *), char *str); //函数指针作参数，使用指定函数处理字符串的函数原型
void ToUpper(char *);                     //把字符串所有字母字符转换成大写的函数原型
void ToLower(char *);                     //把字符串所有字母字符转换成大写的函数原型
void Transpose(char *);                   //把字符串大小写字母字符转置的函数原型
void Dummy(char *);                       //不对字符串作任何处理的函数原型
char *s_gets(char *st, int n);            //读取输入字符串的函数原型

int main(void)
{
    char line[LEN];       //储存输入的字符串
    char copy[LEN];       //储存处理后的字符串
    char choice;          //储存菜单选项字符
    void (*pfun)(char *); //声明一个函数指针，被指向的函数接受char*类型的参数，且返回类型为void
    puts("Enter a string (empty line to quit):");

    /*读取字符串*/
    while (s_gets(line, LEN) != NULL && line[0] != '\0')
    {
        /*输入选项*/
        while ((choice = showmenu()) != 'n')
        {
            /*根据指定的菜单选项，将指定的函数地址赋给函数指针*/
            switch (choice) // switch sets pointer
            {
            case 'u':pfun = ToUpper;    break;
            case 'l':pfun = ToLower;    break;
            case 't':pfun = Transpose;  break;
            case 'o':pfun = Dummy;      break;
            }
            strcpy(copy, line); //拷贝字符串
            show(pfun, copy);   //函数指针作参数，调用指定函数处理字符串并打印处理结果
        }
        puts("Enter a string (empty line to quit):");
    }
    puts("Bye!");

    return 0;
}

/*显示菜单的函数定义*/
char showmenu(void)
{
    char ans; //储存菜单选项字符

    /*打印菜单*/
    puts("Enter menu choice:");
    puts("u) uppercase       l) lowercase");
    puts("t) transposed case o) original case");
    puts("n) next string");

    ans = getchar();    //读取输入的选项字符
    ans = tolower(ans); //转换成小写字母
    eatline();          //清理输入行

    /*判断是否输入了错误选项*/
    while (strchr("ulton", ans) == NULL)
    {
        puts("Please enter a u, l, t, o, or n:"); //提示错误
        ans = tolower(getchar());                 //重新读取输入
        eatline();                                //清理输入行
    }

    return ans; //返回选项字符
}

/*清理输入行的函数定义*/
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

/*把字符串所有字母字符转换成大写的函数原定义*/
void ToUpper(char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

/*把字符串所有字母字符转换成小写的函数原定义*/
void ToLower(char *str)
{
    while (*str)
    {
        *str = tolower(*str);
        str++;
    }
}

/*把字符串大小写字母字符转置的函数定义*/
void Transpose(char *str)
{
    while (*str)
    {
        if (islower(*str))
            *str = toupper(*str);
        else if (isupper(*str))
            *str = tolower(*str);
        str++;
    }
}

/*不对字符串作任何处理的函数定义*/
void Dummy(char *str) {}

/*根据指定函数处理字符串并打印处理结果的函数定义*/
void show(void (*fp)(char *), char *str)
{
    (*fp)(str); //调用指定函数
    puts(str);  //打印处理结果
}

/*读取输入字符串的函数定义*/
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // 查找换行符
        if (find)                // 如果地址不是 NULL，
            *find = '\0';        // 在此处放置一个空字符
        else
            while (getchar() != '\n')
                continue; // 处理输入行中剩余的字符
    }
    return ret_val;
}