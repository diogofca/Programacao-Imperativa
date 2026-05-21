#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

union number
{
    int i;
    double d;
};

typedef struct
{
    int number;
    int type;
    union data
    {
        struct
        {
            char *name;

        } atuamae;
        struct
        {
            char *name2;
        } atuapai;
    } data;

} Policy;

void lala()
{
    printf("lala\n");
}

void func_caller(void (*f)())
{
    printf("Function calling\n");
    f();
}

int main()
{

    int *arr = (int *)calloc(5, sizeof(int));
    if (arr == NULL)
    {
        printf("Error\n");
        return 0;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]);
    }

    free(arr);
    func_caller(lala);
    union number N;
    N.d = 9.0;

    assert(1 == 0);
    return 0;
}