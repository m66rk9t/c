#include <stdio.h>
#define MASK 1
int isopen(int, int);

int main(void)
{
    int input, position;
    printf("Please enter an integer(\'q\' to quit):");
    while (scanf("%d", &input) == 1)
    {
        printf("Please enter an position(0~7):");
        scanf("%d", &position);
        printf("The bit value on position %d is %d.\n", position, isopen(input, position));
        printf("Now enter the next integer:");
    }
    puts("Done!");
}
int isopen(int val, int pos)
{
    val >>= pos;
    if ((val&MASK) == 1)
        return 1;

    return 0;
}