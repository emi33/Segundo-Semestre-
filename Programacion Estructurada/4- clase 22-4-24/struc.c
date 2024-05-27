#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <ctype.h>
struct alumno
{
    char nombre[25];
    char apellido[25];
    int edad;
    int notas[4];
    float promedio;
};
int verificarnum()
{
    char note[10]; // Increase size to handle extra input
    int nume, suma, temp;
    bool valid = false;
    while (!valid)
    {
        fgets(note, 10, stdin);
        note[strcspn(note, "\r\n")] = 0; // Remove newline character
        suma = 0;
        temp = 0;

        for (int l = 0; l < strlen(note); l++)
        {
            if (isdigit(note[l]))
            {
                suma++;
            }else{
                temp++;
            }
        }
        // 23, 2
        if (temp == 0 && sscanf(note, "%d", &nume) == 1 && nume >= 0 && nume <= 100)
        {
            valid = true;
        }
        else
        {
            printf("Ingrese un número válido del 000 al 100: ");
        }
    }
    return nume;
}
int main()
{
    int suma, i = 0, nume;
    char c;
    struct alumno a[100];
    char notes[3];
    do
    {
        printf("Ingrese nombre: ");
        fgets(a[i].nombre, 25, stdin);
        a[i].nombre[strcspn(a[i].nombre, "\r\n")] = 0;

        printf("Ingrese apellido: ");
        fgets(a[i].apellido, 25, stdin);
        a[i].apellido[strcspn(a[i].apellido, "\r\n")] = 0;

        printf("Ingrese edad: ");
        nume = verificarnum();
        a[i].edad = nume;

        printf("Promedio: \n");
        suma = 0;
        for (int j = 0; j < 4; j++)
        {
            printf("Ingrese nota %d: ", j + 1);
            nume = verificarnum();
            a[i].notas[j] = nume;
            suma = suma + a[i].notas[j];
        }

        a[i].promedio = (float)suma / 4;

        printf("\n¿Agregar otro usuario? (s/n): ");
        scanf(" %c", &c);
        while ((getchar()) != '\n')
            ;
        if (c == 'n')
        {
            break;
        }

        i++;
    } while (1);

    printf("\nTodos los datos: ");
    for (int k = 0; k <= i; k++)
    {

        printf("\nNombre: %s %s\nEdad: %d\nPromedio: %.2f\n", a[k].nombre, a[k].apellido, a[k].edad, a[k].promedio);
        if (a[k].nombre == NULL)
        {
            break;
        }
    }
    getch();
    return 0;
}