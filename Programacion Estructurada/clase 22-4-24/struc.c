#include <stdio.h>
#include <string.h>

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
    int suma = 0;

    struct alumno a;
    printf("Ingrese nombre: ");
    fgets(a.nombre, sizeof(a.nombre), stdin);
    a.nombre[strcspn(a.nombre, "\n")] = '\0';

    printf("Ingrese apellido: ");
    fgets(a.apellido, sizeof(a.apellido), stdin);
    a.apellido[strcspn(a.apellido, "\n")] = '\0';

    printf("Ingrese edad: ");
    scanf("%d", &a.edad);

    printf("Promedio: \n");

    for (int i = 0; i < 4; i++)
    {
        printf("Ingrese nota %d: ", i + 1);
        scanf("%d", &a.notas[i]);
        suma = suma + a.notas[i];
    }

    a.promedio = (float)suma / 4; 

    printf("\nDatos Ingresados: ");
    printf("\nNombre: %s %s\nEdad: %d\nPromedio: %.2f\n", a.nombre, a.apellido, a.edad, a.promedio); 
    return 0;
}


