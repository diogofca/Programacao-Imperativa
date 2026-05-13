#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX 200
#define SKIPEOL                   \
    {                             \
        while (getchar() != '\n') \
            ;                     \
    }

bool check(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return true;
    }
    else if (a == '[' && b == ']')
    {
        return true;
    }
    else if (a == '{' && b == '}')
    {
        return true;
    }
    else
    {
        return false;
    }
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
void verify(char *line)
{
    char stuff[MAX];
    int pos = 0;
    for (int i = 0; i < worldlenght(line); i++)
    {
        char pos_char = line[i];
        if (pos_char == '(' || pos_char == '{' || pos_char == '[')
        {
            stuff[pos] = pos_char;
            pos += 1;
        }
        else if (pos_char == ')' || pos_char == '}' || pos_char == ']')
        {
            if (pos - 1 < 0)
            {
                printf("Erro na posicao %d\n", i);
                return;
            }
            else if (!check(stuff[pos - 1], pos_char))
            {

                printf("Erro na posicao %d\n", i);
                return;
            }
            else
            {
                pos -= 1;
            }
        }
    }
    if (pos == 0)
    {
        printf("Expressao bem formada\n");
        return;
    }
    else
    {
        printf("Ficam parenteses por fechar\n");
        return;
    }
}

int main()
{
    int ncases;
    char line[MAX];

    scanf("%d", &ncases);
    SKIPEOL;
    for (int c = 0; c < ncases; c++)
    {
        fgets(line, sizeof(line), stdin);
        verify(line);
    }
}