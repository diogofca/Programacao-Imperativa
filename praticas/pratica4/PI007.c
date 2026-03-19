#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n];
    int b[m];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }

    int i = 0;
    int j = 0;

    for (int t = 0; t < m + n; t++)
    {
        if (a[i] < b[j])
        {
            printf("%d ", a[i]);
            i++;
            if (i == n)
            {
                for (int l = j; l < m - 1; l++)
                {
                    printf("%d ", b[l]);
                }
                printf("%d", b[m - 1]);
                break;
            }
        }
        else
        {
            printf("%d ", b[j]);
            j++;
            if (j == m)
            {
                for (int l = i; l < n - 1; l++)
                {
                    printf("%d ", a[l]);
                }
                printf("%d", a[n - 1]);
                break;
            }
        }
    }
    printf("\n");

    return 0;
}