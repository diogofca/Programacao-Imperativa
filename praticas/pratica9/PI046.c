#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int counter(int R, int C, char board[R][C], bool visited[R][C], int i, int j)
{
    if (i < 0 || i >= R || j < 0 || j >= C)
    {
        return 0;
    }
    else if (visited[i][j] == true)
    {
        return 0;
    }
    else if (board[i][j] == '#')
    {
        visited[i][j] = true;
        return 1 + counter(R, C, board, visited, i + 1, j) + counter(R, C, board, visited, i - 1, j) + counter(R, C, board, visited, i, j + 1) + counter(R, C, board, visited, i, j - 1) +
               counter(R, C, board, visited, i + 1, j + 1) + counter(R, C, board, visited, i - 1, j + 1) + counter(R, C, board, visited, i + 1, j - 1) + counter(R, C, board, visited, i - 1, j - 1);
    }
    else
    {
        return 0;
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    for (int t = 0; t < N; t++)
    {
        int R, C;
        scanf("%d %d", &R, &C);
        char tmp_board[R][C + 1];
        for (int i = 0; i < R; i++)
        {
            scanf("%s", tmp_board[i]);
        }
        char board[R][C];
        bool visited[R][C];
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                board[i][j] = tmp_board[i][j];
                visited[i][j] = false;
            }
        }
        int max = 0;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (visited[i][j] == false)
                {
                    int a = counter(R, C, board, visited, i, j);
                    if (a > max)
                    {
                        max = a;
                    }
                }
            }
        }
        printf("%d\n", max);
    }

    return 0;
}