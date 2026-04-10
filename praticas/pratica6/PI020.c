#include <stdio.h>
#include <stdbool.h>

int powe(int a, int b)
{
    int toReturn = 1;
    for (int i = 0; i < b; i++)
    {
        toReturn *= a;
    }
    return toReturn;
}

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

    char matricula[10];
    scanf("%s", matricula);
    int n = wordlenght(matricula);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (matricula[n - 1 - i] - 'a' + 1) * powe(26, i);
    }
    printf("%d\n", sum);
    return 0;
}