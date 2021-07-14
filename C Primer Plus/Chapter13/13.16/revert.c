#include <stdio.h>
#include <stdlib.h> //提供exit()原型
#define ROW 20      //行
#define COL 30      //列
void revert(const char src[][COL], char tar[][COL + 1]);
void fun1(char *a, char b, char c);
void fun2(char *a, char b, char c, char d);
void fun3(char *a, char b, char c, char d, char e);
int fun4(char fst, char sec);

int main(void)
{
    FILE *fs, *fp;          //分别指向源文件和转换后的文件
    char src[ROW][COL];     //储存源文件字符
    char pic[ROW][COL + 1]; //储存转还后的字符

    /*打开源文件*/
    if ((fs = fopen("src", "r")) == NULL)
    {
        fprintf(stderr, "Can't open \"src\".\n");
        exit(EXIT_FAILURE);
    }

    /*读取源文件内容，将字符写入数组中*/
    for (int r = 0; r < ROW; r++)
    {
        for (int c = 0; c < COL; c++)
        {
            src[r][c] = getc(fs);
            getc(fs); //丢弃空格字符
        }
    }

    /*消除失真数字*/
    fun1(&src[0][0], src[1][0], src[0][1]);
    fun1(&src[ROW - 1][0], src[ROW - 2][0], src[ROW - 1][1]);
    fun1(&src[0][COL - 1], src[0][COL - 2], src[1][COL - 1]);
    fun1(&src[ROW - 1][COL - 1], src[ROW - 1][COL - 2], src[ROW - 2][COL - 1]);
    for (int r1 = 0, r2 = ROW - 1, c = 1; c < COL - 1; c++)
    {
        fun2(&src[r1][c], src[r1][c - 1], src[r1][c + 1], src[r1 + 1][c]);
        fun2(&src[r2][c], src[r2][c - 1], src[r2][c + 1], src[r2 - 1][c]);
    }
    for (int r = 1, c1 = 0, c2 = COL - 1; r < ROW - 1; r++)
    {
        fun2(&src[r][c1], src[r - 1][c1], src[r + 1][c1], src[r][c1 + 1]);
        fun2(&src[r][c2], src[r - 1][c2], src[r + 1][c2], src[r][c2 - 1]);
    }
    for (int r = 1; r < ROW-1; r++)
        for (int c = 1; c < COL-1; c++)
            fun3(&src[r][c],src[r-1][c],src[r+1][c],src[r][c-1],src[r][c+1]);

    /*转换*/
    revert(src, pic);

    /*打开目标文件*/
    if ((fp = fopen("pic", "w")) == NULL)
    {
        fprintf(stderr, "Can't open \"pic\".\n");
        exit(EXIT_FAILURE);
    }

    /*写入*/
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL + 1; j++)
            putc(pic[i][j], fp);

    /*收尾*/
    if (fclose(fs) != 0 && fclose(fp) != 0)
    {
        fprintf(stderr, "Error closing files.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

/*函数定义*/
void revert(const char src[][COL], char tar[][COL + 1])
{
    for (int r = 0; r < ROW; r++)
    {
        for (int c = 0; c < COL; c++)
        {
            switch (src[r][c])
            {
            case '0':
                tar[r][c] = ' ';
                break;
            case '1':
                tar[r][c] = '.';
                break;
            case '2':
                tar[r][c] = '\'';
                break;
            case '3':
                tar[r][c] = ':';
                break;
            case '4':
                tar[r][c] = '~';
                break;
            case '5':
                tar[r][c] = '*';
                break;
            case '6':
                tar[r][c] = '=';
                break;
            case '8':
                tar[r][c] = '%';
                break;
            case '9':
                tar[r][c] = '#';
                break;
            default:
                break;
            }
        }
        tar[r][COL] = '\n';
    }
}

void fun1(char *a, char b, char c)
{
    if (fun4(*a, b) > 1 && fun4(*a, c) > 1)
        *a = (((b - 48) + (c - 48)) / 2) + 48;
}

void fun2(char *a, char b, char c, char d)
{
    if (fun4(*a, b) > 1 && fun4(*a, c) > 1 && fun4(*a, d) > 1)
        *a = (((b - 48) + (c - 48) + (d - 48)) / 3) + 48;
}

void fun3(char *a, char b, char c, char d, char e)
{
    if (fun4(*a, b) > 1 && fun4(*a, c) > 1 && fun4(*a, d) > 1 && fun4(*a, e) > 1)
        *a = (((b - 48) + (c - 48) + (d - 48) + (e - 48)) / 4) + 48;
}

int fun4(char fst, char sec)
{
    int n;
    n = fst - sec;
    if (n < 0)
        return -n;
    return n;
}