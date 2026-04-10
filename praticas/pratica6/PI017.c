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

bool matchy(char *s, char *string, int i)
{

    for (int j = 0; j < wordlenght(s); j++)
    {
        if (string[i + j] != s[j])
        {
            return false;
        }
    }
    return true;
}

int findOccurrence(char *s, char *string)
{
    for (int i = 0; i < wordlenght(string); i++)
    {
        if (matchy(s, string, i))
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    char string[10000];
    fgets(string, 10000, stdin);
    string[wordlenght(string) - 1] = '\0';

    // printf("%s", string);
    int N;
    scanf("%d", &N);
    getchar();
    // printf("%s", string);

    for (int i = 0; i < N; i++)
    {
        // printf("ciclo: %d\n", i);
        char s[100000];

        fgets(s, 10000, stdin);
        char t[100000];
        fgets(t, 10000, stdin);
        s[wordlenght(s) - 1] = '\0';
        t[wordlenght(t) - 1] = '\0';
        // printf("s: %s", s);
        // printf("t: %s", t);
        int ff = findOccurrence(s, string);
        // printf("s: %s\n", s);
        // printf("t: %s\n", t);
        // printf("ff: %d\n", ff);
        if (ff == -1)
        {
            continue;
        }
        // printf("%d", ff);
        char newString[10000];
        for (int i = 0; i < ff; i++)
        {
            newString[i] = string[i];
        }
        // printf("%s", newString);
        for (int i = 0; i < wordlenght(t); i++)
        {
            newString[ff + i] = t[i];
        }
        // printf("%s", newString);
        int j = ff + wordlenght(s);
        for (int i = ff + wordlenght(t); i < wordlenght(string) - wordlenght(s) + wordlenght(t); i++)
        {
            newString[i] = string[j];
            j++;
        }
        newString[wordlenght(string) + wordlenght(t) - wordlenght(s)] = '\0';
        for (int i = 0; i < 10000; i++)
        {
            string[i] = newString[i];
        }
        // printf("%s\n", newString);
    }
    // printf("%s\n", string);
    // printf("%d", wordlenght(string));
    for (int i = 0; i < wordlenght(string); i++)
    {
        printf("%c", string[i]);
    }
    printf("\n");
    return 0;
}