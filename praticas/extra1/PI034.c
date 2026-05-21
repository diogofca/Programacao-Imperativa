#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int wordlenght(char *palavra)
{
    int counter = 0;
    while (*palavra != '\0')
    {
        palavra += 1;
        counter += 1;
    }
    return counter;
}
void iteration(char *sequence)
{
    char temporario[wordlenght(sequence)];
    char *temporario2 = (char *)temporario;
    for (int i = 0; i < wordlenght(sequence); i++)
    {
        temporario[i] = sequence[i];
    }
    int ll = wordlenght(sequence);
    for (int i = 0; i < ll; i++)
    {
        if (*temporario2 == 'A')
        {
            *sequence = 'A';
            sequence += 1;
            *sequence = 'B';
            sequence += 1;
        }
        else if (*temporario2 == 'B')
        {
            *sequence = 'A';
            sequence += 1;
        }
        temporario2 += 1;
    }
    *temporario2 = '\0';
}

int main()
{
    int N;
    char palabra[100001];
    scanf("%s", palabra);
    scanf("%d", &N);
    printf("%s\n", palabra);
    for (int i = 0; i < N; i++)
    {
        iteration(palabra);
        printf("%s\n", palabra);
    }

    return 0;
}