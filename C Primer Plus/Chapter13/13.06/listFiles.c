#include <stdio.h>
#include <stdlib.h> //提供exit()原型
#define BUFSIZE 128

int main(int argc, char *argv[])
{
    FILE *fp;
    char buff[BUFSIZE];
    char ch;

    /*检查命令行参数*/
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /*依次读取文件内容*/
    for (int i = 0; i < argc - 1; i++)
    {
        /*以文本读模式打开文件，打开失败则提示错误并异常结束程序*/
        if ((fp = fopen(argv[i + 1], "r")) == NULL)
        {
            fprintf(stderr, "Can't open %s.\n", argv[i + 1]);
            exit(EXIT_FAILURE);
        }

        /*判断是否为空文件*/
        if ((ch = getc(fp)) != EOF)
            rewind(fp); //不是空文件，重新定位至文件开始处
        else
        {
            fprintf(stderr, "%s is an empty file.\n", argv[i + 1]);
            continue; //是空文件，开始新一轮循环，读取下一个文件
        }

        /*使用标准I/O读取并输出文件内容*/
        fprintf(stdout, "%s contents:\n", argv[i + 1]);
        while (fgets(buff, BUFSIZE, fp) != NULL)
            fputs(buff, stdout);

        /*关闭文件*/
        fclose(fp);
    }
    puts("Done!");

    return 0;
}