#include <stdio.h>

int contains(int j, int arr[], int a)
{
    for (int i = 0; i < j; i++)
    {
        if (arr[i] == a)
        {
            return 0;
        }
    }
    return 1;
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

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    int lala[max + 1];

    for (int i = 0; i < max + 1; i++)
    {
        lala[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (lala[a[i]] == 0)
        {
            if (i == 0)
            {
                printf("%d", a[i]);
            }
            else
            {
                printf(" %d", a[i]);
            }
            lala[a[i]] = 1;
        }
    }
    printf("\n");
    return 0;
}