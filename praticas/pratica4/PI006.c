#include <stdio.h>
#include <string.h>

int mod(int x)
{
    if (x > 0)
    {
        return x;
    }
    else
    {
        return -x;
    }
}

int main()
{

    int n;
    scanf("%d", &n);
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    int min = mod(a[0] - b[0]);
    for (int i = 0; i < n; i++)
    {
        int a_r = a[i];
        int b_r = b[i];
        if (mod(a_r - b_r) < min)
        {
            min = mod(a_r - b_r);
        }
    }

    printf("%d\n", min);

    return 0;
}