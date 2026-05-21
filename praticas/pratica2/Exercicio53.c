#include <stdio.h>

int main()
{

    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = n; i <= n * m; i += n)
    {
        if (i % m == 0)
        {
            printf("%d\n", i);
            return 0;
        }
    }

    return 0;
}