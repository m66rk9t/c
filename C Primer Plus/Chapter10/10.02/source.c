#include<stdio.h>
void copy_arr(double arr[],double src[],int n);         /*第1份拷贝函数的原型*/
void copy_ptr(double *arr,double *src,int n);           /*第2份拷贝函数的原型*/
void copy_ptrs(double *arr, double *start, double* end);/*第3份拷贝函数的原型*/
void show_arr(double *start,double *end);               /*显示数组内容的函数原型*/
int main(void)
{
    /*声明并初始化源数组*/
    double source[5]={1.1,2.2,3.3,4.4,5.5};

    /*声明目标数组*/
    double target1[5];
    double target2[5];
    double target3[5];

    /*调用拷贝数组的函数*/
    copy_arr(target1,source,5);
    copy_ptr(target2,source,5);
    copy_ptrs(target3,source,source+5);

    /*显示拷贝后的数组内容*/
    printf("Array source:\n");
    show_arr(source,source+5);
    printf("Array target1:\n");
    show_arr(target1,target1+5);
    printf("Array target2:\n");
    show_arr(target2,target2+5);
    printf("Array target3:\n");
    show_arr(target3,target3+5);

    return 0;
}

/*函数定义*/
/*使用带数组表示法的函数进行第1份拷贝*/
void copy_arr(double arr[],double src[],int n)
{
    for (int i = 0; i < n; i++)
        arr[i]=src[i];
}
/*使用带指针表示法和指针递增的函数进行第2份拷贝*/
void copy_ptr(double *arr,double *src,int n)
{
    for (int i = 0; i < n; arr++,src++)
        *arr=*src;
}
/*使用指向源数组最后一个元素后面的元素的指针进行第3份拷贝*/
void copy_ptrs(double *arr, double *start, double *end)
{
    while (start<end)
        *(arr++)=*(start++);
}
/*使用指针表示法显示数组的内容*/
void show_arr(double *start,double *end)
{
    while (start<end)
        printf("%3.1f ",*(start++));
    printf("\n");
}