#include <stdio.h>

int main()
{

    int n = 20;
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum += i;
    }
    printf("Soma = %d\n", sum);
    return 0;
}