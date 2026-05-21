#include <stdio.h>

int numberOfAlive(int LINS, int COLS, char board[LINS][COLS], int l, int c)
{
    int counter = 0;
    int places[8][2] = {
        {l + 1, c + 1},
        {l + 1, c},
        {l + 1, c - 1},
        {l, c + 1},
        {l, c - 1},
        {l - 1, c + 1},
        {l - 1, c},
        {l - 1, c - 1},
    };

    for (int i = 0; i < 8; i++)
    {
        int a = places[i][0];
        int b = places[i][1];
        if (a >= 0 && a <= LINS - 1 && b >= 0 && b <= COLS - 1)
        {
            if (board[a][b] == 'O')
            {
                counter += 1;
            }
        }
    }
    return counter;
}

int main()
{

    int LINS, COLS, I;
    scanf("%d %d %d", &LINS, &COLS, &I);
    char board[LINS][COLS];
    for (int i = 0; i < LINS; i++)
    {
        scanf("%s", board[i]);
    }
    for (int t = 0; t < I; t++)
    {
        char newBoard[LINS][COLS];
        for (int i = 0; i < LINS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                newBoard[i][j] = '.';
            }
        }
        // tentar de novo
        for (int i = 0; i < LINS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                int nn = numberOfAlive(LINS, COLS, board, i, j);
                if (nn <= 1 && board[i][j] == 'O')
                {
                    newBoard[i][j] = '.';
                }
                else if (nn >= 4 && board[i][j] == 'O')
                {
                    newBoard[i][j] = '.';
                }
                else if (board[i][j] == 'O')
                {
                    newBoard[i][j] = 'O';
                }
                else if (nn == 3)
                {
                    newBoard[i][j] = 'O';
                }
            }
        }

        for (int i = 0; i < LINS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                board[i][j] = newBoard[i][j];
            }
        }
    }
    for (int i = 0; i < LINS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    // second try

    return 0;
}