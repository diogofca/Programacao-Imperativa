#include <stdio.h>

int main()
{
    int P;
    scanf("%d", &P);
    if (P > 5000)
    {
        printf("%f", 0.6 * P);
    }
    else if (2500 < P && P <= 5000)
    {
        printf("%f", 0.8 * P);
    }
    else if (1000 < P && P <= 2500)
    {
        prinf("%f", 0.9 * P);
    }
    else if (P <= 1000)
    {
        printf("%f", 0.95 * P);
    }

    return 0;
}