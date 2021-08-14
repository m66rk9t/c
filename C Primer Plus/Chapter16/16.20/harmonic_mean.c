#include <stdio.h>
#define MEAN(X, Y) (2.0 * (X) *(Y) / ((X) + (Y))) //类函数宏

int main(void)
{
    double mean = MEAN(2, 4);
    printf("The harmonic mean of 2 and 4 is %f\n", mean);

    return 0;
}