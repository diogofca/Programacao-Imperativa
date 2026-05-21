#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if ((a < b + c && b < a + c && c < a + b) && (a > 0 && b > 0 && c > 0))
    {
        printf("(%d, %d, %d) defines a triangle\n", a, b, c);
    }
    else
    {
        printf("(%d, %d, %d) cannot define a triangle\n", a, b, c);
    }
    return 0;
}