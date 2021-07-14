#include <stdio.h>
#include <stdlib.h> //提供exit()原型
#define ROW 20      //行
#define COL 30      //列
void revert(const char src[][COL], char tar[][COL + 1]);

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
        for (int c = 0; c < COL; c++)
        {
            src[r][c] = getc(fs);
            getc(fs); //丢弃空格字符
        }
    
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
        for (int j = 0; j < COL+1; j++)
            putc(pic[i][j], fp);

    /*收尾*/
    if (fclose(fs)!=0 && fclose(fp)!=0)
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