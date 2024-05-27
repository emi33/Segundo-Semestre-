#include <stdio.h>
#include <string.h>
#include <conio.h>
struct alumno
{
    char nombre[50];
    char apellido[50];
    int edad;
    int notas[4];
    float promedio;
};

int main()
{
    int suma = 0, i = 0;
    char c;
    struct alumno a[100];
    do
    {
        printf("Ingrese nombre: ");
        fgets(a[i].nombre, sizeof(a[i].nombre), stdin);
        a[i].nombre[strcspn(a[i].nombre, "\n")] = '\0';

        printf("Ingrese apellido: ");
        fgets(a[i].apellido, sizeof(a[i].apellido), stdin);
        a[i].apellido[strcspn(a[i].apellido, "\n")] = '\0';

        printf("Ingrese edad: ");
        scanf("%d", &a[i].edad);

        printf("Promedio: \n");

        for (int j = 0; j < 4; j++)
        {
            printf("Ingrese nota %d: ", j + 1);
            scanf("%d", &a[i].notas[j]);
            suma = suma + a[i].notas[j];
        }

        a[i].promedio = (float)suma / 4;

          while ((c = getchar()) != '\n' && c != EOF);

        printf("\n¿Agregar otro usuario? (s/n): ");
       scanf("%c",&c);

        if (c == 'n')
        {
            break;
        }

         i++;
    } while (1);

    for (int i = 0; i < 100; i++)
    {
        printf("\nTodos los datos: ");
        printf("\nNombre: %s %s\nEdad: %d\nPromedio: %.2f\n", a[i].nombre, a[i].apellido, a[i].edad, a[i].promedio);
        if (a[i].nombre == NULL)
        {
            break;
        }
    }
    getch();
    return 0;
}
