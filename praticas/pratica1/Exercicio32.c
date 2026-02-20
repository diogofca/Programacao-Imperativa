#include <stdio.h>

int main()
{
    int n = 12345;
    int sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }
    printf("Soma dos digitos = %d\n", sum);
    return 0;
}