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
    struct alumno estudiantes[2];

    for (int j = 0; j < 2; j++) 
    {
        int suma = 0;

        printf("Nombre del alumno %d: ", j + 1);
        fgets(estudiantes[j].nombre, sizeof(estudiantes[j].nombre), stdin);
        estudiantes[j].nombre[strcspn(estudiantes[j].nombre, "\n")] = '\0';

        printf("Apellido del alumno %d: ", j + 1);
        fgets(estudiantes[j].apellido, sizeof(estudiantes[j].apellido), stdin);
        estudiantes[j].apellido[strcspn(estudiantes[j].apellido, "\n")] = '\0';

        printf("Edad del alumno %d: ", j + 1);
        scanf("%d", &estudiantes[j].edad);

        printf("Notas del alumno %d:\n", j + 1);
        for (int i = 0; i < 4; i++)
        {
            printf("Ingrese nota %d: ", i + 1);
            scanf("%d", &estudiantes[j].notas[i]);
            suma = suma + estudiantes[j].notas[i];
        }

        estudiantes[j].promedio = (float)suma / 4; 
        getchar(); 
    }

    printf("\nDatos Ingresados:\n");
    for (int j = 0; j < 2; j++)
    {
        printf("\nAlumno %d:\n", j + 1);
        printf("Nombre: %s %s\n", estudiantes[j].nombre, estudiantes[j].apellido);
        printf("Edad: %d\n", estudiantes[j].edad);
        printf("Promedio: %.2f\n", estudiantes[j].promedio);
    }

    char op[20];
    printf("\nNombre Alumno:\n");
    scanf("%s", op);

    for (int j = 0; j < 2; j++){

        if (strcmp(op,estudiantes[j].nombre) == 0)
        {
            printf("\nAlumno %d:\n", j+1);
            printf("Nombre: %s %s\n", estudiantes[j].nombre, estudiantes[j].apellido);
            printf("Edad: %d\n", estudiantes[j].edad);
            printf("Promedio: %.2f\n", estudiantes[j].promedio);
        }
    }

    return 0;
}
