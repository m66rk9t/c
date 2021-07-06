#include <stdio.h>
#include<string.h>
int main(int argc, char *argv[])
{
    for (int i = argc-1; i > 0; i--)
        printf("%s ",argv[i]);
    putchar('\n');
    return 0;
}