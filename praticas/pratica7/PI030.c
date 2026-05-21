#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define MAX_CHAR 100

int wordlenght(char *word)
{
    int i = 0;
    while (*word != '\0')
    {
        word += 1;
        i++;
    }
    return i;
}

struct aluno
{
    char BI[MAX_CHAR];
    char Nome[MAX_CHAR];
    char Faculdade[MAX_CHAR];
    int faculdade_codigo;
    int media;
};

int main()
{

    int NA, f;
    char dd;
    scanf("%d %d", &NA, &f);
    scanf("%c", &dd);

    struct aluno alunos[NA];
    for (int i = 0; i < NA; i++)
    {
        fgets(alunos[i].BI, MAX_CHAR, stdin);
        fgets(alunos[i].Nome, MAX_CHAR, stdin);
        fgets(alunos[i].Faculdade, MAX_CHAR, stdin);
        scanf("%d", &alunos[i].faculdade_codigo);
        scanf("%d", &alunos[i].media);
        scanf("%c", &dd);
    }
    int estabelecimentos[NA];
    int new = 0;
    for (int i = 0; i < NA; i++)
    {
        bool found = false;
        for (int j = 0; j < new; j++)
        {
            if (estabelecimentos[j] == alunos[i].faculdade_codigo)
            {
                found = true;
            }
        }
        if (!found)
        {
            estabelecimentos[new] = alunos[i].faculdade_codigo;
            new += 1;
        }
    }
    if (f == 0)
    {
        printf("%d\n", new);
        return 0;
    }
    else if (f == 1)
    {
        // find the highest grade
        int min = 0;
        for (int i = 0; i < NA; i++)
        {
            if (alunos[i].media > min)
            {
                min = alunos[i].media;
            }
        }
        printf("%d\n", min);
        for (int i = 0; i < NA; i++)
        {
            if (alunos[i].media == min)
            {
                printf("%s", alunos[i].Nome);
            }
        }
    }
    else if (f == 2)
    {
        int medias[new];
        int medias_counter[new];
        for (int i = 0; i < new; i++)
        {
            medias[i] = 0;
            medias_counter[i] = 0;
        }
        for (int i = 0; i < NA; i++)
        {
            for (int j = 0; j < new; j++)
            {
                if (estabelecimentos[j] == alunos[i].faculdade_codigo)
                {
                    medias[j] += alunos[i].media;
                    medias_counter[j] += 1;
                }
            }
        }
        int medias_float[new];
        for (int i = 0; i < new; i++)
        {
            medias_float[i] = (int)round((double)medias[i] / medias_counter[i]);
        }
        for (int i = 0; i < new; i++)
        {
            int max = 0;
            for (int j = 0; j < new; j++)
            {
                if (medias_float[j] > medias_float[max])
                {
                    max = j;
                }
            }
            // max é onde está o maior coiso
            int number_of_student_concorreram = 0;
            char *nome_da_instituicao;
            for (int j = 0; j < NA; j++)
            {
                if (alunos[j].faculdade_codigo == estabelecimentos[max])
                {
                    number_of_student_concorreram += 1;
                    nome_da_instituicao = alunos[j].Faculdade;
                }
            }
            nome_da_instituicao[wordlenght(nome_da_instituicao) - 1] = '\0';
            printf("%s %d %d\n", nome_da_instituicao, number_of_student_concorreram, medias_float[max]);

            medias_float[max] = -1;
        }
    }
    return 0;
}