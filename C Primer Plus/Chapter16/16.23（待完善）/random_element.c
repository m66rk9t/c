#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
void random_element(const int *, int, int);
const int arr[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main(void)
{
    random_element(arr, SIZE, 5);

    return 0;
}

void random_element(const int * arr, int num, int count)
{
    time_t t;
    int index;
    srand((unsigned int) time(&t));
    for (int i = 0; i < count; i++)
    {
        index = rand()%10;
        printf("Index %d:%d\n", index, arr[index]);
    }
}