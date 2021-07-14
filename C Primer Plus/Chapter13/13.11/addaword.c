#include <stdio.h>
#include <stdlib.h> /*提供exit()原型*/
#define MAX 41      /*待输入单词的最大长度*/

int main(void)
{
    FILE *fp1, *fp2; /*分别指向追加文件和储存追加单词数量的文件*/
    char words[MAX]; /*储存输入的单词*/
    int total = 0;   /*追加单词的数量*/
    size_t byte = 1;

    /*以追加更新模式打开文件，打开失败则提示错误并异常结束程序*/
    if ((fp1 = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    /*以读取更新模式打开文件，打开失败则提示错误并异常结束程序*/
    if ((fp2 = fopen("total", "r+")) == NULL)
    {
        fprintf(stdout, "Can't open \"total\" file.\n");
        exit(EXIT_FAILURE);
    }
    if (fread(&total, sizeof(int), byte, fp2))
    {
        printf("%d words have been added.\n", total);
        rewind(fp2);
    }

    /*文字说明*/
    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");

    /*读写操作*/
    /*while入口条件：读取指定流中的格式化输入并写入指定字符串数组*/
    /*while循环体：从指定文件中把格式化输出写入指定流*/
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
    {
        fprintf(fp1, "%s\n", words);
        total++;
        rewind(fp2);
        fwrite(&total, sizeof(int), byte, fp2);
    }

    /*输出追加后文件中的所有内容*/
    puts("File contents:");
    rewind(fp1); /*返回到文件开始处*/
    while (fscanf(fp1, "%s", words) == 1)
        puts(words);
    printf("Added %d words.\nDone!\n", total);

    /*关闭文件*/
    if (fclose(fp1) != 0)
        fprintf(stderr, "Error closing file.\n");

    return 0;
}
