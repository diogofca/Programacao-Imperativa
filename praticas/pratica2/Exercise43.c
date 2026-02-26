#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a <= b + c || b <= a + c || c <= a + b)
    {
        printf("It is possible to form a triangle\n");
        if (a == b || a == c || c == b)
        {
            if (a == b && b == c)
            {
                printf("Equilateral\n");
            }
            else
            {
                printf("Isosceles\n");
            }
        }
        else
        {
            printf("scalene\n");
        }
    }
    else
    {
        printf("It is not possible to form the triangle\n");
    }

    return 0;
}
