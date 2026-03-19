#include <stdio.h>
int worldlenght(char *word)
{
    int len = 0;
    while (*word != '\0')
    {
        len += 1;
        word += 1;
    }
    return len;
}

int isWordHereCOLS(int LINS, int COLS, char board[LINS][COLS], int l, int c, char *word)
{
    for (int i = 0; i < worldlenght(word); i++)
    {
        if (board[l + i][c] != word[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    while (1)
    {
        int LINS, COLS;

        scanf("%d", &LINS);
        scanf("%d", &COLS);

        if (LINS == 0 && COLS == 0)
        {
            // printf("Aqui\n");
            return 0;
        }
        char sopa[LINS][COLS];
        for (int i = 0; i < LINS; i++)
        {
            scanf("%s", sopa[i]);
        }
        int palavras;
        scanf("%d", &palavras);
        char palabrasToSearch[palavras][51];
        for (int i = 0; i < palavras; i++)
        {
            scanf("%s", palabrasToSearch[i]);
        }
        // for (int i = 0; i < palavras; i++)
        // {
        // printf("%s\n", palabrasToSearch[i]);
        // }
        // for (int i = 0; i < palavras; i++)
        // {
        // printf("%d\n", worldlenght(palabrasToSearch[i]));
        // }

        int boardToKeep[LINS][COLS];
        for (int i = 0; i < LINS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                boardToKeep[i][j] = 0;
            }
        }

        for (int t = 0; t < palavras; t++)
        {
            // check cols
            for (int j = 0; j < COLS; j++)
            {
                // I have fixed one column
                for (int i = 0; i <= LINS - worldlenght(palabrasToSearch[t]); i++)
                {
                    // is word here??
                    if (isWordHereCOLS(LINS, COLS, sopa, i, j, palabrasToSearch[t]))
                    {
                        for (int l = 0; l < worldlenght(palabrasToSearch[t]); l++)
                        {
                            boardToKeep[i + l][j] = 1;
                        }
                    }
                }
            }

            // check cols reversed

            // check lines

            // check lines reversed
        }

        // printf("Input #%d\n", vez);
        printf("lala\n");
        for (int i = 0; i < LINS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (boardToKeep[i][j] == 1)
                {
                    printf("%c", sopa[i][j]);
                }
            }
            printf("\n");
        }
    }

    return 0;
}