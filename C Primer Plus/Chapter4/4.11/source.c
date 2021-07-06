/*求下载文件的时间*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    float d_speed,f_size,d_time;
    
    printf("Please enter the download speed and file size:\n");
    scanf("%f %f",&d_speed,&f_size);
    d_time=d_speed/(f_size*8.0);
    printf("At %.2f megabits per seconds, a file of %.2f megabytes\n",d_speed,f_size);
    printf("downloads in %.2f seconds\n",d_time);

    system("pause");
    return 0;
}