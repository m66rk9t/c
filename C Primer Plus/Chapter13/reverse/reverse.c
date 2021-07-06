/* reverse.c -- 倒序显示文件的内容*/
#include <stdio.h>
#include <stdlib.h>   /*提供exit()原型*/
#define CNTL_Z '\032' /*DOS文本文件中的文件结尾i标记*/
#define SLEN 81
int main(void)
{
    char file[SLEN]; /*储存文件名字符串*/
    char ch;         /*储存读取的字符*/
    FILE *fp;        /*指向FILE的指针*/
    long count, last;

    puts("Enter the name of the file to be processed:");
    scanf("%80s", file); /*输入文件名*/

    if ((fp = fopen(file, "rb")) == NULL)
    { /*以二进制只读模式打开文件*/
        printf("reverse can't open %s\n", file);
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0L, SEEK_END); /*定位到文件结尾*/
    last = ftell(fp);        /*返回文件结尾至开始处的字节数*/
    for (count = 1L; count <= last; count++)
    {
        fseek(fp, -count, SEEK_END); /*回退*/
        ch = getc(fp);
        if (ch != CNTL_Z && ch != 'r') /*MS-DOS文件*/
            putchar(ch);               /*打印读取的字符*/
    }

    fclose(fp); /*关闭文件*/

    return 0;
}
