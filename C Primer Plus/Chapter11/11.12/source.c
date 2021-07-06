#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
    int words = 0;       /*单词数量*/
    int uppers = 0;      /*大写字母数量*/
    int lowers = 0;      /*小写字母数量*/
    int puncts = 0;      /*标点符号数量*/
    int digits = 0;      /*数字字符数量*/
    bool inWord = false; /*判断是否在单词内部*/
    char input;          /*读取输入的字符*/

    printf("Please enter some sentences"
           " (press Ctrl+Z on a new line to quit.):\n");
    while ((input = getchar()) != EOF)
    {
        /*如果字符既不是空白字符也不不是单词的结束*/
        if (!isspace(input) && !inWord)
        {
            words++;       /*单词书递增*/
            inWord = true; /*设置为在单词内*/
        }
        if (isupper(input)) /*大写字母*/
            uppers++;
        if (islower(input)) /*小写字母*/
            lowers++;
        if (ispunct(input)) /*标点符号*/
            puncts++;
        if (isdigit(input)) /*数字字符*/
            digits++;
        /*如果字符是空格且inWord为true，表明单词已结束*/
        if (isspace(input) && inWord)
            inWord = false;
    }
    printf("Words:%d\nUppers:%d\nLowers:%d\n", words, uppers, lowers);
    printf("Puncts:%d\nDigits:%d\n", puncts, digits);
    puts("Done!");

    return 0;
}