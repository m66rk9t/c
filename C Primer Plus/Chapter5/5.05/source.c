/*自动类型转换*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int i;
    float fl;
    char ch;

    fl=i=ch='C';
    printf("ch=%c,i=%d,fl=%.2f\n",ch,i,fl);
    ch=ch+1;
    i=fl+2*ch;
    fl=2.0*ch+i;
    printf("ch=%c,i=%d,fl=%.2f\n",ch,i,fl);
    ch=1107;    //降级上溢
    printf("Now ch=%c\n",ch);
    ch=80.89;   //降级截断
    printf("Now ch=%c\n",ch);

    system("pause");
    return 0;
}