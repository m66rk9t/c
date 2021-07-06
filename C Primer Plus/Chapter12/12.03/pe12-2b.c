//pe12-2b.c
//与pe12-2a.c一起编译
#include <stdio.h>
#include "pe12-2a.h" /*定义的头文件*/
int main(void)
{
    int mode, status;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        get_show(mode);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
        /*判断用户输入是否正确*/
        if (mode > 1)
        {
            printf("Invalid mode specified. Mode %d(%s) used.\n",
                   status, status ? "US" : "metric");
            mode = status;
        }
        else
            status = mode;
    }
    printf("Done!\n");

    return 0;
}