/*使用求模运算符将秒转换成普通计时格式*/
#include<stdio.h>
#include<stdlib.h>
#define SEC_PER_MIN 60
int main(void)
{
    int input,secs,mins;
    
    printf("Please enter the number of seconds:\n");
    scanf("%d",&input);
    while(input>0)
    {
        mins=input/SEC_PER_MIN;
        secs=input%SEC_PER_MIN;
        printf("%d seconds is %d minutes,%d seconds\n",input,mins,secs);
        printf("Please enter the number of seconds(<=0 to quit):\n");
        scanf("%d",&input);
    }
    printf("Done!\n");

    system("pause");
    return 0;
}