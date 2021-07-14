/* reducto.c -- 把文件压缩成原来的1/3！*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 81
char *s_gets(char *st, int n); //函数原型

int main(void)
{
    FILE *fs, *ft;  //分别指向源文件和目标文件
    char src[SLEN]; //储存源文件名
    char tar[SLEN]; //储存目标文件名
    char ch;        //读取的字符
    int count = 0;  //计数

    /*读取源文件名*/
    printf("Enter source file:\n");
    s_gets(src, SLEN);

    /*以文本读模式打开源文件，打开失败则提示错误并异常结束程序*/
    if ((fs = fopen(src, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s.\n", src);
        exit(EXIT_FAILURE);
    }

    /*拼接目标文件名字符串*/
    strncpy(tar, src, SLEN - 5);
    tar[SLEN - 5] = '\0';
    strcat(tar, ".red"); //tar中第1个空字符被.red覆盖

    /*创建目标文件并打开，打开失败则提示错误并异常结束程序*/
    if ((ft = fopen(tar, "w")) == NULL)
    {
        fprintf(stderr, "Can't open %s.\n", tar);
        exit(EXIT_FAILURE);
    }

    /*使用压缩算法写入文件*/
    while ((ch = getc(fs)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, ft);

    /*收尾*/
    if (fclose(fs) != 0 || fclose(ft) != 0)
        fprintf(stderr, "Error in closing files.\n");

    puts("Done!");

    return 0;
}

/*函数定义，读取字符串，保留输入中的换行符并处理输入中的多余字符*/
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(ret_val, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}