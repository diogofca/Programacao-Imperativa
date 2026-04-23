#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int x;
    int y;
} POINT;

POINT findSymbol(int R, int C, char board[R][C], char toFind)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (board[i][j] == toFind)
            {
                POINT toReturn;
                toReturn.x = i;
                toReturn.y = j;
                return toReturn;
            }
        }
    }
    POINT toReturn = {0, 0};
    return toReturn;
}

bool thereIsOne(int R, int C, bool boardPossible[R][C], int i, int j)
{
    int a;
    int b;
    a = i - 1;
    b = j;
    if (0 <= a && a < R && 0 <= b && b < C && boardPossible[a][b])
    {
        return true;
    }

    a = i;
    b = j - 1;

    if (0 <= a && a < R && 0 <= b && b < C && boardPossible[a][b])
    {
        return true;
    }
    a = i;
    b = j + 1;

    if (0 <= a && a < R && 0 <= b && b < C && boardPossible[a][b])
    {
        return true;
    }

    a = i + 1;
    b = j;

    if (0 <= a && a < R && 0 <= b && b < C && boardPossible[a][b])
    {
        return true;
    }

    return false;
}

void paths(int R, int C, char board[R][C], bool boardPossible[R][C])
{
    POINT J = findSymbol(R, C, board, 'J');
    boardPossible[J.x][J.y] = true;
    int counter = 0;
    do
    {
        counter = 0;
        // printf("here");
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if ((board[i][j] == '.' || board[i][j] == 'P') && boardPossible[i][j] == false && thereIsOne(R, C, boardPossible, i, j))
                {

                    // printf("%c; %d %d\n", board[i][j], i, j);

                    boardPossible[i][j] = true;
                    counter += 1;
                }
            }
        }
        // printf("%d", counter);
    } while (counter != 0);
}

int main()
{
    // printf("here");
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int R, C;
        scanf("%d %d", &R, &C);
        // printf("here");
        char board[R][C];
        for (int i = 0; i < R; i++)
        {
            scanf("%s", &board[i][0]);
            // for (int j = 0; j < C; j++)
            //{
            // scanf("%c", &board[i][j]);
            //}
        }
        // printf("%c\n", board[0][0]);
        bool boardPossible[R][C];
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                boardPossible[i][j] = false;
            }
        }
        // printf("here");
        // board loadled
        paths(R, C, board, boardPossible);
        POINT P = findSymbol(R, C, board, 'P');
        if (boardPossible[P.x][P.y])
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}