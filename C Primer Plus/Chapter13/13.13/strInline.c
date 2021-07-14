#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 256
int strinline(const char *arr, const char *str);
int main(int argc, char *argv[])
{
    FILE *fp;
    char line[SLEN];

    /*检查命令行参数*/
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s [string] [file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /*打开文件*/
    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    else if (getc(fp) == EOF)
    {
        fprintf(stderr, "ERROR: Empty file.\n");
        exit(EXIT_FAILURE);
    }
    else
        rewind(fp);

    /*输出字符串所在行的内容*/
    printf("The line of \"%s\" in file %s:\n", argv[1], argv[2]);
    while (fgets(line, SLEN, fp) != NULL)
        if (strinline(line, argv[1]))
            fputs(line, stdout);

    /*收尾工作*/
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Error closing file.\n");
        exit(EXIT_FAILURE);
    }
    puts("Done!");

    return 0;
}

/*函数定义，检查指定字符串是否存在*/
int strinline(const char *arr, const char *str)
{
    char *find;

    find = strstr(arr, str);
    if (find)
        return 1;

    return 0;
}