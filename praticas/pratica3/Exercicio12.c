#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum = 0;
    char c;
    while (c != EOF)
    {
        c = getchar();
        if (c == '\t' || c == '\n' || c == ' ')
        {
            sum += 1;
        }
    }
    printf("%d\n", sum);
    return 0;
}