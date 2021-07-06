/*字母的位置*/
#include<ctype.h>                                   /*提供函数原型*/
#include<stdio.h>
#include<stdlib.h>
int letter_position(char chara);                    /*函数原型*/
int main(void)
{
    char input;                                     /*存储待输入的字符*/
    int position;                                   /*存储字母在字母表中的位置*/
    
    /*文字说明*/
    printf("Please enter some characters(press Ctrl+Z to qiut):\n");
    while (scanf("%c",&input)!=-1)                  /*直到遇到文件结尾结束循环*/
    {
        if (input=='\n')                            /*处理文件结尾前的换行符*/
        {
            continue;
        }
        position=letter_position(input);            /*函数表达式语句*/
        if (position==-1)                           /*处理非字母字符*/
        {
            printf("%c is not a letter.\n",input);  /*文字说明*/
        }
        else                                        /*报告字母在字母表中的位置*/
        {   /*文字说明*/
            printf("The position of %c in the alphabet is %d.\n",input,position);
        }
    }
    printf("Done!\n");

    system("pause");
    return 0;
}

int letter_position(char chara)                     /*函数定义*/
{
    int position;                                   /*存储返回值，即字母在字母表中的位置*/
    if (isalpha(chara))                             /*判断该字符是否为字母*/
    {
        if (chara>='A'&&chara<='Z')                 /*处理大写字母的位置*/
        {
            position=chara-'A'+1;
        }
        else                                        /*处理小写字母的位置*/
        {
            position=chara-'a'+1;
        }
    }
    else                                            /*处理非字母字符，返回值为-1*/
    {
        position=-1;
    }

    return position;                                /*返回值*/
}