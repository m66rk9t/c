/*输入身高（厘米）转换成以英寸与英寸为单位的值，
1foot=30.48cm，1inch=30.48cm/12*/
#include<stdio.h>
#include<stdlib.h>
#define CM_OF_FOOT 30.48
#define CM_OF_INCH 30.48/12
int main(void)
{
    double input,inches;
    int feet;
    printf("Please enter your height(cm):\n");
    scanf("%lf",&input);
    while(input>0)
    {
        feet=(int)(input/CM_OF_FOOT);    //英尺数
        inches=(input-30.48*feet)/(CM_OF_INCH); //英寸数
        /*编译时替换，相当于：
        inches=(input-30.48*feet)/(30.48/12);
        inches=(input-30.48*feet)/30.48*12;*/
        printf("%.1f cm = %.d feet,%.1f inches\n",input,feet,inches);
        printf("Please enter your height(<=0 to quit):\n");
        scanf("%lf",&input);
    }

    printf("Done!\n");

    system("pause");
    return 0;
}