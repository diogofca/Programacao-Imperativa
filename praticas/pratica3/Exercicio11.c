#include <stdio.h>

int main()
{
    int sum = 0;
    char c;
    while (c != '\n')
    {
        scanf("%c", &c);
        if (c >= 'a' && c <= 'z')
        {
            sum += 1;
        }
    }
    printf("%d\n", sum);
    return 0;
}