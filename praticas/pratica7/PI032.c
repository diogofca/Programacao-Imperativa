#include <stdio.h>
#include <stdbool.h>
#include <string.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void genPermutations(int n, int costs[n][n], int v[n], int a, int *min)
{
    if (a == 0)
    {
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            sum += costs[v[i]][v[i + 1]];
        }
        if (sum < *min)
        {
            *min = sum;
        }
    }
    else
    {
        for (int i = n - a; i < n; i++)
        {
            swap(&v[i], &v[n - a]);
            genPermutations(n, costs, v, a - 1, min);
            swap(&v[i], &v[n - a]);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int costs[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &costs[i][j]);
        }
    }

    int min = 0;
    for (int i = 0; i < n - 1; i++)
    {
        min += costs[i][i + 1];
    }
    int v[n];
    for (int i = 0; i < n; i++)
    {
        v[i] = i;
    }
    genPermutations(n, costs, v, n, &min);
    printf("%d\n", min);

    return 0;
}