/*switch语句练习3*/
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    char input; //待分析的输入文本
    int space,lines,others;
    space=lines=others=0;   //分别统计空格数、换行符数、其他字符数

    printf("Please enter a text for analysis(enter '#' to end):\n");
    while ((input=getchar())!='#')  //读取到'#'字符数结束循环
    {
        switch (input)
        {
            case '\040':    //空格，八进制ASCII码值是40
                space++;
                break;
            case '\n':      //换行符
                lines++;
                break;
            default:        //其他字符
                others++;
                break;
        }
    }
    printf("There are %d spaces, %d '\\n', and %d other characters.\n",space,lines,others);

    system("pause");
    return 0;
}