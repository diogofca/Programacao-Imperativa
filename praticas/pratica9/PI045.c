#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int input(char board[6][7], char playler, int position)
{
    for (int i = 5; i >= 0; i--)
    {
        if (board[i][position] == '.')
        {
            board[i][position] = playler;
            return i;
        }
    }
    return 200;
}

bool Bwins(char board[6][7], char playler)
{
    for (int j = 0; j < 7; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][j] == playler && board[i + 1][j] == playler && board[i + 2][j] == playler && board[i + 3][j] == playler)
            {
                // printf("vertical: %c %c\n", board[i][j], board[i + 1][j]);
                // printf("%d %d\n", i, j);
                return true;
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == playler && board[i][j + 1] == playler && board[i][j + 2] == playler && board[i][j + 3] == playler)
            {
                // printf("horizontal: %c %c\n", board[i][j], board[i + 1][j]);
                // printf("%d %d\n", i, j);
                return true;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == playler && board[i + 1][j + 1] == playler && board[i + 2][j + 2] == playler && board[i + 3][j + 3] == playler)
            {
                // printf("diagonal: %c %c\n", board[i][j], board[i + 1][j]);
                // printf("%d %d\n", i, j);
                return true;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 3; j < 7; j++)
        {
            if (board[i][j] == playler && board[i + 1][j - 1] == playler && board[i + 2][j - 2] == playler && board[i + 3][j - 3] == playler)
            {
                // printf("diagonal: %c %c\n", board[i][j], board[i + 1][j]);
                // printf("%d %d\n", i, j);
                return true;
            }
        }
    }

    return false;
}

bool forall(char board[6][7], int i2, int j)
{

    for (int k = 0; k < 7; k++)
    {
        int a = input(board, 'A', i2);
        if (a == 200)
        {

            continue;
        }
        int b = input(board, 'B', j);
        if (b == 200)
        {
            board[a][i2] = '.';
            continue;
        }
        int c = input(board, 'A', k);
        if (c == 200)
        {
            board[a][i2] = '.';
            board[b][j] = '.';
            continue;
        }
        bool lala = Bwins(board, 'A');
        if (lala && !Bwins(board, 'B'))
        {
            board[a][i2] = '.';
            board[b][j] = '.';
            board[c][k] = '.';
            // printf("%d %d %d\n", i2, j, k);
            return true;
            // lala nova submissão
            // for (int p = 0; p < 6; p++)
            // {
            // for (int q = 0; q < 7; q++)
            // {
            // printf("%c", board[p][q]);
            // }
            // printf("\n");
            // }
        }
        board[a][i2] = '.';
        board[b][j] = '.';
        board[c][k] = '.';
    }
    return false;
}

bool thereisone(char board[6][7], int i2)
{

    for (int j = 0; j < 7; j++)
    {
        int a = input(board, 'A', i2);
        if (a != 200)
        {
            int b = input(board, 'B', j);
            if (b != 200)
            {
                if (Bwins(board, 'B'))
                {
                    board[a][i2] = '.';
                    board[b][j] = '.';
                    return false;
                }
                else
                {

                    board[a][i2] = '.';
                    board[b][j] = '.';
                }
            }
        }
        if (forall(board, i2, j) == false)
        {

            return false;
        }
    }
    return true;
}

void myFunc()
{

    char tmp_board[6][8];
    for (int i3 = 0; i3 < 6; i3++)
    {
        scanf("%s", &tmp_board[i3][0]);
    }
    char board[6][7];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            board[i][j] = tmp_board[i][j];
        }
    }

    // for (int i3 = 0; i3 < 6; i3++)
    //{
    // for (int j = 0; j < 7; j++)
    //{
    // printf("%c", board[i3][j]);
    //}
    // printf("\n");
    //}

    // board is made here

    for (int i2 = 0; i2 < 7; i2++)
    {
        int a = input(board, 'A', i2);
        if (a != 200)
        {
            if (Bwins(board, 'A'))
            {

                printf("Yes\n");
                return;
            }
            else
            {
                board[a][i2] = '.';
            }
        }
        if (thereisone(board, i2))
        {
            // printf("%d", i2);
            printf("Yes\n");
            return;
        }
    }
    printf("No\n");
    return;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        myFunc();
    }
}
