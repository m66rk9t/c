/*打印字符与ASCII码*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    char input;
    int count=0;
    printf("Please enter some charchters to analysis(enter '#' to end):\n");
    while((input=getchar())!='#')
    {
        count++;
        printf("%c-%03d\t",input,input);
        if(count%8==0)
            printf("\n");
    }
    printf("Done!\n");

    system("pause");
    return 0;
}