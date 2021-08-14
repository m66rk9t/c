#include <stdio.h>
#include <math.h>
#define RAD (180 / (4 * atan(1)))
typedef struct cart{
    double x;
    double y;
} CART;
typedef struct polar{
    double r;
    double degree;
} POLAR;
CART polar_to_cart(const POLAR *);

int main(void)
{
    CART answer;//直角坐标结构变量
    POLAR input;//极坐标结构变量

    printf("Enter magnitude and angle in degrees: ");
    while (scanf("%lf %lf", &input.r, &input.degree) == 2)
    {
        answer = polar_to_cart(&input);//转换
        printf("polar coord: %g %f\n", input.r, input.degree);
        printf("rectangular coord: %g %g\n", answer.x, answer.y);
        printf("Enter magnitude and angle in degrees (q to quit): ");
    }
    puts("Bye");

    return 0;
}

/*将极坐标转换为直角坐标*/
CART polar_to_cart(const POLAR *ps)
{
    CART result;
    double rad = ps->degree / RAD;
    result.x = ps->r * cos(rad);
    result.y = ps->r * sin(rad);

    return result;
}