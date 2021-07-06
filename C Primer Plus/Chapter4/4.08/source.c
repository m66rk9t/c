/*以“名,姓”格式输出姓名*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    char xing[6];
    char ming[15];
    printf("Please enter you name:\n");
    scanf("%s %s",xing,ming);
    printf("%s,%s\n",ming,xing);

    system("pause");
    return 0;
}