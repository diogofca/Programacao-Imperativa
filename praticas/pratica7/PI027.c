#include <stdio.h>
#include <stdbool.h>
#include <string.h>
void gen(int lala[], int a, int n)
{
    if (a == 0)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d", lala[i]);
        }
        printf("\n");
    }
    else
    {
        lala[n - a] = 0;
        gen(lala, a - 1, n);
        lala[n - a] = 1;
        gen(lala, a - 1, n);
    }
}

int power(int a)
{
    int toReturn = 1;
    for (int i = 0; i < a; i++)
    {
        toReturn *= 2;
    }
    return toReturn;
}

int main()
{
    int n;
    scanf("%d", &n);
    int lala[n];
    gen(lala, n, n);
    return 0;
}