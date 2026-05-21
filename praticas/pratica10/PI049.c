#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int count(int R, int C, char board[R][C], bool visited[R][C], int i, int j)
{
    // printf("%d %d ", i, j);
    if (i < 0 || i >= R || j < 0 || j >= C)
    {
        return 0;
    };
    if (visited[i][j] == true)
    {
        return 0;
    }
    if (board[i][j] == '.')
    {
        visited[i][j] = true;
        return 1 + count(R, C, board, visited, i + 1, j) + count(R, C, board, visited, i - 1, j) + count(R, C, board, visited, i, j + 1) + count(R, C, board, visited, i, j - 1);
    }
    visited[i][j] = true;

    return 0;
}

int count2(int R, int C, char board[R][C])
{
    bool visited[R][C];
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            visited[i][j] = false;
        }
    }
    int counter = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            int a = count(R, C, board, visited, i, j);

            if (a > 0)
            {
                // printf("%d", a);
                counter += 1;
            }
        }
    }
    return counter;
}

int main()
{
    int R, C;
    scanf("%d %d", &R, &C);
    char temp[R][C + 1];
    char board[R][C];
    for (int i = 0; i < R; i++)
    {
        scanf("%s", &temp[i][0]);
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            board[i][j] = temp[i][j];
        }
    }
    // assert(0 == 1);
    int N;
    char tm;
    printf("%d\n", count2(R, C, board));
    scanf("%d", &N);
    // printf("aqui");
    for (int t = 0; t < N; t++)
    {
        scanf("%c", &tm);
        char E;
        int U;
        scanf("%c %d", &E, &U);
        if (E == 'C')
        {
            for (int i = 0; i < R; i++)
            {
                board[i][U - 1] = '.';
            }
        }
        else if (E == 'R')
        {
            for (int j = 0; j < C; j++)
            {
                board[U - 1][j] = '.';
            }
        }
        printf("%d\n", count2(R, C, board));
    }
}