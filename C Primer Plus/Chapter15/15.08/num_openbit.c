#include <stdio.h>
#include <limits.h>
#define MASK 1
int num_openbit(int);

int main(void)
{
    int input, count;
    printf("Please enter an integer(\'q\' to quit):");
    while (scanf("%d", &input) == 1)
    {
        count = num_openbit(input);
        printf("%d open bits in %d\n", count, input);
        printf("Now enter the next integer:");
    }
    puts("Done!");
    

    return 0;
}

int num_openbit(int val)
{
    int ret_val = 0;
    int bits = CHAR_BIT*sizeof(int);

    for (int i = 0; i < bits; i++, val>>=1)
        if ((val&MASK) == 1)
            ret_val++;    

    return ret_val;
}