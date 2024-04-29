#include <stdio.h>
#include <string.h>
#define MAX_ALUMNOS 50

#define MAX_MATERIAS 5

#define MAX_NOTAS 3

// Definición de la estructura Nota

typedef struct
{
    float valor;
} Nota;

// Definición de la estructura Materia

typedef struct
{
    char nombre[50];
    Nota notas[MAX_NOTAS];
} Materia;

// Definición de la estructura Alumno

typedef struct
{
    char nombre[50];
    int edad;
    Materia materias[MAX_MATERIAS];
} Alumno;

int main()
{
    Alumno alumnos[MAX_ALUMNOS];
    // Ejemplo de inicialización de alumnos, materias y notas
    strcpy(alumnos[0].nombre, "Juan");
    alumnos[0].edad = 20;
    strcpy(alumnos[0].materias[0].nombre, "Matemáticas");
    alumnos[0].materias[0].notas[0].valor = 7.5;
    alumnos[0].materias[0].notas[1].valor = 8.0;
    alumnos[0].materias[0].notas[2].valor = 6.5;
    strcpy(alumnos[0].materias[1].nombre, "Ciencias");
    alumnos[0].materias[1].notas[0].valor = 6.0;
    alumnos[0].materias[1].notas[1].valor = 7.0;
    alumnos[0].materias[1].notas[2].valor = 8.0;
    strcpy(alumnos[1].nombre, "Maria");
    alumnos[1].edad = 22;
    strcpy(alumnos[1].materias[0].nombre, "Matemáticas");
    alumnos[1].materias[0].notas[0].valor = 8.0;
    alumnos[1].materias[0].notas[1].valor = 9.0;
    alumnos[1].materias[0].notas[2].valor = 7.5;
    strcpy(alumnos[1].materias[1].nombre, "Ciencias");
    alumnos[1].materias[1].notas[0].valor = 7.0;
    alumnos[1].materias[1].notas[1].valor = 8.0;
    alumnos[1].materias[1].notas[2].valor = 9.0;
    // Mostrar la información de los alumnos, materias y notas
    for (int i = 0; i < 2; i++)
    {
        printf("Alumno: %s\n", alumnos[i].nombre);
        printf("Edad: %d\n", alumnos[i].edad);
        printf("Materias:\n");
        for (int j = 0; j < MAX_MATERIAS; j++)
        {
            printf("  %s:\n", alumnos[i].materias[j].nombre);
            printf("    Notas:\n");
            for (int k = 0; k < MAX_NOTAS; k++)
            {
                printf("      Nota %d: %.2f\n", k + 1, alumnos[i].materias[j].notas[k].valor);
            }
        }
        printf("\n");
    }
    return 0;
}