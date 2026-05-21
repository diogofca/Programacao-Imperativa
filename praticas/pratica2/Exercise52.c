#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int i = 2;
    int d = n;
    while (d != 1)
    {
        if (d % i == 0)
        {
            printf("divides %d\n", i);
            d = d / i;
        }
        else
        {
            i++;
        }
    }

    return 0;
}

int isPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}