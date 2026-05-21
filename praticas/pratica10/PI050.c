#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void putmax(int R, int C, char board[R][C], bool visited[R][C], int i, int j, int max)
{
    // printf("%d %d ", i, j);
    if (i < 0 || i >= R || j < 0 || j >= C)
    {
        return;
    };
    if (visited[i][j] == true)
    {
        return;
    }
    if (board[i][j] != '#')
    {
        visited[i][j] = true;
        board[i][j] = max + '0';
        putmax(R, C, board, visited, i + 1, j, max);
        putmax(R, C, board, visited, i - 1, j, max);
        putmax(R, C, board, visited, i, j + 1, max);
        putmax(R, C, board, visited, i, j - 1, max);
        return;
    }
    visited[i][j] = true;

    return;
}
void findmax(int R, int C, char board[R][C], bool visited[R][C], int i, int j, int *max, int powerpoints[11])
{
    // printf("%d %d ", i, j);
    if (i < 0 || i >= R || j < 0 || j >= C)
    {
        return;
    };
    if (visited[i][j] == true)
    {
        return;
    }
    if (board[i][j] != '#')
    {
        visited[i][j] = true;
        char elem = board[i][j];
        int elem_int;
        if (elem == '0')
        {
            elem_int = 0;
        }
        if (elem == '1')
        {
            elem_int = 1;
        }
        if (elem == '2')
        {
            elem_int = 2;
        }
        if (elem == '3')
        {
            elem_int = 3;
        }
        if (elem == '4')
        {
            elem_int = 4;
        }
        if (elem == '5')
        {
            elem_int = 5;
        }
        if (elem == '6')
        {
            elem_int = 6;
        }
        if (elem == '7')
        {
            elem_int = 7;
        }
        if (elem == '8')
        {
            elem_int = 8;
        }
        if (elem == '9')
        {
            elem_int = 9;
        }
        // printf("%d ", elem_int);
        if (powerpoints[*max] < powerpoints[elem_int])
        {
            *max = elem_int;
        }
        findmax(R, C, board, visited, i + 1, j, max, powerpoints);
        findmax(R, C, board, visited, i - 1, j, max, powerpoints);
        findmax(R, C, board, visited, i, j - 1, max, powerpoints);
        findmax(R, C, board, visited, i, j + 1, max, powerpoints);
    }
    visited[i][j] = true;

    return;
}
int main()
{
    int R, C;
    scanf("%d %d", &R, &C);
    char tmp_board[R][C + 1];
    char board[R][C];
    for (int i = 0; i < R; i++)
    {
        scanf("%s", &tmp_board[i][0]);
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            board[i][j] = tmp_board[i][j];
        }
    }
    int powers[11];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &powers[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        // printf("%d ", powers[i]);
    }
    // printf("\n");
    powers[10] = 0;

    bool visited1[R][C];
    bool visited2[R][C];
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            visited1[i][j] = false;
            visited2[i][j] = false;
        }
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            int max = 10;

            findmax(R, C, board, visited1, i, j, &max, powers);

            // printf("%d\n", max);
            if (max != 10)
            {
                putmax(R, C, board, visited2, i, j, max);
            }
        }
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}