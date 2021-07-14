/* append.c -- 使用命令行参数把文件附加到另一个文件末尾 */
#include <stdio.h>
#include <stdlib.h> //提供exit()原型
#include <string.h> //提供strcmp()原型
#define BUFSIZE 1024
void append(FILE *ft, FILE *fs); //函数原型
void display(FILE *f);           //函数原型

int main(int argc, char *argv[])
{
    FILE *fs, *ft; /*fs指向源文件，ft指向目标文件*/
    int files = 0; /*成功附加的文件数量*/
    int ch;
    /*检查命令行参数*/
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s [target] [source]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /*以文本追加模式打开目标文件，打开失败则提示错误并异常结束程序*/
    if ((ft = fopen(argv[1], "a+")) == NULL)
    {
        fprintf(stderr, "Can't open %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    /*为目标文件创建输出缓冲区，创建失败则提示错误并异常结束程序*/
    if (setvbuf(ft, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fprintf(stderr, "Can't create output buffer.\n");
        exit(EXIT_FAILURE);
    }

    /*使用argc控制循环依次打开源文件*/
    for (int i = 2; i < argc; i++)
    {
        /*是否同名*/
        if (strcmp(argv[1], argv[i]) == 0)
        {
            fprintf(stderr, "Can't append file to itself.\n");
            continue;
        }
        /*以文本读模式打开源文件，打开失败则开始新一轮循环*/
        else if ((fs = fopen(argv[i], "r")) == NULL)
        {
            fprintf(stderr, "Can't open %s.\n", argv[i]);
            continue;
        }
        /*是否为空文件*/
        else if ((ch = getc(fs)) == EOF)
        {
            fprintf(stderr, "%s is an empty file.\n", argv[i]);
            continue;
        }
        else
        {
            rewind(fs); //定位至文件开始处
            /*为源文件创建输出缓冲区，创建失败则提示错误并异常结束程序*/
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fprintf(stderr, "Can't create input buffer.\n");
                exit(EXIT_FAILURE);
            }
        }

        /*追加文件内容*/
        append(ft, fs);
        /*如果读取错误则提示错误*/
        if (ferror(fs) != 0)
            fprintf(stderr, "Error in reading file %s.\n", argv[i]);
        /*如果写入错误则提示错误*/
        if (ferror(ft) != 0)
            fprintf(stderr, "Error in wiriting file %s.\n", argv[1]);
        /*提示追加成功*/
        fprintf(stdout, "File %s appended.\n", argv[i]);
        /*关闭源文件*/
        fclose(fs);
        /*追加数量递增*/
        files++;
    }
    printf("Done appending, %d files appended.\n", files);

    /*输出，收尾*/
    rewind(ft);
    fprintf(stdout, "File %s contents:\n", argv[1]);
    display(ft);
    fclose(ft);

    return 0;
}

/*函数定义，追加文件内容*/
void append(FILE *ft, FILE *fs)
{
    size_t bytes;              /*字节数*/
    static char buff[BUFSIZE]; /*静态无链接变量*/
    while ((bytes = fread(buff, sizeof(char), BUFSIZE, fs)) > 0)
        fwrite(buff, sizeof(char), bytes, ft);
}

/*函数定义，在屏幕上打印文件内容*/
void display(FILE *f)
{
    char ch;
    while ((ch = getc(f)) != EOF)
        putc(ch, stdout);
    putchar('\n');
    puts("Done displaying!");
}