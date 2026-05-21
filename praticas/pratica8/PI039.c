#include <stdio.h>

// Forward declaration of function to implement
void shift(int a[], int n, int k)
{
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = temp[i];
    }
}

// print an array of size n (assume size >= 1)
void print_array(int a[], int n)
{
    printf("[%d", a[0]);
    for (int i = 1; i < n; i++)
        printf(",%d", a[i]);
    printf("]\n");
}

int main(void)
{

    // Read array of n integers
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Read integer, shift the array and print before and after
    int k;
    scanf("%d", &k);
    print_array(a, n);
    printf("After shift(a,%d,%d):\n", n, k);
    if (k < 0)
    {
        k = n + k;
    }
    shift(a, n, k);
    print_array(a, n);

    return 0;
}