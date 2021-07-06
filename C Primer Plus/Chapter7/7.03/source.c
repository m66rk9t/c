/*统计单词程序*/
#include<ctype.h>           //提供isspace()函数原型
#include<stdbool.h>         //为bool、true、false提供定义
#include<stdio.h>
#include<stdlib.h>
#define END '|'             //符号常量，代表文本结束
int main(void)
{
    char input;             //待输入的字符
    char prev;              //读取前一个字符，判断特殊行
    long num_Chars=0L;      //字符数量
    int num_Words=0;        //单词数量
    int num_Lines=0;        //行数
    int special_Lines=0;    //特殊行数
    bool inWord=false;      //判断单词的开始,true表示单词开始或在单词间，false表示当前是空白字符，下一个字符是单词的开始

    printf("Please enter text to analyzed(enter '|' to end)\n");
    printf("Use blank character to separate words:\n");
    prev='\n';              //判断特殊行
    while((input=getchar())!=END)
    {
        if(input!='\n')     //不将换行符纳入字符数量
            num_Chars++;    //统计字符数量。
        if(input =='\n')    //统计行数
        {
            num_Lines++;
        }
        if(!ispunct(input)&&!isspace(input)&&!inWord)    //如果输入的不是空白字符且标记为假，新字符是新单词的开头
        {
            num_Words++;    //单词数量递增
            inWord=true;    //标记设置为真，没有新单词
        }
        if((ispunct(input)||isspace(input))&&inWord)  //如果输入的是标点符号或空白字符且标记为真，一个单词的结束
        {
            inWord=false;   //标记为假，即将输入新单词
        }
        prev=input;         //读取上一个字符，用于判断该行是否是特殊行
    }
    if (prev!='\n'||input==END)         //'|'字符前不是换行符，该行就是特殊行
    {
        special_Lines++;    //特殊行数递增
    }
    printf("There are %ld characters, %d words, %d lines and %d special lines.\n",num_Chars,num_Words,num_Lines,special_Lines);

    system("pause");
    return 0;
}