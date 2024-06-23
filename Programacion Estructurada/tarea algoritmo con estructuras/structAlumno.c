/*Crear código que use estructuras anidadas para cargar datos
de alumnos, materias y sus notas. Mostrar todos los datos
cargados y también el promedio general de  cada alumno.
Se Deberán crea tres estructuras: Nota, Materias y Alumnos.
En la estructura Alumnos, uno de sus miembros debe ser
una estructura de tipo Materias. Dentro de los miembros
de la estructura Materias debe haber una estructura de tipo
Nota que permita cargar un nro variable de notas para una
materia (o sea debería ser un vector). Por ejemplo si elije
3 notas por materia debería cargar 3 notas para matematica,
3 notas para física y así hasta completar el nro elegido
de materias. La estructura Nota solo tiene un miembro
llamado valor.*/
#define MAX_ALUMNS 100
#define MAX_ASSIGNS 20
#define MAX_GRADES 10
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
struct Nota
{
    int valor[10];
};
struct Materia
{
    char asignatura[20];
    struct Nota notas;
};

struct Alumno
{
    char nombre[25];
    char apellido[25];
    char dni[8];
    struct Materia materias[MAX_ASSIGNS];
};


void cargarMateria(char materiaslocal[5][20], char auxmateria[20], char c[6])
{
    
    int valor;
    bool booleano;
    printf("materias: \n");
    for (int k = 0; k < 5; k++)
    {
        printf("%d- %s%c\n", k + 1, materiaslocal[k], c[k]);
    }
    do
    {
        booleano=true;
        printf("Elige una materia(no marcada con x): ");
        scanf("%d", &valor);
        if (c[valor-1] == ' ')
        {
            strcpy(auxmateria, materiaslocal[valor-1]);
            c[valor-1] = 'x';
            booleano=false;
        }
        else
        {
            printf("Elige otra vez\n");
        }
    } while (booleano);
};
int cantidadalumnos, cantidadmaterias, cantidadnotas[100][20];


int main()
{
    char nombrelocal[25];
    char materiaslocal[5][20] = {{"Programacion"}, {"Algebra"}, {"Estadistica"}, {"Arquitectura"}, {"Sistemas"}};
    char c[6]={' ',' ',' ',' ',' '};
    char auxmateria[20];
    int suma=0;
    double promedio[100][20];
    printf("Define la cantidad de alumnos: ");
    scanf("%d", &cantidadalumnos);
    printf("Defina la cantidad de materias: ");
    scanf("%d", &cantidadmaterias);

    printf("alumnos: %d y materias: %d\n", cantidadalumnos, cantidadmaterias);
    // CREAR WHILE PARA VERIFICAR QUE NO SEA MAYOR A MAX_ALUMNOS Y MAX_ASSIGNS
    // CREAR FUNCION PARA VERIFICAR NUMEROS
    struct Alumno alumnos[cantidadalumnos];
    for (int i = 0; i < cantidadalumnos; i++)
    {
        while (getchar() != '\n');
        printf("INGRESANDO DATOS DEL ALUMNO %d\n", i + 1);
        printf("nombre: ");
        fgets(alumnos[i].nombre, 25, stdin);
        alumnos[i].nombre[strcspn(alumnos[i].nombre, "\r\n")] = 0;
        printf("apellido: ");
        fgets(alumnos[i].apellido, 25, stdin);
        alumnos[i].apellido[strcspn(alumnos[i].apellido, "\r\n")] = 0;
        printf("dni: ");
        fgets(alumnos[i].dni, 8, stdin);
        alumnos[i].dni[strcspn(alumnos[i].dni, "\r\n")] = 0;
        strcpy(c, "     ");  // Reset the 'c' array
        for (int j = 0; j < cantidadmaterias; j++) {
            suma=0;
            printf("INGRESANDO DATOS DE MATERIA %d: ", j + 1);
            cargarMateria(materiaslocal, auxmateria, c);
            strcpy(alumnos[i].materias[j].asignatura, auxmateria);
            printf("cantidad de notas de materia %s: ", auxmateria);
            scanf("%d", &cantidadnotas[i][j]);
            while(getchar()!='\n');
            for (int n = 0; n < cantidadnotas[i][j]; n++)
            {
                int notita;
                
                printf("INGRESE NOTA %d: ", n+1);
                scanf("%d", &notita);
                if ((j+1<cantidadmaterias))
                {
                    while(getchar()!='\n');
                }
                alumnos[i].materias[j].notas.valor[n]=notita;
                suma+=alumnos[i].materias[j].notas.valor[n];
            }
            promedio[i][j]= (double) suma/cantidadnotas[i][j];
        }
    }
    printf("Alumnos:\n");
    for (int j = 0; j < cantidadalumnos; j++)
    {
        printf("    Alumno %d\n", j + 1);
        printf("        Nombre: %s\n", alumnos[j].nombre);
        printf("        Apellido: %s\n", alumnos[j].apellido);
        printf("        DNI: %s\n", alumnos[j].dni);
        printf("        Materias\n");
        for (int l = 0; l < cantidadmaterias; l++)
        {
            printf("            Materia %d: \n",l+1);
            printf("                Asignatura: %s\n", alumnos[j].materias[l].asignatura);
            printf("cantidad notas: %d\n", cantidadnotas[j][l]);
            for (int m = 0; m < cantidadnotas[j][l]; m++)
            {
                printf("                Nota %d: %d\n", m+1, alumnos[j].materias[l].notas.valor[m]);
            }
            printf("                Promedio: %.2f\n", promedio[j][l]);         
        }   
    }
    getch();
    return 0;
}
