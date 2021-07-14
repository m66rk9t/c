/* 要求a */
#include <stdio.h>
#include <stdlib.h> //提供exit()原型
#include <stdbool.h>
#include <string.h> //提供strchar()原型
#define SLEN 81     //文件名字符串大小上限
#define BUFSIZE 1024
static char buff1[BUFSIZE];
static char buff2[BUFSIZE];
/*函数原型*/
char *s_gets(char *str, int n);
void display(FILE *f1, FILE *f2);

int main(int argc, char *argv[])
{
    FILE *f1, *f2;  /*文件指针，分别指向第1、第2个文件*/
    char fn1[SLEN]; /*储存第1个文件名字符串*/
    char fn2[SLEN]; /*储存第2个文件名字符串*/

    /*检查命令行参数*/
    if (argc == 1)
    {
        printf("Enter the first  filename(character limit 80):\n");
        s_gets(fn1, SLEN);
        printf("Enter the second filename(character limit 80):\n");
        s_gets(fn2, SLEN);
    }
    else if (argc == 2)
    {
        fprintf(stderr, "Uage: %s [filename1] [filename2]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    else
    {
        strncpy(fn1, argv[1], SLEN);
        strncpy(fn2, argv[2], SLEN);
    }

    /*打开文件，打开失败则提示错误并异常结束程序*/
    if ((f1 = fopen(fn1, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s.\n", fn1);
        exit(EXIT_FAILURE);
    }
    if ((f2 = fopen(fn2, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s.\n", fn2);
        exit(EXIT_FAILURE);
    }

    /*判断是否为空文件，不是空文件就按要求输出文件内容*/
    if (getc(f1) != EOF && getc(f2) != EOF)
    {
        rewind(f1);
        rewind(f2);
        printf("display:\n");
        display(f1, f2);
    }
    else
    {
        fprintf(stderr, "Error: Empty File.\n");
        exit(EXIT_FAILURE);
    }

    puts("Done!");

    return 0;
}

/*函数定义，读取字符串，保留输入中的换行符并处理输入中的多余字符*/
char *s_gets(char *str, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(str, n, stdin);
    if (ret_val)
    {
        find = strchr(str, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}

/*函数定义*/
void display(FILE *f1, FILE *f2)
{
    char *eof1, *eof2;

    while (f1 != NULL && f2 != NULL)
    {
        if ((eof1 = fgets(buff1, BUFSIZE, f1)) && (eof2 = fgets(buff2, BUFSIZE, f2)))
        {
            fputs(buff1, stdout);
            fputs(buff2, stdout);
        }
        else if (eof1 == NULL && f1 != NULL)
        {
            fclose(f1);
            f1 = NULL;
            while (fgets(buff2, BUFSIZE, f2) != NULL)
            {
                fputs(buff2, stdout);
            }
        }
        else if (eof2 == NULL && f2 != NULL)
        {
            fclose(f2);
            f2 = NULL;
            do
            {
                fputs(buff1, stdout);
            } while (fgets(buff1, BUFSIZE, f1) != NULL);
        }
        else
            break;
    }
}

/*函数定义*/
void displayB(FILE *f1, FILE *f2)
{
    char *eof1, *eof2;

    while (f1 != NULL && f2 != NULL)
    {
        if ((eof1 = fgets(buff1, BUFSIZE, f1)) && (eof2 = fgets(buff2, BUFSIZE, f2)))
        {
            fputs(buff1, stdout);
            fputs(buff2, stdout);
        }
        else if (eof1 == NULL && f1 != NULL)
        {
            fclose(f1);
            f1 = NULL;
            while (fgets(buff2, BUFSIZE, f2) != NULL)
            {
                fputs(buff2, stdout);
            }
        }
        else if (eof2 == NULL && f2 != NULL)
        {
            fclose(f2);
            f2 = NULL;
            do
            {
                fputs(buff1, stdout);
            } while (fgets(buff1, BUFSIZE, f1) != NULL);
        }
        else
            break;
    }
}