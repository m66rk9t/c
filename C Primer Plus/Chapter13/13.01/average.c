/*方案一：读取二进制文件，使用fread()读取数据*/
#include <stdio.h>
#include <stdlib.h> /*提供exit()原型*/
int main(int argc, char *argv[])
{
    float val = 0.0;   //输入值
    float total = 0.0; //总和
    float avg = 0.0;   //算术平均值
    int i;             //浮点值的数量

    /*以文件作为输入时所需要的变量*/
    FILE *fp;             //文件指针
    long pos;             //偏移量
    long bytes;           //文件字节数
    unsigned long counts; //文件中float值的数量

    /*检验参数*/
    if (argc < 2)
    { /*使用stdin作为输入*/
        printf("Enter some float values (enter 'q' to quit):\n");
        for (i = 0; scanf("%f", &val) == 1; i++)
            total += val; /*求和*/
    }
    else if (argc == 2)
    { /*使用文件作为输入*/
        /*以二进制读模式打开文件，打开失败则提示错误并异常结束程序*/
        if ((fp = fopen(argv[1], "rb")) == NULL)
        {
            fprintf(stderr, "Can't open file %s.\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        /*计算文件大小以及文件中float值的数量*/
        fseek(fp, 0L, SEEK_END);        //定位至文件结尾
        bytes = ftell(fp);              //计算文件字节数
        counts = bytes / sizeof(float); //计算文件中float值的数量
        /*读取浮点值并求和*/
        for (i = 0; i < counts; i++)
        {
            pos = (long)i * sizeof(float);     //设置偏移量
            fseek(fp, pos, SEEK_SET);          //定位
            fread(&val, sizeof(float), 1, fp); //读取并写入到指定位置
            total += val;                      //求和
        }
        fclose(fp); /*关闭文件*/
    }
    else
    { /*不满足命令行参数要求则提示错误并异常结束程序*/
        fprintf(stderr, "Only one parameters, please.\n");
        exit(EXIT_FAILURE);
    }

    /*计算并输出平均值*/
    avg = total / i;
    fprintf(stdout, "Average: %f\n", avg);

    return 0;
}

/*方案二，参考答案：使用文本读模式打开，使用fscanf()读取*/
// #include <stdio.h>
// #include <stdlib.h> //提供exit()原型

// int main(int argc, char *argv[])
// {
//     FILE *fp;         //FILE指针
//     float n;         //读取的值
//     float sum = 0.0; //总和
//     int ct = 0;       //计数

//     /*检查命令行参数*/
//     if (argc == 1)
//         fp = stdin; //将标准输入作为输入
//     else if (argc == 2)
//     { /*以二进制读模式打开文件，打开失败则提示错误并异常结束程序*/
//         if ((fp = fopen(argv[1], "r")) == NULL)
//         {
//             fprintf(stderr, "Can't open %s.\n", argv[1]);
//             exit(EXIT_FAILURE);
//         }
//     }
//     else
//     { /*不符合命令行参数要求，提示错误并异常结束程序*/
//         fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
//         exit(EXIT_FAILURE);
//     }

//     /*从输入中读取数据并求和*/
//     while (fscanf(fp, "%f", &n) == 1)
//     {
//         sum += n; //求和
//         ++ct;     //计数
//     }

//     /*计算平均值*/
//     if (ct > 0)
//         printf("Average if %d values = %f\n", sum, sum / n);
//     else
//         printf("No valid data.\n");

//     return 0;
// }