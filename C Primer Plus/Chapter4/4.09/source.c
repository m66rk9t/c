/*花式打印姓名*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
    char name[20];
    int weidth;

    printf("Please enter your name:\n");
    scanf("%s",name);
    weidth=strlen(name)+3;

    printf("%s\n",name);
    printf("\"%-20s\"\n",name);
    printf("\"%20s\"\n",name);
    printf("%*s\n",weidth,name);

    system("pause");
    return 0;
}