/*flaot类型与double类型的最少有效位数*/
#include<stdio.h>
#include<stdlib.h>
#include<float.h>
int main(void)
{
    float num1=1.0/3.0;
    double num2=1.0/3.0;

    printf("num1:%.6f %.12f %.16f\n",num1,num1,num1);
    printf("num2:%.6f %.12f %.16f\n",num2,num2,num2);
    printf("float   precision = %d digits\n",FLT_DIG);
    printf("double  precision = %d digits\n",DBL_DIG);

    system("pause");
    return 0;
}