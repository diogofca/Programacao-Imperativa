#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool checkIFItIsTheSame(int LINS, int COLS, char board[LINS][COLS], int LINS2, int COLS2, char newBoard[LINS2][COLS2], int l, int c)
{
    for (int i = 0; i < LINS2; i++)
    {
        for (int j = 0; j < COLS2; j++)
        {
            if (board[l + i][c + j] != newBoard[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool isLineEmpty(int LINS, int COLS, char board[LINS][COLS], int l)
{
    for (int j = 0; j < COLS; j++)
    {
        if (board[l][j] == '*')
        {
            return false;
        }
    }
    return true;
}
bool isColEmpty(int LINS, int COLS, char board[LINS][COLS], int c)
{
    for (int i = 0; i < LINS; i++)
    {
        if (board[i][c] == '*')
        {
            return false;
        }
    }
    return true;
}

int max(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int min(int a, int b)
{
    if (a <= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    int flag;
    scanf("%d", &flag);
    int LINS, COLS;
    scanf("%d %d", &LINS, &COLS);

    char board[LINS][COLS];
    for (int i = 0; i < LINS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = '.';
        }
    }

    bool penDown = false;
    int x = 0;
    int y = 0;
    char direction = 'E';
    while (true)
    {
        char instruction[5];
        scanf("%s", instruction);
        // printf("%s\n", instruction);
        if (instruction[0] == 'D')
        {
            penDown = true;
            board[x][y] = '*';
        }
        else if (instruction[0] == 'U')
        {
            penDown = false;
        }
        else if (instruction[0] == 'L')
        {
            if (direction == 'E')
            {
                direction = 'N';
            }
            else if (direction == 'S')
            {
                direction = 'E';
            }
            else if (direction == 'O')
            {
                direction = 'S';
            }
            else if (direction == 'N')
            {
                direction = 'O';
            }
        }
        else if (instruction[0] == 'R')
        {
            if (direction == 'E')
            {
                direction = 'S';
            }
            else if (direction == 'S')
            {
                direction = 'O';
            }
            else if (direction == 'O')
            {
                direction = 'N';
            }
            else if (direction == 'N')
            {
                direction = 'E';
            }
        }
        else if (instruction[0] == 'F')
        {
            // printf("Aqui\n");
            int numberOFSteps;
            scanf("%d", &numberOFSteps);
            // printf("%d\n", numberOFSteps);
            for (int i = 0; i < numberOFSteps; i++)
            {
                switch (direction)
                {
                case 'E':
                    y = min(y + 1, COLS - 1);
                    break;
                case 'N':
                    x = max(0, x - 1);
                    break;

                case 'O':
                    y = max(0, y - 1);
                    break;
                case 'S':
                    x = min(x + 1, LINS - 1);
                    break;
                default:
                    break;
                }
                // printf("%d %d\n", x, y);
                if (penDown)
                {
                    board[x][y] = '*';
                }
            }
        }
        else
        {
            break;
        }
    }

    if (flag == 0)
    {
        for (int i = 0; i < LINS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (j != COLS - 1)
                {
                    printf("%c ", board[i][j]);
                }
                else
                {
                    printf("%c", board[i][j]);
                }
            }
            printf("\n");
        }
    }

    if (flag == 1)
    {
        int counter = 0;
        int total = LINS * COLS;
        for (int i = 0; i < LINS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (board[i][j] == '*')
                {
                    counter += 1;
                }
            }
        }
        int linesEmpty = 0;
        for (int i = 0; i < LINS; i++)
        {
            if (isLineEmpty(LINS, COLS, board, i))
            {
                linesEmpty += 1;
            }
        }
        int colsEmpty = 0;
        for (int j = 0; j < COLS; j++)
        {
            if (isColEmpty(LINS, COLS, board, j))
            {
                colsEmpty += 1;
            }
        }

        printf("%d %d %d\n", counter * 100 / total, linesEmpty, colsEmpty);
    }
    if (flag == 2)
    {
        int LINS2, COLS2;
        scanf("%d %d", &LINS2, &COLS2);
        // printf("%d %d\n", LINS2, COLS2);
        char newBoard[LINS2][COLS2];
        for (int i = 0; i < LINS2; i++)
        {
            for (int j = 0; j < COLS2; j++)
            {
                scanf("%s", &newBoard[i][j]);
            }
        }
        // for (int i = 0; i < LINS2; i++)
        // {
        // for (int j = 0; j < COLS2; j++)
        // {
        // printf("%c", newBoard[i][j]);
        // }
        // printf("\n");
        // }

        for (int i = 0; i <= LINS - LINS2 + 1; i++)
        {
            for (int j = 0; j <= COLS - COLS2 + 1; j++)
            {
                if (checkIFItIsTheSame(LINS, COLS, board, LINS2, COLS2, newBoard, i, j))
                {
                    printf("Sim\n");
                    return 0;
                }
            }
        }
        printf("Nao\n");
    }

    return 0;
}