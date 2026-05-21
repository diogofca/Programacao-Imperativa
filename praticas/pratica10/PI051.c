#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    char name[100];
    char category;
} Patient;
int main()
{

    int N;
    scanf("%d", &N);
    Patient patient_list[N];
    int pos = 0;
    int a_patients[N];
    int pos_a = 0;
    int b_patients[N];
    int pos_b = 0;
    int c_patient[N];
    int pos_c = 0;
    int pos_aa = 0;
    int pos_bb = 0;
    int pos_cc = 0;
    for (int i = 0; i < N; i++)
    {
        int command;
        char temp;
        scanf("%d", &command);
        scanf("%c", &temp);
        // scanf("%c", &temp);

        // printf("%d", command);
        if (command == 0)
        {
            fgets(&patient_list[pos].name[0], 1000, stdin);
            // scanf("%c", &temp);
            //   printf("%s ", patient_list[pos].name);
            char category;
            scanf("%c", &category);
            // scanf("%c", &temp);
            //  printf("%c\n", category);
            patient_list[pos].category = category;
            // printf("%c, %s", patient_list[pos].category, patient_list[pos].name);
            if (category == 'A')
            {

                a_patients[pos_a] = pos;
                pos_a++;
            }
            else if (category == 'B')
            {
                b_patients[pos_b] = pos;
                pos_b++;
            }
            else if (category == 'C')
            {
                c_patient[pos_c] = pos;
                pos_c++;
            }
            pos += 1;
            // lala
        }
        else if (command == 1)
        {
            if (pos_aa < pos_a)
            {
                int removed_val;
                removed_val = a_patients[pos_aa];
                printf("%s", patient_list[removed_val].name);
                pos_aa++;
            }
            else if (pos_bb < pos_b)
            {
                int removed_val;
                removed_val = b_patients[pos_bb];
                printf("%s", patient_list[removed_val].name);
                pos_bb++;
            }
            else if (pos_cc < pos_c)
            {
                int removed_val;
                removed_val = c_patient[pos_cc];
                printf("%s", patient_list[removed_val].name);
                pos_cc++;
            }
        }
    }
}