/*奇数偶数*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int input,num_even,num_odd;
    double sum_even,sum_odd;
    num_even=num_odd=0;sum_even=sum_odd=0.0;
    printf("Please enter a set of numbers(enter 0 to end):\n");
    while (1)
    {
        scanf("%d",&input);
        if (input==0)
            break;
        else if(input%2==0)  
        {
            num_even++;
            sum_even+=input;
        }
        else
        {
            num_odd++;
            sum_odd+=input;
        }
    }
    printf("Count of odd numbers:%d\nAverage of odd numbers:%f\n",num_odd,sum_odd/num_odd);
    printf("Count of even numbers:%d\nAverage of even numbers:%f\n",num_even,sum_even/num_even);

    system("pause");
    return 0;
}