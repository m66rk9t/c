#include <math.h>
#include <stdio.h>
#define SIZE 100
double additself(double val);
double mutitself(double val);
void transform(double *, double *, int, double(*pfun)(double));

int main(void)
{
    double source[SIZE];
    double target[SIZE];

    /*初始化源数组*/
    printf("Source array:");
    for (int i = 0; i < SIZE; i++)
    {
        if(i%10==0)
            putchar('\n');
        source[i] = i+1;  
        printf("%10f ", source[i]);
    }

    transform(source, target, SIZE, sin);
    printf("\nFunction1:");
    for (int i = 0; i < SIZE; i++)
    {   
        if(i%10==0)
            putchar('\n');
        printf("%10f ", target[i]);
    }
    putchar('\n');

    transform(source, target, SIZE, cos);
    printf("\nFunction2:");
    for (int i = 0; i < SIZE; i++)
    {   
        if(i%10==0)
            putchar('\n');
        printf("%10f ", target[i]);
    }
    putchar('\n');

    transform(source, target, SIZE, additself);
    printf("\nFunction3:");
    for (int i = 0; i < SIZE; i++)
    {   
        if(i%10==0)
            putchar('\n');
        printf("%10f ", target[i]);
    }
    putchar('\n');

    printf("\nFunction4:");
    for (int i = 0; i < SIZE; i++)
    {   
        if(i%10==0)
            putchar('\n');
        printf("%10f ", target[i]);
    }
    putchar('\n');
    return 0;
}
double additself(double val)
{
    return (val+=val);
}

double mutitself(double val)
{
    return (val*=val);
}

void transform(double * src, double * tar, int count, double(*pfun)(double))
{
    for (int i = 0; i < count; i++)
        tar[i] = (*pfun)(src[i]);    
}