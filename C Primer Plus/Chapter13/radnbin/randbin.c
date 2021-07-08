/* randbin.c -- 用二进制I/O进行随即访问 */
#include <stdio.h>
#include <stdlib.h> /*提供exit()原型*/
#define ARSIZE 1000 /*数组大小*/

int main(void)
{
    double numbers[ARSIZE];           /*储存double类型数值*/
    double value = 0.0;               /*储存读取的double类型数值*/
    const char *file = "numbers.dat"; /*储存double类型数值的文件*/
    int i;                            /*索引*/
    long pos;                         /*偏移量*/
    FILE *iofile;                     /*FILE指针*/

    /*使用double类型数值初始化数组*/
    for (i = 0; i < ARSIZE; i++)
        numbers[i] = 100.0 * i + 1.0 / (i + 1);

    /*以二进制写模式打开文件，打开失败则提示错误并异常结束程序*/
    if ((iofile = fopen(file, "wb")) == NULL)
    {
        fprintf(stderr, "Could not open %s for output.\n", file);
        exit(EXIT_FAILURE);
    }

    /*以二进制格式把数组中的数值写入文件*/
    fwrite(numbers, sizeof(double), ARSIZE, iofile);
    fclose(iofile); /*关闭文件流*/

    /*以二进制读模式打开文件，打开失败则提示错误并异常结束程序*/
    if ((iofile = fopen(file, "rb")) == NULL)
    {
        fprintf(stderr, "Could not open %s for random access.\n", file);
        exit(EXIT_FAILURE);
    }

    /*从文件中读取选定的内容*/
    printf("Enter an index inthe range 0-%d.\n", ARSIZE - 1);
    while (scanf("%d", &i) == 1 && i >= 0 && i < ARSIZE)
    {
        pos = (long)i * sizeof(double); /*计算偏移量*/
        fseek(iofile, pos, SEEK_SET);   /*定位*/
        fread(&value, sizeof(double), 1, iofile);/*将当前文件位置上的数值拷贝到指针指定位置*/
        printf("The value there is %f.\n", value);
        printf("Next index (out of range to quit):\n");
    }

    /*收尾，关闭文件流*/
    fclose(iofile);
    puts("Done!");

    return 0;
}