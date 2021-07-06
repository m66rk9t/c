/*发出一声警报并打印文本*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int alert='\a';
    printf("%c",alert);
    printf("Startled by the sudden sound,Sally shouted,\n");
    printf("\"By the Great Pumpkin, what was that!\"\n");

    system("pause");
    return 0;
}