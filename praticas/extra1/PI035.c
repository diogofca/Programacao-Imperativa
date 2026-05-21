#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX_STRING 100

bool CompareContactsFinal(char *a, char *b);
struct Contact
// this is stricking
{
    char name[MAX_STRING];
    char email[MAX_STRING];
    char birth[MAX_STRING];
    int phone;
};

bool compareNames1(char *a, char *b)
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
    return CompareContactsFinal(a.name, b.name);
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int wordleghtSpace(char *name)
{
    int counter = 0;
    while (*name != ' ' && *name != '\0')
    {
        counter += 1;
        name += 1;
    }
    return counter;
}

bool equalStrigs(char *a, char *b, int al, int bl)
{
    for (int i = 0; i < al; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

bool CompareContactsFinal(char *a, char *b)
{
    int al = wordleghtSpace(a);
    int bl = wordleghtSpace(b);
    if (al == bl && equalStrigs(a, b, al, bl))
    {
        // do nothing
        // continue to the next pair of words
        a = a + al;
        b = b + al;
    }
    else
    {
        char name1[al + 1];
        char name2[bl + 1];
        for (int i = 0; i < al; i++)
        {
            name1[i] = a[i];
        }
        name1[al] = '\0';
        for (int i = 0; i < bl; i++)
        {
            name2[i] = b[i];
        }
        name2[bl] = '\0';
        // printf("%s %s\n", name1, name2);
        return compareNames1(name1, name2);
    }

    while (true)
    {
        if (*a == '\0' && *b == '\0')
        {
            return true;
        }
        else if (*a == '\0')
        {
            return true;
        }
        else if (*b == '\0')
        {
            return false;
        }
        a += 1;
        b += 1;
        int aWordLenght = wordleghtSpace(a);
        int bWordLenght = wordleghtSpace(b);
        if (aWordLenght == bWordLenght && equalStrigs(a, b, aWordLenght, bWordLenght))
        {
            a = a + aWordLenght;
            b = b + bWordLenght;
            continue;
        }
        else
        {
            char name1[aWordLenght + 1];
            char name2[bWordLenght + 1];
            for (int i = 0; i < aWordLenght; i++)
            {
                name1[i] = a[i];
            }
            name1[aWordLenght] = '\0';
            for (int i = 0; i < bWordLenght; i++)
            {
                name2[i] = b[i];
            }
            name2[bWordLenght] = '\0';
            // printf("%s %s\n", name1, name2);
            return compareNames1(name1, name2);
        }
    }
}

void sortContact(int n, struct Contact cc[n], int vv[n])
{
    for (int i = 0; i < n; i++)
    {
        int *min = &vv[i];
        for (int j = i; j < n; j++)
        {
            if (compareContacts(cc[vv[j]], cc[*min]))
            {
                min = &vv[j];
            }
        }
        swap(min, &vv[i]);
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
        int month;
        scanf("%d", &month);
        if (1 <= month && month <= 9)
        {
            mes[0] = '0';
            switch (month)
            {
            case 1:
                /* code */
                mes[1] = '1';
                break;
            case 2:
                /* code */
                mes[1] = '2';
                break;

            case 3:
                /* code */
                mes[1] = '3';
                break;
            case 4:
                /* code */
                mes[1] = '4';
                break;
            case 5:
                /* code */
                mes[1] = '5';
                break;
            case 6:
                /* code */
                mes[1] = '6';
                break;
            case 7:
                /* code */
                mes[1] = '7';
                break;
            case 8:
                /* code */
                mes[1] = '8';
                break;
            case 9:
                /* code */
                mes[1] = '9';
                break;
            default:
                break;
            }
        }
        else if (month == 10)
        {
            mes[0] = '1';
            mes[1] = '0';
        }
        else if (month == 11)
        {
            mes[0] = '1';
            mes[1] = '1';
        }
        else
        {
            mes[0] = '1';
            mes[1] = '2';
        }
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
        // char ll[] = "Zezere";
        // char ll1[] = "Xai";
        // printf("\n%d\n", CompareContactsFinal(ll, ll1));
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