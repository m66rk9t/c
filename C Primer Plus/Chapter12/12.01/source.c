#include <stdio.h>
void critic(int *ptr); /*函数原型*/
int main(void)
{
    int units;
    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
        critic(&units);
    printf("You must have looked it up!\n");
    return 0;
}
void critic(int *ptr) /*函数定义*/
{
    printf("No luck, my firend. Try again.\n");
    scanf("%d", ptr);
}