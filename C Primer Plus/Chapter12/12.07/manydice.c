#include <stdio.h>
#include <stdlib.h>   /*提供srand()原型*/
#include <time.h>     /*提供time()原型*/
#include "diceroll.h" /*提供value声明和roll_n_dice原型*/

int main(void)
{
    int dice;  /*骰子数*/
    int sides; /*面数*/
    int sets;  /*投掷次数*/

    srand((unsigned int)time(0)); /*设置随机种子值*/
    printf("Enter the number of sets; enter q to stop: ");
    while (scanf("%d", &sets) == 1 && sets > 0)
    {
        printf("How many sides and how many dice? ");
        scanf("%d %d", &sides, &dice);

        value = roll_n_dice(dice, sides, sets);
        printf("Here are %d sets of %d %d-sides throws.\n",
               sets, dice, sides);
        for (int i = 0; i < sets; i++)
            printf("%d ", value[i]);
        printf("\nHow many sets? Enter q to stup: ");
    }
    free(value);/*释放内存*/
    printf("Done!\n");

    return 0;
}