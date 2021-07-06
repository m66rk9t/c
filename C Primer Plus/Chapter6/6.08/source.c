/*使用for循环与数组求总分和平均分*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int main(void)
{
    int counter=0;
    float sum,avg;
    sum=avg=0.0;
    float Grades[SIZE];

    printf("Please enter 10 scores:\n");
    for(;counter<SIZE;counter++)
    {
        scanf("%f",&Grades[counter]);
        sum+=Grades[counter];
    }
    avg=sum/(float)SIZE;
    printf("Overall scores:%.1f\nAverage score:%6.2f\n",sum,avg);

    system("pause");
    return 0;
}