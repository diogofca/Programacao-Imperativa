#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void printValor(int valor, int i, int M, int N)
{
    if (i == M + N - 1)
    {
        printf("%d\n", valor);
    }
    else
    {
        printf("%d ", valor);
    }
}
int main()
{
    int N;
    int M;
    scanf("%d", &N);
    int first[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &first[i]);
    }
    scanf("%d", &M);
    int second[M];
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &second[i]);
    }

    int valor_first = 0;
    int valor_second = 0;
    for (int i = 0; i < N + M; i++)
    {
        int to_Print;
        if (valor_first == N)
        {
            to_Print = second[valor_second];
            valor_second += 1;
            printValor(to_Print, i, M, N);
            continue;
        }
        else if (valor_second == M)
        {
            to_Print = first[valor_first];
            valor_first += 1;
            printValor(to_Print, i, M, N);
            continue;
        }
        else if (first[valor_first] <= second[valor_second])
        {
            to_Print = first[valor_first];
            valor_first += 1;
            printValor(to_Print, i, M, N);
            continue;
        }
        else
        {
            to_Print = second[valor_second];
            valor_second += 1;
            printValor(to_Print, i, M, N);
            continue;
        }
    }

    return 0;
}