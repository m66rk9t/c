/* append.c -- 把文件附加到另一个文件末尾 */
#include <stdio.h>
#include <stdlib.h>                    /*提供exit()原型*/
#include <string.h>                    /*提供strchr()和strcmp()原型*/
#define BUFSIZE 4096                   /*缓冲区大小*/
#define SLEN 81                        /*文件名字符串长度*/
void append(FILE *source, FILE *dest); /*附加文件函数原型*/
char *s_gets(char *st, int n);         /*读取字符串函数原型*/

int main(void)
{
    FILE *fa, *fs;       /*fa指向目标文件，fs指向源文件*/
    int files = 0;       /*附加的文件数量*/
    char file_app[SLEN]; /*目标文件名*/
    char file_src[SLEN]; /*源文件名*/
    int ch;              /*读取的字符*/

    puts("Enter name of destination file:");
    s_gets(file_app, SLEN); /*读取目标文件名*/
    /*以文本追加模式打开文件，打开失败则提示错误并退出程序*/
    if ((fa = fopen(file_app, "a+")) == NULL)
    {
        fprintf(stderr, "Can't open %s", file_app);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    { /*为目标文件创建输出缓冲区*/
        /*让setvbuf()函数自动分配缓冲区存储空间*/
        /*创建失败则提示错误并退出程序*/
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }
    puts("Enter name of first source file (empty line to quit):");
    /*读取源文件名字符串，读取失败或遇到结束行就退出循环*/
    while (s_gets(file_src, SLEN) && file_src[0] != '\0')
    {
        /*如果输入的目标文件名与源文件名一致则提示错误并退出程序*/
        if (strcmp(file_src, file_app) == 0)
            fputs("Can't append file to itself\n", stderr);
        /*以二进制制度模式打开文件，打开失败则提示错误并退出程序*/
        else if ((fs = fopen(file_src, "r")) == NULL)
            fprintf(stderr, "Can't open %s\n", file_src);
        else
        { /*为目标文件创建输出缓冲区*/
            /*让setvbuf()函数自动分配缓冲区存储空间*/
            /*创建失败则提示错误并开始新一轮迭代*/
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Can't create input buffer\n", stderr);
                continue;
            }

            append(fs, fa); /*附加文件内容*/
            /*如果读取错误则提示错误*/
            if (ferror(fs) != 0)
                fprintf(stderr, "Error in reading file %s.\n", file_src);
            /*如果写入错误则提示错误*/
            if (ferror(fa) != 0)
                fprintf(stderr, "Error in wiriting file %s.\n", file_app);
            fclose(fs); /*关闭源文件*/
            files++;    /*附加文件数量递增*/
            printf("File %s appended .\n", file_src);
            puts("Next file (empty line to quit):");
        }
    }
    printf("Done appending. %d files appended.\n", files); /*输出附加成功的文件数量*/
    rewind(fa);                                            /*定位到文件开始出*/
    printf("%s contents:\n", file_app);
    /*输出目标文件中的内容*/
    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("Done displaying.");
    fclose(fa); /*关闭目标文件*/

    return 0;
}
void append(FILE *source, FILE *dest)
{
    size_t bytes;              /*数据块个数，本程序内为缓冲区字节数*/
    static char temp[BUFSIZE]; /*静态无链接变量，只分配一次缓冲区*/

    /*附加文件内容，读写操作*/
    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
}
char *s_gets(char *st, int n)
{
    char *ret_val; /*字符串地址*/
    char *find;    /*字符地址*/

    ret_val = fgets(st, n, stdin); /*读取输入中的字符串*/
    if (ret_val)
    {
        find = strchr(st, '\n');
        /*查找换行符并替换为空字符*/
        if (find)
            *find = '\0';
        else
            /*处理多余字符*/
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}