/* byebye.c -- 使用atexit()*/
#include <stdio.h>
#include <stdlib.h>
/*函数原型*/
void sign_off(void);
void too_bad(void);

int main(void)
{
    int n;
    
    atexit(sign_off);    /*注册sign_off()函数*/
    puts("Enter an integer:");
    if (scanf("%d",&n) != 1)
    {
        puts("That's no integer!");
        atexit(too_bad); /*注册too_bad()函数*/
        exit(EXIT_FAILURE);
    }
    printf("%d is %s.\n", n,  (n % 2 == 0)? "even" : "odd");
    
    return 0;
}

/*sign_off()函数定义*/
void sign_off(void)
{
    puts("Thus terminates another magnificent program from");
    puts("SeeSaw Software!");
}

/*too_bad函数定义*/
void too_bad(void)
{
    puts("SeeSaw Software extends its heartfelt condolences");
    puts("to you upon the failure of your program.");
}
