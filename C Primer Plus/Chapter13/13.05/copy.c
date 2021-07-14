#include <stdio.h>
#include <stdlib.h> //提供exit()原型
#include <ctype.h>  //提供toupper()原型
#define SLEN 81     //文件名字符串最大长度
int main(void)
{
    FILE *fs, *ft;  //分别指向源文件与目标文件
    char src[SLEN]; //储存源文件名字符串
    char tar[SLEN]; //储存目标文件名字符串
    char ch;        //读取字符

    /*输入文件名*/
    puts("Enter source file:");
    scanf("%s", src);
    puts("Enter target file:");
    scanf("%s", tar);

    /*以文本读模式打开源文件，打开失败则提示错误并异常结束程序*/
    if ((fs = fopen(src, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s.\n", src);
        exit(EXIT_FAILURE);
    }

    /*以文本写模式打开目标文件，打开失败则提示错误并异常结束程序*/
    if ((ft = fopen(tar, "w")) == NULL)
    {
        fprintf(stderr, "Can't open %s.\n", src);
        exit(EXIT_FAILURE);
    }

    /*文件内容拷贝*/
    while (fscanf(fs, "%c", &ch) == 1)
    {
        ch = toupper(ch);      //转换为大写字母
        fprintf(ft, "%c", ch); //写入目标文件
    }

    /*关闭文件*/
    fclose(fs);
    fclose(ft);

    puts("Done!");

    return 0;
}