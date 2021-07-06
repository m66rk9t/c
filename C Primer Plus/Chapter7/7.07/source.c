/*goto语句练习*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    char input;
    
    while((input=getchar())!='#')
    {
        if(input=='\n')
            continue;
        printf("Step1\n");
        if(input=='a')
            continue;
        else if(input=='b')
            break;
        else if(input=='c')
            goto laststep;
        printf("Step2\n");
        laststep:printf("Step3\n"); //goto标签后的语句也会被程序按顺序执行
    }
    printf("Done!\n");

    system("pause");
    return 0;
}