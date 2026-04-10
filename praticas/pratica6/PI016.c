#include <stdio.h>
#include <stdbool.h>

// just a small change

int worldlenght(char *word);

bool areWordsEqual(char *word1, char *word2)
{
    if (worldlenght(word1) != worldlenght(word2))
    {
        return false;
    }
    for (int i = 0; i < worldlenght(word1); i++)
    {
        if (word1[i] != word2[i])
        {
            return false;
        }
    }

    return true;
}
int worldlenght(char *word)
{
    int len = 0;
    while (*word != '\0')
    {
        len += 1;
        word += 1;
    }
    return len;
}

int splitString(char *string, char *words[], char *sequence)
{
    int p = 0;
    int l = worldlenght(sequence);
    words[p] = string;
    p++;
    for (int i = l; i < worldlenght(string); i++)
    {
        bool last = true;
        for (int j = 1; j <= l; j++)
        {
            if (string[i - j] != sequence[worldlenght(sequence) - j])
            {
                last = false;
            }
        }
        if (last)
        {
            // printf("Aqui");
            //  string[i - l] = '\0';

            words[p] = &string[i];
            p += 1;
        }
    }
    return p;
}

void putLetterInside(char *beginning, char *end, char *palavra)
{
    int t = 0;
    for (char *i = beginning; i < end; i++)
    {
        palavra[t] = *i;
    }
    palavra[t] = '\0';
}

void printLetter(char *letter)
{
    // lala
    char *code[] = {"10111", "111010101", "11101011101", "1110101", "1", "101011101", "111011101", "1010101", "101", "1011101110111", "111010111", "101110101", "1110111", "11101", "11101110111", "10111011101", "1110111010111", "1011101", "10101", "111", "1010111", "101010111", "101110111", "11101010111", "1110101110111", "11101110101", "10111011101110111", "101011101110111", "1010101110111", "10101010111", "101010101", "11101010101", "1110111010101", "111011101110101", "11101110111011101", "1110111011101110111"};
    char *devode = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    for (int i = 0; i < 36; i++)
    {
        if (areWordsEqual(code[i], letter))
        {
            printf("%c", devode[i]);
        }
    }
}

int main()
{
    // char *code[] = {"10111", "111010101", "11101011101", "1110101", "1", "101011101", "111011101", "1010101", "101", "1011101110111", "111010111", "101110101", "1110111", "11101", "11101110111", "10111011101", "1110111010111", "1011101", "10101", "111", "1010111", "101010111", "101110111", "11101010111", "1110101110111", "11101110101", "10111011101110111", "101011101110111", "1010101110111", "10101010111", "1010101010", "11101010101", "1110111010101", "111011101110101", "11101110111011101", "1110111011101110111"};
    // char *devode = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    char message[5100 * 10];
    scanf("%s", message);
    char *words[51000];

    // char caso[] = "101110001110101010001110101110100011101010001000101011101000111011101000101010100010100010111011101110001110101110001011101010001110111000111010001110111011100010111011101000111011101011100010111010001010100011100010101110001010101110001011101110001110101011100011101011101110001110111010100011101110111011101110001011101110111011100010101110111011100010101011101110001010101011100010101010100011101010101000111011101010100011101110111010100011101110111011101";
    // if (areWordsEqual(message, caso))
    // {
    // printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\n");
    // return 0;
    // }

    int numberOfWords = splitString(message, words, "0000000");
    // printf("%d\n", numberOfWords);
    for (int i = 0; i < numberOfWords; i++)
    {
        // printf("%s\n", words[i]);
    }
    words[numberOfWords] = message + worldlenght(message);

    for (int i = 0; i < numberOfWords; i++)
    {
        char word[51];
        int t = 0;
        for (char *j = words[i]; j < words[i + 1]; j++)
        {
            word[t] = *j;
            t++;
        }
        if (i < numberOfWords - 1)
        {
            word[t - 7] = '\0';
        }
        word[t] = '\0';
        // printf("%s\n", word);

        char *letters[50];
        int numberOfLetters = splitString(word, letters, "000");
        letters[numberOfLetters] = word + worldlenght(word);
        for (int y = 0; y < numberOfLetters; y++)
        {
            char letter[20];
            int T = 0;

            for (char *u = letters[y]; u < letters[y + 1]; u++)
            {
                letter[T] = *u;
                T++;
            }
            if (y < numberOfLetters - 1)
            {
                letter[T - 3] = '\0';
            }
            else
            {
                letter[T] = '\0';
            }
            printLetter(letter);
        }
        if (i == numberOfWords - 1)
        {
            printf("\n");
        }
        else
        {
            printf(" ");
        }
    }

    // falta a ultima

    return 0;
}