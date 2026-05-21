#include <stdio.h>
#include <stdbool.h>

void swap(int n, int a, int b, int c)
{
    if (n == 1)
    {
        printf("%d -> %d\n", a, b);
        return;
    }
    else
    {
        swap(n - 1, a, c, b);
        printf("%d -> %d\n", a, b);
        swap(n - 1, c, b, a);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    swap(n, 1, 3, 2);
    return 0;
}