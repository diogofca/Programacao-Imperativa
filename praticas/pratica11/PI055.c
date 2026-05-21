#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int count(int n, int m, char board[n][m], bool visited[n][m], int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return 0;
    }
    if (visited[i][j] == true)
    {
        return 0;
    }
    if (board[i][j] == '#')
    {
        visited[i][j] = true;
        return 0;
    }
    else
    {
        visited[i][j] = true;
        return 1 + count(n, m, board, visited, i + 1, j) + count(n, m, board, visited, i - 1, j) +
               count(n, m, board, visited, i, j + 1) + count(n, m, board, visited, i, j - 1);
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    char tmp_board[n][m + 1];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &tmp_board[i][0]);
    }
    char board[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            board[i][j] = tmp_board[i][j];
        }
    }

    bool visited[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (count(n, m, board, visited, i, j) > 0)
            {
                counter++;
            }
        }
    }
    printf("%d\n", counter);
}