#include <stdio.h>
#include <stdlib.h>
#define BUF 256
int has_ch(char ch, const char *line); //函数原型
int main(int argc, char *argv[])
{
    FILE *fp;       //FILE指针
    char ch;        //读取字符
    char line[BUF]; //储存一行字符串

    /*检查命令行参数*/
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s [character] [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ch = argv[1][0]; //字符赋值

    /*以文本读模式打开文件，打开失败则提示错误并异常结束程序*/
    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    /*以行为单位读取字符串并判断是否存在指定字符*/
    while (fgets(line, BUF, fp) != NULL)
    {
        if (has_ch(ch, line))    //是否存在指定字符
            fputs(line, stdout); //输出一行字符串
    }
    fclose(fp); //关闭文件

    return 0;
}
/*函数定义*/
int has_ch(char ch, const char *line)
{
    while (*line)          //空字符时结束循环
        if (ch == *line++) //判断
            return 1;
    return 0;
}