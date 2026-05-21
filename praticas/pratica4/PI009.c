#include <stdio.h>

int main()
{

    int n;

    scanf("%d", &n);
    int m = 2 * (n - 1) + 1;
    int primeira[m];
    for (int i = 0; i < m; i++)
    {
        primeira[i] = 0;
    }
    primeira[n - 1] = 1;
    int i = 1;
    while (i < n)
    {
        int temporaria[m];
        for (int j = 0; j < m; j++)
        {
            temporaria[j] = primeira[j];
        }
        for (int j = 0; j < m; j++)
        {
            if (j - 1 < 0)
            {
                primeira[j] = 0 + temporaria[j + 1];
            }
            else if (j + 1 >= m)
            {
                primeira[j] = temporaria[j - 1];
            }
            else
            {
                primeira[j] = temporaria[j - 1] + temporaria[j + 1];
            }
        }
        i++;
    }
    for (int i = 0; i < m; i++)
    {
        if (primeira[i] == 0)
        {
            printf(" ");
        }
        else
        {
            printf("%d", primeira[i]);
        }
    }
    printf("\n");
    return 0;
}