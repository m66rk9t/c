/*花式打印姓名2*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
    char firstname[12],lastname[6];
    int count_first,count_last;

    printf("Please enter your lastname:\n");
    scanf("%s",&lastname);
    printf("Now enter your firstname:\n");
    scanf("%s",&firstname);
    count_first=strlen(firstname);
    count_last=strlen(lastname);
    printf("%s %s\n",lastname,firstname);
    printf("%*d %*d\n",count_last,count_last,count_first,count_first);
    printf("%s %s\n",lastname,firstname);
    printf("%-*d %-*d\n",count_last,count_last,count_first,count_first);

    system("pause");
    return 0;
}