#include <stdio.h>
#include <string.h>
#include <conio.h>
// UN PROGRAMA QUE SIMULE EL FUNCIONAMIENTO DE STRCMP es decir, debe devolver un int mayor menor o igual a 0
int mistrcmp(char cadena1[10], char cadena2[10])
{
    int value = 0, suma1 = 0, suma2 = 0;
    for (int i = 0; i < 10; i++)
    {
        if (cadena1[i] && cadena2[i])
        {
            suma1 += cadena1[i];
            suma2 += cadena2[i];
        }
    }
    value = suma1 - suma2;

    return value;
}
int main()
{
    char cadena1[10];
    char cadena2[10];
    printf("escriba la cadena 1: ");
    scanf("%s", &cadena1);
    printf("escriba la cadena 2: ");
    scanf("%s", &cadena2);
    int val = mistrcmp(cadena1, cadena2);
    if (val < 0)
    {
        printf("%s menor que %s", cadena1, cadena2);
    }
    else if (val > 0)
    {
        printf("%s mayor que %s", cadena1, cadena2);
    }
    else
    {
        printf("%s igual a %s", cadena1, cadena2);
    }
    getch();
}