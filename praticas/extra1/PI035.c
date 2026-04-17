#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_STRING 1000
struct Contact
// this is stricking
{
    char name[MAX_STRING];
    char email[MAX_STRING];
    char birth[MAX_STRING];
    int phone;
};

#include <ctype.h>

bool compareNames(char *a, char *b)
{
    while (*a || *b)
    {
        while (*a && !isalpha(*a))
            a++;
        while (*b && !isalpha(*b))
            b++;

        char ca = tolower(*a);
        char cb = tolower(*b);

        if (ca < cb)
            return true;
        if (ca > cb)
            return false;

        if (*a)
            a++;
        if (*b)
            b++;
    }
    return true;
}
bool compareNames(char *a, char *b)
{
    while (*a != '\0' && *b != '\0')
    {
        // printf("hello there");
        if (*a >= 'a' && *a <= 'z' && *b >= 'a' && *b <= 'z')
        {
            // printf("%c %c\n", *a, *b);
            //    printf("aqui");
            if (*a < *b)
            {
                // printf("aqui");
                return true;
            }
            if (*a > *b)
            {
                return false;
            }
            if (*a == *b)
            {
                a += 1;
                b += 1;
            }
            continue;
        }
        if (*a >= 'A' && *a <= 'Z')
        {
            // printf("aqui");
            *a = *a - 'A' + 'a';
        }
        else if (!(*a >= 'a' && *a <= 'z'))
        {
            a += 1;
        }

        if (*b >= 'A' && *b <= 'Z')
        {
            *b = *b - 'A' + 'a';
        }
        else if (!(*b >= 'a' && *b <= 'z'))
        {
            b += 1;
        }
    }
    if (*b == *a)
    {
        return true;
    }
    else if (*b != '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
    return true;
}

bool compareContacts(struct Contact a, struct Contact b)
{
    return compareNames1(a.name, b.name);
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortContact(int n, struct Contact cc[n], int vv[n])
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (compareContacts(cc[vv[j]], cc[vv[min]]))
            {
                min = j;
            }
        }
        swap(&vv[min], &vv[i]);
    }
}

int wordlenght(char *palavra)
{
    int counter = 0;
    while (*palavra != '\0')
    {
        palavra += 1;
        counter += 1;
    }
    return counter;
}
bool monthEqual(char *pessoa, char mes[2])
{
    if (pessoa[4] == mes[0] && pessoa[5] == mes[1])
    {
        return true;
    }
    return false;
}

int main()
{
    int N;
    char dd;
    scanf("%d", &N);
    struct Contact pessoas[N];
    // printf("aqui\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%c", &dd);
        fgets(pessoas[i].name, MAX_STRING, stdin);
        pessoas[i].name[wordlenght(pessoas[i].name) - 1] = '\0';
        scanf("%s", pessoas[i].email);
        scanf("%s", pessoas[i].birth);
        scanf("%d", &pessoas[i].phone);
    }
    // printf("aqiu");
    int flag;
    scanf("%d", &flag);
    if (flag == 0)
    {
        char mes[MAX_STRING];
        scanf("%s", mes);
        int counter = 0;
        for (int i = 0; i < N; i++)
        {
            if (monthEqual(pessoas[i].birth, mes))
            {
                printf("%s %d\n", pessoas[i].name, pessoas[i].phone);
                counter += 1;
            }
        }
        if (counter == 0)
        {
            printf("NONE\n");
        }
    }
    else if (flag == 1)
    {
        // char ll[] = "Diogo Almeida";
        // char ll1[] = "Diogo Leite leite";
        // printf("\n%d\n", compareNames(ll1, ll));
        int vv[N];
        for (int i = 0; i < N; i++)
        {
            vv[i] = i;
        }
        sortContact(N, pessoas, vv);
        for (int i = 0; i < N; i++)
        {
            struct Contact *my = &pessoas[vv[i]];
            printf("%s\n%s\n%s\n%d\n", my->name, my->email, my->birth, my->phone);
        }
    }
    return 0;
}