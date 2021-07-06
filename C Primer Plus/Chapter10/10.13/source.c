#include<stdio.h>
void input(double (*arr)[5]);/*1.将用户输入储存到二维数组的函数原型*/
double avg1_arr(double *arr,int n);/*2.计算每组数据平均值的函数原型*/
double avg2_arr(double (*arr)[5]);/*3.计算所有数据平均值的函数原型*/
double max(double (*arr)[5]);/*4.找出数据中最大值的函数原型*/
/*5.打印结果*/
void show_result(double avg1,double avg2, double avg3, double avg4,double max);
int main(void)
{
    /*声明储存待处理数据的源数组*/
    double arr[3][5];
    /*声明储存每组数据平均值的一维数组*/
    double avg1[3];
    /*声明储存所有数据平均值的变量*/
    double avg2;
    /*声明储存所有数据中最大值的变量*/
    double max_element;

    /*函数调用*/
    input(arr);//1.将输入数据储存到二维数组中
    for (int i = 0; i < 3; i++)
        avg1[i]=avg1_arr(arr[i],5);//2.计算每组（5个）数据的平均值
    avg2=avg2_arr(arr);//3.计算所有数据的平均值
    max_element=max(arr);//4.找出这15个数据中的最大值
    show_result(avg1[0],avg1[1],avg1[2],avg2,max_element);//5.打印结果

    
    return 0;
}
/*函数定义*/
/*1.把用户输入的数据储存在3X5的数组中*/
void input(double (*arr)[5])
{
    for (int i = 0; i < 3; i++)
    {
        printf("Please enter 5 integers:\n");
        for (int j = 0; j < 5; j++)
            scanf("%lf",&arr[i][j]);
    }
}
/*2.计算每组（5个）数据的平均值*/
double avg1_arr(double *arr,int n)
{
    double total=0;
    for (int i = 0; i < n; i++)
        total+=arr[i];
    
    return total/(double)n;
}
/*3.计算所有数据的平均值*/
double avg2_arr(double (*arr)[5])
{
    double total=0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 5; j++)
            total+=arr[i][j];
    
    return total/(double)15;
}
/*4.找出这15个数据中的最大值*/
double max(double (*arr)[5])
{
    double max_element=**arr;
    for (int i = 0; i < 3; i++)
        for (int j = 1; j < 5; j++)
            if (arr[i][j]>max_element)
                max_element=arr[i][j];
    
    return max_element;
}
/*5.打印结果*/
void show_result(double avg1,double avg2, double avg3, double avg4,double max)
{
    printf("Average of arr[0]:%f\n",avg1);
    printf("Average of arr[1]:%f\n",avg2);
    printf("Average of arr[2]:%f\n",avg3);
    printf("Average of array arr:%f\n",avg4);
    printf("The max value of arr:%f\n",max);
}