
#include <stdio.h>
#include <stdbool.h>
int comparable(int x, int y)
{
    if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))
    {
        if (x <= y)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (x % 2 == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    int numbers[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < N; i++)
    {
        int min = i;
        for (int j = i + 1; j < N; j++)
        {
            if (comparable(numbers[j], numbers[min]))
            {
                min = j;
            }
        }
        int temp = numbers[i];
        numbers[i] = numbers[min];
        numbers[min] = temp;
    }
    for (int i = 0; i < N; i++)
    {
        if (i < N - 1)
        {
            printf("%d ", numbers[i]);
        }
        else
        {
            printf("%d\n", numbers[i]);
        }
    }

    return 0;
}