/*模拟EOF*/
#include<stdio.h>   //提供了EOF定义
#include<stdlib.h>
int main(void)
{
    char input;
    printf("Please enter the text to be displayed,press Enter to print the text on the next line,\n");
    printf("press Ctrl+Z to end:\n");
    while ((input=getchar())!=EOF)
    {
        putchar(input);
    }
    printf("Done!\n");
    system("pause");
    return 0;
}