/*社交圈与邓巴数问题*/
#include<stdio.h>
#include<stdlib.h>
#define Dunbars_number 150
int main(void)
{
    int Friends,week;
    Friends=5;

    printf("At first, the number of friends:%d.\n",Friends);
    for(week=1;Friends<=Dunbars_number;week++)
    {
        Friends=(Friends-week)*2;
        printf("Week %d, the number of friends:%d.\n",week,Friends);
    }
    printf("Done!\n");

    system("pause");
    return 0;
}