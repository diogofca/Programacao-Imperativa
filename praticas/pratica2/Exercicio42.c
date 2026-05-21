#include <stdio.h>

int main()
{
    int ano, dia;

    scanf("%d %d", &ano, &dia);
    int january, february, march, april, may, june, july, august, september, october, november, december;

    if (ano % 4 == 0)
    {
        february = 29;
    }
    else
    {
        february = 28;
    }
    january = 31;
    march = 31;
    april = 30;
    may = 31;
    june = 30;
    july = 31;
    august = 31;
    september = 30;
    october = 31;
    november = 30;
    december = 31;
    int i = 1;
    if (dia > january)
    {
        dia = dia - january;
        i++;
    }
    else if (dia > february)
    {
        dia = dia - february;
        i++;
    }
    else if (dia > march)
    {
        dia = dia - march;
        i++;
    }
    else if (dia > april)
    {
        dia = dia - april;
        i++;
    }
    else if (dia > may)
    {
        dia = dia - may;
        i++;
    }
    else if (dia > june)
    {
        dia = dia - june;
        i++;
    }
    else if (dia > july)
    {
        dia = dia - july;
        i++;
    }
    else if (dia > august)
    {
        dia -= august;
        i++;
    }
    else if (dia > september)
    {
        dia -= september;
        i++;
    }
    else if (dia > october)
    {
        dia -= october;
        i++;
    }
    else if (dia > november)
    {
        dia -= november;
        i++;
    }
    printf("%d/%d/%d\n", dia, i, ano);
}