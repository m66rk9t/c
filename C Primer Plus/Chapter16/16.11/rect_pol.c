/*rect_pol.c -- 把直角坐标转换成极坐标*/
#include <stdio.h>
#include <math.h>//提供sqrt()、atan()、atan2()原型

#define RAD_TO_DEG (180/(4 * atan(1)))  //类对象宏，1弧度的角度值

typedef struct polar_v {
    double magnitude;
    double angle;
} Polar_V;//结构声明，Polar_V作别名

typedef struct rect_v {
    double x;
    double y;
} Rect_V;//结构声明，Rect_V作别名

Polar_V rect_to_polar(Rect_V);//直角坐标转换成及坐标的函数原型

int main(void)
{
    /*声明结构变量*/
    Rect_V input;
    Polar_V result;
    
    /*输入直角坐标的两个值*/
    puts("Enter x and y coordinates; enter q to quit:");
    while (scanf("%lf %lf", &input.x, &input.y) == 2)
    {
        result = rect_to_polar(input);//转换
        printf("magnitude = %0.2f, angle = %0.2f\n",
               result.magnitude, result.angle);
    }
    puts("Bye.");
    
    return 0;
}

/*直角坐标转换成及坐标的函数定义*/
Polar_V rect_to_polar(Rect_V rv)
{
    Polar_V pv;//声明一个struct polar_v变量
    
    pv.magnitude = sqrt(rv.x * rv.x + rv.y * rv.y);//计算长度
    if (pv.magnitude == 0)
        pv.angle = 0.0;
    else
        pv.angle = RAD_TO_DEG * atan2(rv.y, rv.x);//计算角度
    
    return pv;//返回一个结构
}
