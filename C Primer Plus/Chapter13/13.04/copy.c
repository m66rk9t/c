#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *src, *tar;
    char ch;

    /*检查命令行参数*/
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s [source] [target]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /*以二进制读模式打开文件，打开失败则提示错误并异常结束程序*/
    if ((src = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "Can't open %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /*以二进制写模式打开文件，打开失败则提示错误并异常结束程序*/
    if ((tar = fopen(argv[2], "wb")) == NULL)
    {
        fprintf(stderr, "Can't open %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    /*文件内容拷贝*/
    while (fread(&ch, sizeof(char), 1, src) > 0)
        fwrite(&ch, sizeof(char), 1, tar);

    /*关闭文件*/
    fclose(src);
    fclose(tar);

    puts("Done!");

    return 0;
}