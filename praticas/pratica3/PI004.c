
#include <stdio.h>

int main()
{

    int n, f;
    scanf("%d %d", &n, &f);

    if (f == 0)
    {
        int w = 1 + 2 * (n - 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < w / 2 - i; j++)
            {
                printf("_");
            }

            for (int j = 0; j < 1 + 2 * (i); j++)
            {
                printf("#");
            }

            for (int j = 0; j < w / 2 - i; j++)
            {
                printf("_");
            }

            printf("\n");
        }
    }
    else if (f == 1)
    {

        int w = 1 + 2 * (n - 1);
        for (int i = 1; i <= w / 2; i++)
        {
            for (int j = 0; j < i; j++)
            {
                printf("#");
            }
            for (int j = 0; j < n - i; j++)
            {
                printf("_");
            }
            printf("\n");
        }

        for (int i = 0; i < n; i++)
        {
            printf("#");
        }
        printf("\n");
        for (int i = w / 2; i >= 1; i--)
        {
            for (int j = 0; j < i; j++)
            {
                printf("#");
            }
            for (int j = 0; j < n - i; j++)
            {
                printf("_");
            }
            printf("\n");
        }
    }
    return 0;
}