/*简单的温度转换器*/
#include<stdio.h>
#include<stdlib.h>
void Temperatures(float para);
int main(void)
{
    float C;
    int i;
    printf("Please enter a floating-point number as Celsius:");
    i=scanf("%f",&C);
    while(i==1)
    {
        Temperatures(C);
        printf("Now enter the next floating-point number as Celsius:");
        i=scanf("%f",&C);
    }
    printf("Done!\n");
}

void Temperatures(float para)
{
    float F,T;
    const float TO_F_1=5.0/9.0,TO_F_2=32.0f;
    const float TO_T=273.16f;
    F=para/(TO_F_1)+TO_F_2;
    T=para+TO_T;
    printf("%.2fC=%.2fF=%.2fK\n",para,F,T);
}