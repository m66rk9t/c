/*switch语句练习1*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    char input;

    printf("Please enter an letter of the alphabet, and I will give an animal name.\n");
    printf("The letters entered are not case sensitive, enter '#' to quit.\n");
    while((input=getchar())!='#')
    {
        if(input=='\n') /*用户输入Enter键后开始新的迭代*/
            continue;
        switch (input)
        {
            case 'a':
            case 'A':
                printf("Argali, a wild sheep of Asia.\n");
                break;
            case 'b':
            case 'B':
                printf("Babirusa, a wild pig of Malay.\n");
                break;
            case 'c':
            case 'C':
                printf("Coati, racoonlike mammal.\n");
                break;
            case 'd':
            case 'D':
                printf("Desman, aquatic, molelike critter.\n");
                break;
            case 'e':
            case 'E':
                printf("Echidna, the spiny anteater.\n");
                break;
            case 'f':
            case 'F':
                printf("Fisher, brownish marten.\n");
                break;
            default:
                printf("Wrong input!\n");
        }
        while (getchar()!='\n') //跳过输入的多余字符
            continue;
        /*getchar()函数返回值是读取的字符，该循环只是读取并丢弃多余的字符，返回值并没有赋给input*/
        printf("Now enter another letter(enter '#' to quit):\n");
    }
    printf("Done!\n");

    system("pause");
    return 0;
}