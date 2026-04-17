#include <stdio.h>
#include <stdbool.h>
#include <string.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
struct restaurant
{
    char name[100];
    char NIF[100];
    char area[100];
    int atividade_economica;
    int rendimentos;
};

void printPlace(struct restaurant *p)
{
    printf("%s, %s, %s, %d, %d\n", p->name, p->NIF, p->area, p->atividade_economica, p->rendimentos);
}

int main()
{
    int n, f;
    scanf("%d %d", &n, &f);
    char dd;
    scanf("%c", &dd);
    struct restaurant sitios[n];
    for (int i = 0; i < n; i++)
    {
        fgets(sitios[i].NIF, 100, stdin);
        fgets(sitios[i].name, 100, stdin);
        fgets(sitios[i].area, 100, stdin);
        scanf("%d", &sitios[i].atividade_economica);
        scanf("%d", &sitios[i].rendimentos);
        char dummy;
        scanf("%c", &dummy);
    }
    // for (int i = 0; i < n; i++)
    // {
    // printPlace(&sitios[i]);
    // }

    // count number of economic activities
    int counter = 0;
    int ea[n];
    int ea_counter[n];
    for (int i = 0; i < n; i++)
    {
        ea_counter[i] = 0;
    }
    int new = 0;
    bool found = false;
    int found_where = -1;
    for (int i = 0; i < n; i++)
    {
        found = false;
        for (int j = 0; j < new; j++)
        {
            if (sitios[i].atividade_economica == ea[j])
            {
                found = true;
                found_where = j;
                break;
            }
        }
        if (found)
        {
            ea_counter[found_where] += sitios[i].rendimentos;
        }
        else
        {
            ea[new] = sitios[i].atividade_economica;
            counter += 1;
            ea_counter[new] += sitios[i].rendimentos;
            new += 1;
        }
    }

    if (f == 0)
    {
        printf("%d\n", counter);
    }
    else if (f == 1)
    {
        int max = 0;
        for (int i = 0; i < counter; i++)
        {
            if (sitios[i].atividade_economica > max)
            {
                max = sitios[i].atividade_economica;
            }
        }

        int MAX = max + 10;
        for (int i = 0; i < counter; i++)
        {
            int min = 0;
            for (int j = 0; j < counter; j++)
            {
                if (ea[j] < ea[min])
                {
                    min = j;
                }
            }
            printf("%d %d\n", ea[min], ea_counter[min]);
            ea[min] = MAX;
        }
    }

    return 0;
}