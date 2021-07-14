/* count.c -- 使用标准 I/O */
#include <stdio.h>
#include <stdlib.h> //提供exit()的原型

int main(void)
{
    FILE *fp;                //文件指针
    char *fs;                //储存文件名字符串
    int ch;                  //读取文件时，储存每个字符的地方
    unsigned long count = 0; //字符计数

    /*输入文件名*/
    puts("Enter filename:");
    while (scanf("%s", fs) != 1)
    {
        fprintf(stderr, "%s does not exist.\n", fs);
        puts("Please enter again:");
    }

    /*以文本读模式打开文件，打开失败则提示错误并异常结束程序*/
    if ((fp = fopen(fs, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", fs);
        exit(EXIT_FAILURE);
    }

    /*输出文件内容并计算文件中字符个数*/
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout); //与putchar(ch);相同
        count++;          //计数
    }
    fclose(fp); //关闭文件
    fprintf(stdout, "\nFile %s has %lu characters\n", fs, count);

    return 0;
}