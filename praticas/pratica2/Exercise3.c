#include <stdio.h>

int main()
{

    long int L, W, H;
    scanf("%ld %ld %ld", &L, &W, &H);
    long int volume = L * W * H;
    printf("Volume: %ld\n", volume);

    return 0;
}