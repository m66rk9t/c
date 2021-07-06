/*switch语句练习2*/
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    char input;
    int Lowers,Uppers,Others;
    Lowers=Uppers=Others=0;

    printf("Please enter a text for analysis(enter '#' to end):\n");
    while ((input=getchar())!='#')
    {
        if (isalpha(input))
        {
            switch (islower(input)?'L':'U')
            {
                case 'L':
                    Lowers++;
                    break;
                case 'U':
                    Uppers++;
                    break;
            }
        }
        else
            Others++;
    }
    printf("There are %d lower case letters, %d uppercase letters, and %d other characters.\n",Lowers,Uppers,Others);

    system("pause");
    return 0;
}