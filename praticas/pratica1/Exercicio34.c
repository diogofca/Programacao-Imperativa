#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int atual = 0;
    int maior = 0;
    for (int i = 0; i < n; i++)
    {
        int new;
        scanf("%d", &new);
        if (new > 0)
        {
            atual += 1;
        }
        if (new <= 0)
        {
            if (atual > maior)
            {
                maior = atual;
            }
            atual = 0;
        }
    }
    if (atual > maior)
    {
        maior = atual;
    }

    printf("Aqui está: %d\n", maior);

    // printf("Os números maiores são : %d %d\n", maior1, maior2);
    return 0;
}