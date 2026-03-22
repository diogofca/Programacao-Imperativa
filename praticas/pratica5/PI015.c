#include <stdio.h>
#include <stdbool.h>
int min(int a, int b);
int worldlenght(char *word);

char *whichComesFirst(char *word1, char *word2)
{
    if (word1 == 0)
    {
        return word2;
    }
    else if (word2 == 0)
    {
        return word1;
    }
    int l1 = worldlenght(word1);
    int l2 = worldlenght(word2);
    for (int i = 0; i < min(l1, l2); i++)
    {
        if (word1[i] < word2[i])
        {
            return word1;
        }
        else if (word1[i] > word2[i])
        {
            return word2;
        }
        else
        {
            continue;
        }
        if (l1 < l2)
        {
            return word1;
        }
        else
        {
            return word2;
        }
    }
    return word1;
}
int min(int a, int b)
{
    if (a <= b)
    {
        return a;
    }
    else
    {
        return b;
    }
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

bool iguais(char *word1, char *word2)
{
    if (worldlenght(word1) != worldlenght(word2))
    {
        return false;
    }
    int ll = worldlenght(word1);
    int visto[ll];
    int visto2[ll];
    for (int i = 0; i < ll; i++)
    {
        visto[i] = 0;
        visto2[i] = 0;
    }
    for (int i = 0; i < ll; i++)
    {
        for (int j = 0; j < ll; j++)
        {
            if (word1[i] == word2[j] && visto[j] == 0)
            {
                visto[j] = 1;
                visto2[i] = 1;
                break;
            }
        }
    }
    for (int i = 0; i < ll; i++)
    {
        if (visto2[i] != 1 || visto[i] != 1)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int vez = 1;
    while (true)
    {
        int N;
        scanf("%d", &N);
        if (N == 0)
        {
            break;
        }
        if (vez != 1)
        {
            printf("\n");
        }
        char palavras[N][51];
        for (int i = 0; i < N; i++)
        {
            scanf("%s", palavras[i]);
        }
        int diferentes[N];
        for (int i = 0; i < N; i++)
        {
            diferentes[i] = -1;
        }

        int newDifferent = 0;
        bool achou;
        for (int i = 0; i < N; i++)
        {
            achou = false;
            for (int j = 0; j < i; j++)
            {
                if (iguais(palavras[i], palavras[j]))
                {
                    diferentes[i] = diferentes[j];
                    achou = true;
                    break; // next word
                }
            }
            if (achou == false)
            {
                diferentes[i] = newDifferent;
                newDifferent += 1;
            }
        }
        printf("#%d\n", vez);
        vez++;
        int final_contagem[newDifferent];
        char *final_palavras[newDifferent];
        for (int i = 0; i < newDifferent; i++)
        {
            int counter = 0;
            char *word = 0;
            for (int j = 0; j < N; j++)
            {
                if (diferentes[j] == i)
                {
                    counter += 1;

                    word = whichComesFirst(palavras[j], word);
                }
            }
            // printf("%s: %d\n", word, counter);
            final_palavras[i] = word;
            final_contagem[i] = counter;
        }
        // for (int i = 0; i < newDifferent; i++)
        // {
        // printf("%s %d\n", final_palavras[i], final_contagem[i]);
        // }
        // bool jaFeitos[newDifferent];
        // for (int i = 0; i < newDifferent; i++)
        // {
        // jaFeitos == false;
        // }

        char *finalfinalpalavras[newDifferent];
        int finalfinalcontagem[newDifferent];
        char *word = 0;
        for (int i = 0; i < newDifferent; i++)
        {
            for (int j = 0; j < newDifferent; j++)
            {
                word = whichComesFirst(word, final_palavras[j]);
            }
            // printf("%s", final_palavras[0]);
            for (int j = 0; j < newDifferent; j++)
            {
                if (final_palavras[j] == word)
                {
                    // printf("%s: %d\n", word, final_contagem[j]);
                    finalfinalcontagem[i] = final_contagem[j];
                    finalfinalpalavras[i] = word;
                    final_palavras[j] = 0;
                }
            }
            word = 0;
        }
        // teste aqui
        for (int i = 0; i < newDifferent; i++)
        {
            int max = -1;
            for (int j = 0; j < newDifferent; j++)
            {
                if (finalfinalcontagem[j] > max)
                {
                    max = finalfinalcontagem[j];
                }
            }
            for (int j = 0; j < newDifferent; j++)
            {
                if (finalfinalcontagem[j] == max)
                {
                    printf("%s: %d\n", finalfinalpalavras[j], finalfinalcontagem[j]);
                    finalfinalcontagem[j] = -1;
                    break;
                }
            }
        }
    }
    return 0;
}