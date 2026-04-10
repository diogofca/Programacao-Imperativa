#include <stdio.h>
#include <stdbool.h>

int binarySearch(int number[], int n, int start, int end, int toSearch)
{
    if (start == end)
    {
        // printf("%d", start);
        if (number[start] <= toSearch)
        {
            return number[start];
        }
        else
        {
            return 0;
        }
    }
    if (end == start + 1)
    {
        if (toSearch >= number[end])
        {
            return number[end];
        }
        else if (toSearch >= number[start])
        {
            return number[start];
        }
        else
        {
            return 0;
        }
    }
    int middle = (end + start) / 2;
    // printf("%d", middle);
    if (number[middle] <= toSearch)
    {
        return binarySearch(number, n, middle, end, toSearch);
    }
    else if (number[middle] > toSearch)
    {
        return binarySearch(number, n, start, middle - 1, toSearch);
    }
    return 0;
}
int main()
{
    int N;
    scanf("%d", &N);
    int cars[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &cars[i]);
    }
    int n;
    scanf("%d", &n);
    int drivers[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &drivers[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            printf("%d ", binarySearch(cars, N, 0, N - 1, drivers[i]));
        }
        else
        {
            printf("%d", binarySearch(cars, N, 0, N - 1, drivers[i]));
        }
    }
    printf("\n");

    return 0;
}