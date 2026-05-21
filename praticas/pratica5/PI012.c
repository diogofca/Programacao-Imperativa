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
int isWordHereCOLSRevsersed(int LINS, int COLS, char board[LINS][COLS], int l, int c, char *word)
{
    for (int i = 0; i < worldlenght(word); i++)
    {
        if (board[l - i][c] != word[i])
        {
            return 0;
        }
    }
    return 1;
}

int isWordHereLINS(int LINS, int COLS, char board[LINS][COLS], int l, int c, char *word)
{
    for (int i = 0; i < worldlenght(word); i++)
    {
        if (board[l][c + i] != word[i])
        {
            return 0;
        }
    }
    return 1;
}

int isWordHereLINSRevsersed(int LINS, int COLS, char board[LINS][COLS], int l, int c, char *word)
{
    for (int i = 0; i < worldlenght(word); i++)
    {
        if (board[l][c - i] != word[i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int vez = 1;
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
            for (int j = 0; j < COLS; j++)
            {
                // I have fixed a columns
                for (int i = LINS - 1; i >= worldlenght(palabrasToSearch[t]) - 1; i--)
                {
                    if (isWordHereCOLSRevsersed(LINS, COLS, sopa, i, j, palabrasToSearch[t]))
                    {
                        for (int l = 0; l < worldlenght(palabrasToSearch[t]); l++)
                        {
                            boardToKeep[i - l][j] = 1;
                        }
                    }
                }
            }

            // check lines
            for (int i = 0; i < LINS; i++)
            {
                for (int j = 0; j <= COLS - worldlenght(palabrasToSearch[t]); j++)
                {
                    if (isWordHereLINS(LINS, COLS, sopa, i, j, palabrasToSearch[t]))
                    {
                        for (int l = 0; l < worldlenght(palabrasToSearch[t]); l++)
                        {
                            boardToKeep[i][j + l] = 1;
                        }
                    }
                }
            }

            // check lines reversed

            for (int i = 0; i < LINS; i++)
            {
                for (int j = COLS - 1; j >= worldlenght(palabrasToSearch[t]) - 1; j--)
                {
                    if (isWordHereLINSRevsersed(LINS, COLS, sopa, i, j, palabrasToSearch[t]))
                    {
                        for (int l = 0; l < worldlenght(palabrasToSearch[t]); l++)
                        {
                            boardToKeep[i][j - l] = 1;
                        }
                    }
                }
            }
        }

        // printf("Input #%d\n", vez);
        printf("Input #%d\n", vez);
        vez++;
        for (int i = 0; i < LINS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (boardToKeep[i][j] == 1)
                {
                    printf("%c", sopa[i][j]);
                }
                else
                {
                    printf(".");
                }
            }
            printf("\n");
        }
    }

    return 0;
}