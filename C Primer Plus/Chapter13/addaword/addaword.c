/* addaword.c -- 使用fprintf()、fscanf()和rewind() */
#include <stdio.h>
#include <stdlib.h> /*提供exit()原型*/
#include <string.h>
#define MAX 41 /*待输入单词的最大长度*/

int main(void)
{
    FILE *fp;        /*声明指向FILE的指针*/
    char words[MAX]; /*储存输入的单词*/

    /*以追加更新模式打开文件，打开失败则提示错误并异常结束程序*/
    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    /*文字说明*/
    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");

    /*读写操作*/
    /*while入口条件：读取指定流中的格式化输入并写入指定字符串数组*/
    /*while循环体：从指定文件中把格式化输出写入指定流*/
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%s\n", words);

    /*输出追加后文件中的所有内容*/
    puts("File contents:");
    rewind(fp); /*返回到文件开始处*/
    while (fscanf(fp, "%s", words) == 1)
        puts(words);
    puts("Done!");

    /*关闭文件*/
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file.\n");

    return 0;
}
