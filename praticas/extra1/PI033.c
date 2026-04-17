#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void printprint(int a)
{
    // primeira
    for (int i = 0; i < a; i++)
    {
        printf("#");
    }
    printf("\n");

    // meio cima
    for (int i = 0; i < (a - 2) / 2; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf(".");
        }
        printf("#");
        for (int j = 0; j < a - 2 * (i + 1) - 2; j++)
        {
            printf(".");
        }
        printf("#");
        for (int j = 0; j < i + 1; j++)
        {
            printf(".");
        }
        printf("\n");
    }

    // meio
    for (int i = 0; i < a / 2; i++)
    {
        printf(".");
    }
    printf("#");
    for (int i = 0; i < a / 2; i++)
    {
        printf(".");
    }
    printf("\n");

    // meio baixo

    for (int i = (a - 2) / 2 - 1; i >= 0; i--)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf(".");
        }
        printf("#");
        for (int j = 0; j < a - 2 * (i + 1) - 2; j++)
        {
            printf(".");
        }
        printf("#");
        for (int j = 0; j < i + 1; j++)
        {
            printf(".");
        }
        printf("\n");
    }

    // ultima
    for (int i = 0; i < a; i++)
    {
        printf("#");
    }
    printf("\n");
}

int main()
{
    int N;
    scanf("%d", &N);
    int numbers[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0; i < N; i++)
    {
        printprint(numbers[i]);
    }
    return 0;
}