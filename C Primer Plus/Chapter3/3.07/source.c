/*杯数与品脱、盎司、汤匙数、茶匙数单位换算*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    float pint;   //品脱
    int cups,ounce,soup_spoons,tea_spoons;    //杯数、品脱、盎司、汤匙数、茶匙数

    printf("Please enter the number of cups:\n");
    scanf("%d",&cups);
    pint=(float)cups*0.5;
    ounce=cups*8;
    soup_spoons=ounce*2;
    tea_spoons=soup_spoons*3;
    printf("%dcups = %.1fpint = %dounce = %dsoup spoons = %dtea spoons\n",cups,pint,ounce,soup_spoons,tea_spoons);

    system("pause");
    return 0;
}