/* reverse.c -- 倒叙显示文件的内容*/
#include <stdio.h>
#include <stdlib.h>   /*提供exit()原型*/
#define CNTL_Z '\032' /*DOS文本文件中的文件结尾标记*/
#define SLEN 81

int main(void)
{
    char file[SLEN];  /*存储文件名字符串*/
    char ch;          /*读取的字符*/
    FILE *fp;         /*指向待打开的文件*/
    long count, last; /*用于记录文件位置*/

    puts("Enter the name of the file to be processed:");
    scanf("%80s", file); /*从标准输入中读取文件名字符串*/

    /*以二进制只读模式打开文件，打开失败则提示错误并异常结束程序*/
    if ((fp = fopen(file, "rb")) == NULL)
    {
        printf("reverse can't open %s\n", file);
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Output the contents of the file %s in reverse order:", file);
    fseek(fp, 0L, SEEK_END); /*定位到文件末尾*/
    last = ftell(fp);        /*记录当前位置距文件开始出的字节数*/

    /*遍历文件，输出文件内容*/
    for (count = 1L; count <= last; count++)
    {
        fseek(fp, -count, SEEK_END);    /*每次迭代都从文件结尾处回退count个字节*/
        ch = getc(fp);                  /*读取一个字符*/
        if (ch != CNTL_Z && ch != '\r') /*MS-DOS文件*/
            putchar(ch);
    }
    putchar('\n');
    fclose(fp); /*关闭文件*/

    return 0;
}