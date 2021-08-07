#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void bitopposite(char *);
void bitand(char *, char *);
void bitor (char *, char *);
void bitxor(char *, char *);

int main(int argc, char *argv[])
{
    /*检查参数*/
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s [string1] [string2]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /*使用四个按位运算符*/
    printf("~(%s):", argv[1]);
    bitopposite(argv[1]);
    printf("%s\n", argv[1]);
    printf("~(%s):", argv[2]);
    bitopposite(argv[2]);
    printf("%s\n", argv[2]);
    bitopposite(argv[1]);
    bitopposite(argv[2]);
    bitand(argv[1], argv[2]);
    bitor(argv[1], argv[2]);
    bitxor(argv[1], argv[2]);


    return 0;
}

void bitopposite(char *str)
{
    while (*str)
    {
        if (*str == '0')
            *str = '1';
        else
            *str = '0';
        str++;
    }
}

void bitand(char * str1, char * str2)
{
    char temp[sizeof(str1)];
    for (int i = 0; i < strlen(str1); i++)
    {
        if (str1[i] != str2[i])
            temp[i] = '0';
        else if (str1[i] == str2[i] && str1[i] == '0'&& str2[i] == '0')
            temp[i] = '0';
        else
            temp[i] = '1';
    }
    printf("%s & %s:%s\n", str1, str2, temp);
    
}

void bitor (char * str1, char * str2)
{
    char temp[sizeof(str1)];
    for (int i = 0; i < strlen(str1); i++)
    {
        if (str1[i] != str2[i])
            temp[i] = '1';
        else if (str1[i] == str2[i] && str1[i] == '1'&& str2[i] == '1')
            temp[i] = '1';
        else
            temp[i] = '0';
    }
    printf("%s | %s:%s\n", str1, str2, temp);
}

void bitxor(char * str1, char * str2)
{
    char temp[sizeof(str1)];
    for (int i = 0; i < strlen(str1); i++)
    {
        if (str1[i] != str2[i])
            temp[i] = '1';
        else
            temp[i] = '0';
    }
    printf("%s ^ %s:%s\n", str1, str2, temp);
}