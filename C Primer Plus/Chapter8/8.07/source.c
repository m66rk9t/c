/*EOF与统计单词数量及其平均字母数*/
#include<ctype.h>
#include<stdbool.h>         //为bool、true、false提供定义
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    char input;             //待输入的字符
    double num_Letter=0;      //字母数量
    double num_Words=0;        //单词数量
    bool inWord=false;      //判断单词的开始,true表示单词开始或在单词间，false表示当前是空白字符，下一个字符是单词的开始
    
    printf("Please enter text to analyzed(press Ctrl+Z to end),\n");
    printf("Use blank character to separate words:\n");
    while((input=getchar())!=EOF)
    {
        if(isalnum(input))     //不将换行符纳入字符数量
            num_Letter++;    //统计字符数量
        if(!ispunct(input)&&!isspace(input)&&!inWord)    //如果输入的不是空白字符且标记为假，新字符是新单词的开头
        {
            num_Words++;    //单词数量递增
            inWord=true;    //标记设置为真，没有新单词
        }
        if((ispunct(input)||isspace(input))&&inWord)  //如果输入的是标点符号或空白字符且标记为真，一个单词的结束
        {
            inWord=false;   //标记为假，即将输入新单词
        }
    }
    printf("Letters:%.f\nWords:%.f\nAvg:%.2f/word\n",num_Letter,num_Words,num_Letter/num_Words);

    system("pause");
    return 0;
}