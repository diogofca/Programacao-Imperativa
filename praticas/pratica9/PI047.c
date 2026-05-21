#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define FALSE 0
#define TRUE 1
#define SKIP_EOL                  \
    {                             \
        while (getchar() != '\n') \
            ;                     \
    }
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

bool areWordsEqual(char *a, char *b)
{
    if (worldlenght(a) != worldlenght(b))
    {
        return false;
    }
    int ll = worldlenght(a);
    for (int i = 0; i < ll; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int readAndCountWords()
{
    char ch = getchar();
    int nwords = 0;
    while (ch != '\n')
    {
        while ((ch = getchar()) != ' ' && ch != '\n')
            ;
        nwords++;
        while (ch != '\n' && (ch = getchar() == ' '))
            ;
    }
    return nwords;
}

int main()
{
    int ncases, nwords, npersons;
    int pos;

    scanf("%d", &ncases);
    SKIP_EOL; // skip end_of_line

    for (int c = 0; c < ncases; c++)
    {
        if (c != 0)
        {
            SKIP_EOL;
        }
        pos = 0;
        nwords = readAndCountWords();
        char carlos[] = "Carlos";
        // read persons
        scanf("%d", &npersons);
        // printf("%d\n", npersons);
        char persons[npersons][100];
        int int_persons[npersons];
        for (int i = 0; i < npersons; i++)
        {
            scanf("%s", &persons[i][0]);
            int_persons[i] = i;
            // printf("%s", persons[i]);
        }
        for (int i = 0; i < npersons - 1; i++)
        {
            int to_remove = (pos + (nwords % (npersons - i) - 1 + npersons - i) % (npersons - i)) % (npersons - i);
            pos = to_remove;
            // printf("%d", to_remove);
            for (int j = to_remove; j < npersons - 1; j++)
            {
                swap(&int_persons[j], &int_persons[j + 1]);
            }
        }
        if (areWordsEqual(persons[int_persons[0]], carlos))
        {
            printf("O Carlos nao se livrou\n");
        }
        else
        {
            printf("O Carlos livrou-se (coitado do %s!)\n", persons[int_persons[0]]);
        }
        // Do calculation
    }
}