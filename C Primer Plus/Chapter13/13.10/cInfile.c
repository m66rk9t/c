#include <stdio.h>
#include <stdlib.h> //提供exit()原型
#include <string.h> //提供strchr()、strlen()原型
#define FNUM 10
#define SLEN 81

char *s_gets(char *str, int n);
int c_inFile(FILE *f, char c);

int main(int argc, char *argv[])
{
    FILE *fp;
    char files[FNUM][SLEN];
    int counts = 0;
    char ch;
    int i;
    int f_ct = 0;

    /*检查命令行参数*/
    if (argc == 1 || argc > 12)
    {
        fprintf(stderr, "Usage: %s [character] [filename] "
                        "(Files limitation: 10)\n",
                argv[0]);
        exit(EXIT_FAILURE);
    }
    else if (argc == 2)
    {
        printf("Enter filename (enter '#' in a new line to quit):\n");
        for (i = 0; i < FNUM; i++)
        {
            s_gets(files[i], SLEN);
            if (files[i][0] == '#')
                break;
            else
                f_ct++;
            printf("Next filename:\n");
        }
    }
    else
    {
        for (i = 2; i < argc; i++)
        {
            strcpy(files[i-2], argv[i]);
            f_ct++;
        }
    }

    ch = argv[1][0]; //字符赋值

    /*打开文件，统计指定字符数量*/
    for (i = 0; i < f_ct; i++)
    {
        /*以文本读模式打开文件，打开失败则提示错误并处理下一个文件*/
        if ((fp = fopen(files[i], "r")) == NULL)
        {
            fprintf(stderr, "Can't open %s.\n", files[i]);
            continue;
        }
        /*是否为空文件*/
        else if (getc(fp) == EOF)
        {
            fclose(fp);
            continue;
        }
        else
            rewind(fp);

        /*统计字符数量并报告，处理完关闭文件*/
        counts = c_inFile(fp, ch);
        printf("%d '%c' in %s.\n", counts, ch, files[i]);
        fclose(fp);
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

/*函数定义，返回文件中指定字符出现的次数*/
int c_inFile(FILE *f, char c)
{
    int ch;
    int ct = 0;

    while ((ch = getc(f)) != EOF)
        if (ch == c)
            ct++;

    return ct;
}