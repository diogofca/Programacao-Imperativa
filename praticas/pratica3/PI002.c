#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    char j = '#';
    for (int i = 0; i < n * n; i++)
    {
        printf("%c", j);
        if (j == '#')
        {
            j = '_';
        }
        else
        {
            j = '#';
        }
        if (i % n == n - 1)
        {
            printf("\n");
            if (n % 2 == 0)
            {

                if (j == '#')
                {
                    j = '_';
                }
                else
                {
                    j = '#';
                }
            }
        }
    }
    return 0;
}