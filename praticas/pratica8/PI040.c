#include <stdio.h>
#include <stdbool.h>

bool isOneThere(char *board, int n)
{
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (board[i] == '#')
        {
            counter += 1;
        }
    }
    if (counter == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    int N;
    scanf("%d", &N);
    char board[N];
    for (int i = 0; i < N; i++)
    {
        board[i] = '#';
    }

    bool isLast = false;
    int i = 0;
    while (isOneThere(board, N) == false)
    {
        if (board[i] == '#')
        {
            if (isLast)
            {
                board[i] = '.';
            }
            isLast = !isLast;
        }
        i = (i + 1) % N;
    }
    for (int i = 0; i < N; i++)
    {
        if (board[i] == '#')
        {
            printf("%d\n", i + 1);
            break;
        }
    }
    return 0;
}