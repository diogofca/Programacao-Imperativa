#include <stdio.h>

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
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int sum = 0;
    for (int j = 0; j < n; j++)
    {
        sum += mod(a[j % n] - a[(j + 1) % n]);
    }

    int min = sum;
    int j;
    for (int i = 0; i < n; i++)
    {
        int innerSum;
        if (i == 0)
        {
            innerSum = sum - mod(a[i] - a[n - 1]);
        }
        else
        {
            innerSum = sum - mod(a[i % n] - a[(i - 1) % n]);
        }
        // printf("%d\n", innerSum);

        if (innerSum < min)
        {
            min = innerSum;
            j = i;
        }
    }
    for (int i = j; i < n + j - 1; i++)
    {
        printf("%d ", a[i % n]);
    }
    printf("%d\n", a[(n + j - 1) % n]);
    return 0;
}