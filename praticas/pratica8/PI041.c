#include <stdio.h>
#include <stdbool.h>

void dump(int board[], int n, int x, int s)
{
    board[x - 1] += s;
    for (int i = 1; i <= s - 1; i++)
    {
        int j1 = x + i;
        if (0 <= j1 - 1 && j1 - 1 < n)
        {
            board[j1 - 1] += s - i;
        }
        j1 = x - i;
        if (0 <= j1 - 1 && j1 - 1 < n)
        {
            board[j1 - 1] += s - i;
        }
    }
}

int main()
{

    int N, M;
    scanf("%d %d", &N, &M);
    int board[N];
    for (int i = 0; i < N; i++)
    {
        board[i] = 0;
    }
    for (int i = 0; i < M; i++)
    {
        int x, s;
        scanf("%d %d", &x, &s);
        dump(board, N, x, s);
    }
    for (int i = 0; i < N; i++)
    {
        if (i != N - 1)
        {
            printf("%d ", board[i]);
        }
        else
        {
            printf("%d\n", board[i]);
        }
    }

    return 0;
}