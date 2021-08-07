#include <stdio.h>
#include <string.h>
int bintoi(char *);

int main(void)
{
    char *pbin = "01001001"; //二进制字符串
    int value;//返回的十进制值

    value = bintoi(pbin);
    printf("%d", value);

    return 0;
}

int bintoi(char *binstr)
{
    int val = 0, temp;
    int out, in;
    int len = strlen(binstr);

    for (out = 0, temp = 1; out < len; out++, temp = 1)
    {
        if (binstr[out] == '1')//当该位为1就求幂
        {
            for (in = 0; in < len - out - 1; in++)
                temp *= 2;
            val += temp;
        }
    }

    return val;
}