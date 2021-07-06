#include<stdio.h>
#define SIZE 5
void getnchr(char * arr, int n);
int main(void)
{
    char arr[SIZE];
    printf("Please enter %d characters (include blank characters),\n"
            ,SIZE-1);
    puts("I will combine them into a string:");
    getnchr(arr,SIZE-1);
    puts("Your string is:");
    puts(arr);
    
    return 0;
}
void getnchr(char * arr, int n)
{
    for (int i = 0; i < n; i++)
        scanf("%c",arr++);
    *arr='\0';
    while (getchar()!='\n')
        continue;
}