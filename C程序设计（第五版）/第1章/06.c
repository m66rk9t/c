#include <stdio.h>

int main(void)
{
    int a, b, c, max;

    max = 0;
    printf("Please enter three integer numbers:\n");
    scanf("%d %d %d", &a, &b, &c);
    if (a > b)
        max = a;
    else
        max = b;
    if (max < c)
        max = c;
    printf("max value is %d.\n", max);

    return 0;
}