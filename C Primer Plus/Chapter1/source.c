#include<stdio.h>
#include<stdlib.h>
int main()
{
    //英寸转厘米
    float in,cm;
    printf("Please enter an number(in):\n");
    scanf("%f",&in);
    cm=in*2.54;
    printf("%fin to cm is %fcm\n",in,cm);
    system("pause");
    return 0;
}