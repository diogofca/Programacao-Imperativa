#include <stdio.h>

int main()
{

    int n = 20;
    printf("Even numbers from 1 to %d: ", n);
    printf("1");
    for (int i = 3; i < n; i += 2)
    {
        printf(",%d", i);
    }
    printf("\n");
    return 0;
}