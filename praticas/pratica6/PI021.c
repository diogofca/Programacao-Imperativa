#include <stdio.h>
#include <stdbool.h>

bool binarySearch(int number[], int n, int start, int end, int toSearch)
{
    if (start == end)
    {
        if (number[start] == toSearch)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int middle = (end + start) / 2;
    if (number[middle] == toSearch)
    {
        return true;
    }
    else if (number[middle] < toSearch)
    {
        return binarySearch(number, n, middle + 1, end, toSearch);
    }
    else if (number[middle] > toSearch)
    {
        return binarySearch(number, n, start, middle, toSearch);
    }
    return false;
}

int main()
{
    int n;
    scanf("%d", &n);
    int numbers[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }
    int N;
    scanf("%d", &N);
    int toCheck[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &toCheck[i]);
    }
    for (int i = 0; i < N; i++)
    {
        if (binarySearch(numbers, n, 0, n - 1, toCheck[i]))
        {
            if (i == N - 1)
            {
                printf("yes");
            }
            else
            {
                printf("yes ");
            }
        }
        else
        {
            if (i == N - 1)
            {
                printf("no");
            }
            else
            {
                printf("no ");
            }
        }
    }
    printf("\n");
    return 0;
}