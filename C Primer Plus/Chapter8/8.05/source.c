/*EOF与打印ASCII码（需要改！！！！！！！！！！！！）*/
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    char input;
    int i=0;
    printf("Please enter some chararters(press ctrl+z to end):\n");

    for (input=getchar(),i=1; input!=EOF; i++,input=getchar())
    {
        if (input=='\n')
            printf("\\n-%d\t",input);
        else if (input=='\t')
            printf("\\t-%d\t",input);
        else if (input<' ')
        {
            printf("^%c-%d\t",input+64,input);
        }
        else
        {
            printf("%c-%d\t",input,input);
        }
        if(i%10==0)
            putchar('\n');
    }

    printf("Done!\n");
    
    system("pause");
    return 0;
}