#include <stdio.h>

int main()

{

    int n;

    printf("Amount in EUR? ");
    scanf("%d", &n);

    int values[] = {20, 10, 5, 1};
    int coisos[4];
    for (int i = 0; i < 4; i++)
    {
        coisos[i] = n / values[i];
        n = n % values[i];
    }

    for (int i = 0; i < 4; i++)
    {
        if (coisos[i] == 0)
        {
            continue;
        }
        else
        {
            printf("EUR %d: %d\n", values[i], coisos[i]);
        }
    }
    return 0;
}