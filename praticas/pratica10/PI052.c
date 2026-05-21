#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

int power(int a, int b)
{
    int toRetunr = 1;
    for (int i = 0; i < b; i++)
    {
        toRetunr *= a;
    }
    return toRetunr;
}

int wordlenght(char *word)
{
    int toReturn = 0;
    while (*word != '\0')
    {
        toReturn += 1;
        word += 1;
    }
    return toReturn;
}

bool isNumber(char *word)
{
    for (int i = 0; i < wordlenght(word); i++)
    {
        char lala = word[i];
        if (!(lala >= '0' && lala <= '9'))
        {
            return false;
        }
    }
    return true;
}

int convert_assist(char digit)
{
    if (digit == '0')
    {
        return 0;
    }
    if (digit == '1')
    {
        return 1;
    }
    if (digit == '2')
    {
        return 2;
    }
    if (digit == '3')
    {
        return 3;
    }
    if (digit == '4')
    {
        return 4;
    }
    if (digit == '5')
    {
        return 5;
    }
    if (digit == '6')
    {
        return 6;
    }
    if (digit == '7')
    {
        return 7;
    }
    if (digit == '8')
    {
        return 8;
    }
    if (digit == '9')
    {
        return 9;
    }
    return 0;
}

int convert(char *number)
{
    int toReturn = 0;
    int j = 0;
    for (int i = wordlenght(number) - 1; i >= 0; i--)
    {
        toReturn += convert_assist(number[i]) * power(10, j);
        j++;
    }
    return toReturn;
}

int main()
{
    int N;
    scanf("%d", &N);
    for (int t = 0; t < N; t++)
    {
        bool broke = false;

        int stack[10000];
        int pos = 0;
        while (true)
        {

            char expression[10];
            char tmp;
            // printf("here");
            scanf("%s", &expression[0]);
            // printf("here");
            scanf("%c", &tmp);
            // printf("operation: %s", expression);

            // printf("%d", wordlenght(expression));
            //  printf("%d", isNumber(expression));
            if (isNumber(expression))
            {
                // printf("here: %s", expression);
                int number;
                number = 0;
                number = convert(expression);
                // printf("converted : (%d)", number);
                stack[pos] = number;
                pos += 1;
            }
            else
            {
                char operation = expression[0];
                if (operation == '+')
                {
                    if (pos <= 1)
                    {
                        broke = true;
                        printf("Expressao Incorreta\n");
                        break;
                    }
                    else
                    {
                        int one = stack[pos - 1];
                        int two = stack[pos - 2];
                        int result = one + two;
                        stack[pos - 2] = result;
                        pos--;
                    }
                }
                else if (operation == '*')
                {
                    if (pos <= 1)
                    {
                        broke = true;
                        printf("Expressao Incorreta\n");
                        break;
                    }
                    else
                    {
                        int one = stack[pos - 1];
                        int two = stack[pos - 2];
                        int result = one * two;
                        stack[pos - 2] = result;
                        pos--;
                    }
                }
                else if (operation == '-')
                {
                    if (pos <= 1)
                    {
                        broke = true;
                        printf("Expressao Incorreta\n");
                        break;
                    }
                    else
                    {
                        int one = stack[pos - 1];
                        int two = stack[pos - 2];
                        int result = two - one;
                        stack[pos - 2] = result;
                        pos--;
                    }
                }
                else if (operation == '/')
                {
                    if (pos <= 1)
                    {
                        broke = true;
                        printf("Expressao Incorreta\n");
                        break;
                    }
                    else
                    {
                        int one = stack[pos - 1];
                        int two = stack[pos - 2];
                        int result = two / one;
                        stack[pos - 2] = result;
                        pos--;
                    }
                }
            }

            if (tmp == '\n' || tmp == EOF)
            {

                break;
            }

            // char imidiate_charater;
            // scanf("%c", &imidiate_charater);
            // printf("%c ", imidiate_charater);
            // if (imidiate_charater == '\n')
            //{
            //// printf("here");
            // break;
            //}
        }
        if (broke == false)
        {
            if (pos != 1)
            {
                printf("Expressao Incorreta\n");
            }
            else
            {
                printf("%d\n", stack[0]);
            }
        }
    }

    return 0;
}