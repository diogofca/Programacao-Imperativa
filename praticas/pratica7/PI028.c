#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void genPermutations(int v[], int n, int a)
{
    if (a == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (i < n - 1)
            {
                printf("%d ", v[i]);
            }
            else
            {
                printf("%d", v[i]);
            }
        }
        printf("\n");
    }
    else
    {
        for (int i = n - a; i < n; i++)
        {
            swap(&v[i], &v[n - a]);
            for (int j = i; j >= n - a + 2; j--)
            {
                swap(&v[j], &v[j - 1]);
            }
            genPermutations(v, n, a - 1);
            for (int j = n - a + 1; j < i; j++)
            {
                swap(&v[j], &v[j + 1]);
            }
            swap(&v[i], &v[n - a]);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int b[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = i + 1;
    }
    genPermutations(b, n, n);

    return 0;
}