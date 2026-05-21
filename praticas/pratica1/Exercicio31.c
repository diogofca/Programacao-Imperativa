#include <stdio.h>

int main()
{
    int n = 12345;
    int sum = 0;
    while (n != 0)
    {
        sum += 1;
        n /= 10;
    }
    printf("Num. de digitos= %d\n", sum);
    return 0;
}