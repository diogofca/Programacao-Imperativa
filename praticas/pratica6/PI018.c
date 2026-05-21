#include <stdio.h>
#include <stdbool.h>

int wordlenght(char *word)
{
    int i = 0;
    while (*word != '\0')
    {
        word += 1;
        i++;
    }
    return i;
}

int main()
{
    int MAX = 1000000;
    char palavra[MAX];
    fgets(palavra, MAX, stdin);
    int ww1 = wordlenght(palavra) - 1;
    palavra[ww1] = '\0';
    char newPalavra[MAX];
    int j = 0;
    for (int i = 0; i < ww1; i++)
    {
        if (('a' <= palavra[i] && palavra[i] <= 'z'))

        {
            newPalavra[j] = palavra[i];
            j++;
        }
        else
        {
            continue;
        }
    }
    newPalavra[j] = '\0';
    int counter = 0;
    // wtf
    // helo there
    // printf("%s", newPalavra);
    int ww = wordlenght(newPalavra);
    for (int i = 0; i < ww / 2; i++)
    {
        if (newPalavra[i] != newPalavra[ww - i - 1])
        {
            counter += 1;
        }
    }
    if (counter == 0)
    {
        printf("Inspection passed\n");
    }
    else
    {
        printf("Oh boy, this needs a fix. You have to change at least %d characters\n", counter);
    }
    // lalala
    return 0;
}