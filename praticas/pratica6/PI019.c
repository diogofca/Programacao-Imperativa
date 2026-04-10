#include <stdio.h>
#include <stdbool.h>

int main()
{
    int N1, M1, M2, N2;
    scanf("%d", &M1);
    scanf("%d", &N1);
    int matrix1[M1][N1];
    for (int i = 0; i < M1; i++)
    {
        for (int j = 0; j < N1; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }
    scanf("%d", &M2);
    scanf("%d", &N2);
    int matrix2[M2][N2];
    for (int i = 0; i < M2; i++)
    {
        for (int j = 0; j < N2; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }

    for (int i = 0; i < M1; i++)
    {
        for (int j = 0; j < N2; j++)
        {
            int sum = 0;
            for (int t = 0; t < N1; t++)
            {
                sum += matrix1[i][t] * matrix2[t][j];
            }
            if (j < N2 - 1)
            {
                printf("%d ", sum);
            }
            else
            {
                printf("%d", sum);
            }
        }
        printf("\n");
    }
}