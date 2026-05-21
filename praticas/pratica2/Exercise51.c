#include <math.h>
#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int delta = b * b - 4 * a * c;
    if (delta < 0)
    {
        printf("Não tem soluções\n");
    }
    else if (delta == 0)
    {
        double x_1 = -(double)b / (2 * a);
        printf("tem uma solucao %f\n", x_1);
    }
    else
    {
        double x_1 = (-(double)b + sqrt(delta)) / (2 * a);
        double x_2 = (-(double)b - sqrt(delta)) / (2 * a);
        printf("tem duas solucoes %f %f\n", x_1, x_2);
    }
    return 0;
}