#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 81
char *s_gets(char *str, int n);

int main(void)
{
    FILE * fp;
    char file[SLEN];
    long pos;
    char ch;

    /*输入文件名*/
    printf("Enter filenama:\n");
    s_gets(file, SLEN);

    /*尝试打开文件*/
    if ((fp = fopen(file, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s.\n", file);
        exit(EXIT_FAILURE);
    }
    /*是否为空文件*/
    else if (getc(fp) == EOF)
    {
        fprintf(stderr, "ERROR: Empyt file.\n");
        exit(EXIT_FAILURE);
    }
    /*定位至文件开始处*/
    else
        rewind(fp);
    
    /*输入文件位置*/
    printf("Please enter a position (negative or Non-numeric characters to quit):\n");
    while (scanf("%ld", &pos) == 1 && pos > 0)
    {
        fseek(fp, pos, SEEK_SET);//定位
        printf("Contents before the ""\\""n"":\n");
        while ((ch = getc(fp)) != EOF && ch != '\n')
            putc(ch, stdout);
        putchar('\n');
        printf("Next position:\n");
    }
    
    /*收尾*/
    fclose(fp);
    puts("Done!");

    return 0;
}

/*函数定义，读取字符串，保留输入中的换行符并处理输入中的多余字符*/
char *s_gets(char *str, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(str, n, stdin);
    if (ret_val)
    {
        find = strchr(str, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}