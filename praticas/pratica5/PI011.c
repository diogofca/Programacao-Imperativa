#include <stdio.h>

int checkCols(int n, char board[n][n], char p, int col)
{
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] != p)
        {
            return 0;
        }
    }
    return 1;
}

int checkRows(int n, char board[n][n], char p, int row)
{
    for (int i = 0; i < n; i++)
    {
        if (board[row][i] != p)
        {
            return 0;
        }
    }
    return 1;
}

int checkDiagonal(int n, char board[n][n], char p)
{
    for (int i = 0; i < n; i++)
    {
        // printf("%c\n", board[i][i]);
        if (board[i][i] != p)
        {
            return 0;
        }
    }
    return 1;
}
int checkAntiDiagonal(int n, char board[n][n], char p)
{
    for (int i = 0; i < n; i++)
    {
        if (board[i][n - 1 - i] != p)
        {
            return 0;
        }
    }
    return 1;
}

int thereIsEmptySpot(int n, char board[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '.')
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{

    int n;
    scanf("%d", &n);
    char board[n][n];
    // char temp[n];
    // for (int i = 0; i < n; i++)
    // {
    // scanf("%c", &temp[i]);
    // }
    for (int i = 0; i < n; i++)
    {
        scanf("%s", board[i]);
    }
    // printf("%c", board[0][0]);
    // for (int i = 0; i < n; i++)
    // {
    // for (int j = 0; j < n; j++)
    // {
    // printf("%c", board[i][j]);
    // }
    // }
    // printf("%c", board[1][1]);
    for (int i = 0; i < n; i++)
    {
        if (checkCols(n, board, 'X', i))
        {
            printf("Ganhou o X\n");
            return 0;
        }
        else if (checkCols(n, board, 'O', i))
        {
            printf("Ganhou o O\n");
            return 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (checkRows(n, board, 'X', i))
        {
            printf("Ganhou o X\n");
            return 0;
        }
        else if (checkRows(n, board, 'O', i))
        {
            printf("Ganhou o O\n");
            return 0;
        }
    }
    if (checkAntiDiagonal(n, board, 'X') == 1 || checkDiagonal(n, board, 'X') == 1)
    {
        printf("Ganhou o X\n");
        return 0;
    }

    if (checkAntiDiagonal(n, board, 'O') == 1 || checkDiagonal(n, board, 'O') == 1)
    {
        printf("Ganhou o O\n");
        return 0;
    }

    if (thereIsEmptySpot(n, board) == 1)
    {
        printf("Jogo incompleto\n");
    }
    else
    {
        printf("Empate\n");
    }

    return 0; // isto está bem
}