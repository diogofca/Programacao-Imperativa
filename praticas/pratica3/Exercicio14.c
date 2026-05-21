#include <stdio.h>

int main()
{

    char c;
    int vowels = 0;
    int consonants = 0;
    int digits = 0;
    int punctuation = 0;
    do
    {
        c = getchar();
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            {
                vowels += 1;
            }
            else
            {
                consonants += 1;
            }
        }
        else if (c >= '0' && c <= '9')
        {
            digits += 1;
        }
        else if (c >= '!' && c <= '/')
        {
            punctuation += 1;
        }

    } while (c != '\n');

    printf("vowels: %d\n", vowels);
    printf("consonants: %d\n", consonants);
    printf("digits: %d\n", digits);
    printf("punctuation: %d\n", punctuation);
    return 0;
}