#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int maior1;
    int maior2;

    scanf("%d", &maior1);
    scanf("%d", &maior2);
    for (int i = 2; i < n; i++)
    {
        int new;
        scanf("%d", &new);
        if (new > maior1 || new > maior2)
        {
            int max = (maior1 > maior2 ? maior1 : maior2);
            maior1 = max;
            maior2 = new;
        }
    }

    printf("Os números maiores são : %d %d\n", maior1, maior2);
    return 0;
}