/* fseek.c -- 使用fseek()和ftell() */
#include <stdio.h>
#include <stdlib.h> /*提供exit()原型*/
#define SLEN 81

int main(void)
{
    char file[SLEN];  /*储存文件名字符串*/
    FILE *fp;         /*待打开的文件*/
    long size = 0L;   /*文件字节数*/
    char ch;          /*读取一个字符*/
    long offset = 0L; /*偏移量*/

    /*打开文件*/
    puts("Enter the name of file to be processed:");
    scanf("%80s", file); /*读取文件名字符串*/
    /*以二进制只读模式打开文件，打开失败则提示错误并异常结束程序*/
    if ((fp = fopen(file, "rb")) == NULL)
    {
        fprintf(stderr, "Can't open file %s.\n", file);
        exit(EXIT_FAILURE);
    }

    /*计算文件大小*/
    fseek(fp, 0L, SEEK_END);                                 /*定位至文件结尾处*/
    size = ftell(fp);                                        /*计算文件字节数*/
    fprintf(stdout, "File %s has %ld bytes.\n", file, size); /*输出文件字节数*/

    /*设置定位*/
    rewind(fp); /*定位至文件开始处*/
    puts("Enter the offset you want to set:");
    scanf("%ld", &offset);       /*输入偏移量*/
    fseek(fp, offset, SEEK_SET); /*定位*/
    size = ftell(fp);            /*计算文件字节数*/
    fprintf(stdout, "The number of bytes from the current position "
                    "\nto the beginning of the file is %d bytes.\n",
            size);

    /*输出当前为位置上的字符*/
    ch = getc(fp);/*读取字符*/
    if (ch == EOF)
        puts("It's EOF!");
    else if (ch == '\n')
        puts("It's \\n.");
    else
        fprintf(stdout, "It's %c.\n", ch);
    
    /*关闭文件*/
    if (fclose(fp) != 0)
        fprintf(stdout, "Error in closing file %s.\n", file);    

    return 0;
}