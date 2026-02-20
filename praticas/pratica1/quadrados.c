#include <stdio.h>

int main()
{

    int n = 5;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((j + i) % 2 == 0)
            {
                printf("#");
            }
            else
            {
                printf("_");
            }
        }
        printf("\n");
    }

    return 0;
}