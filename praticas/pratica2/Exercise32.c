#include <stdio.h>
#define PI 3.14159

int main()
{
    int R, H;
    scanf("%d %d", &R, &H);

    double volume = PI * R * R * H / 3.0;
    printf("volume is %f\n", volume);
    return 0;
}