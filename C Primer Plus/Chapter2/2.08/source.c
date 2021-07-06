//搁这套娃呢？
#include<stdio.h>
#include<stdlib.h>
void one(void);
void two(void);
void three(void);
int main(void)
{
    printf("Starting now!\n");
    one();
    printf("done!\n");
    system("pause");
    return 0;
}

void one(void)
{
    printf("one\n");
    two();
}

void two(void)
{
    printf("two\n");
    three();
}

void three(void)
{
    printf("three\n");
}