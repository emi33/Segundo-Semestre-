/*DiseNIar un programa modificando el ejemplo anterior que ingrese los datos correspondientes
a todos los alumnos de primer año de Programacion utilizando un arreglo de estructuras y
muestre un menú donde se puedan seleccionar estas distintas opciones:
(1)-Ingresar datos
(2)-Mostrar datos por alumno
(3)-estadísticas que muestren cantidad de
alumnos inscriptos, alumnos regulares, porcentaje de aprobacion,
promocionados por curso y ejecutar las operaciones de acuerdo a la opcion elegida.
CON 6 ESTAS REGULAR Y LUEGO RENDIR UN EXAMEN FINAL
ALUMNO PROMOCIONAL ES APROBAR TODO EL PROGRESO
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define AA 24
typedef struct 
{
    char cond;
    //struct nota notas;
} Condicion;
typedef struct 
{
    char nombre[20];
    char apellido[20];
    char curso[10];
    int dni;
    Condicion condicional;
} Alumno;
typedef struct 
{
    int cant;
    char nombre[10];
    Alumno alumnos[100];
} Curso;
typedef struct 
{
    char year;
    Curso cursos[20];
    int cantidad;
} Anio;
void bienvenida()
{
    printf("----------------------------------------------------------\n");
    printf("--------Bienvenido al programa Mis alumnos---------------\n");
    printf("---El programa simula una aplicacion para cargar alumnos--\n");
    printf("----------------------------------------------------------\n");
}
void menu() {
    printf("----------------------------------------------------------\n");
    printf("-------------------------Menu-----------------------------\n");
    printf("(1)-Ingresar datos\n");
    printf("(2)-Mostrar datos por alumno\n");
    printf("(3)-Estadisticas\n");
    printf("(4)-Salir\n");
    printf("----------------------------------------------------------\n");
}
void darAlumno(int cantidad, Anio *ciclo)
{
    int j, val;
    bool flag = true;

    for (int i = 0; i < cantidad; i++)
    {
        ciclo->cursos[i].cant = 0;
        printf("Ingrese nombre del curso: ");
        scanf("%s", &(ciclo->cursos[i].nombre));
        printf("%s: ", ciclo->cursos[i].nombre);
        j = 0;
        do {
            printf("Nombre del alumno del curso %s: ", ciclo->cursos[i].nombre);
            scanf("%s", &(ciclo->cursos[i].alumnos[j].nombre));
            printf("Apellido del alumno %d: ", i + 1);
            scanf("%s", &(ciclo->cursos[i].alumnos[j].apellido));
            printf("DNI del alumno %d: ", i + 1);
           
            scanf("%d", &(ciclo->cursos[i].alumnos[j].dni));
            printf("Condicion del alumno %d (R para Regular, A para Aprobado, P para Promocionado): ", j);
            scanf(" %c", &(ciclo->cursos[i].alumnos[j].condicional.cond));
            ciclo->cursos[i].cant++;
            printf("Ingrese 0 para dejar de agregar alumnos o cualquier otro numero para continuar: ");
            scanf("%d", &val);
            if (val == 0) {
                flag = false;
            }
            j++;
        }while (flag);
    }
    ciclo->cantidad = cantidad;
}
void mostrarDatos( Anio *ciclo)
{
    int val;
    printf("(1)-Buscar alumno\n");
    printf("(2)-Mostrar todos\n");
    printf("(3)-Salir\n");
    scanf("%d", &val);
    switch (val)
    {
    case 1:
    {
		int cursoIndex, alumnoIndex;
            printf("Ingrese el indice del curso: ");
            scanf("%d", &cursoIndex);
            printf("Ingrese el inndice del alumno: ");
            scanf("%d", &alumnoIndex);
            printf("Nombre: %s\n", ciclo->cursos[cursoIndex - 1].alumnos[alumnoIndex - 1].nombre);
            printf("Apellido: %s\n", ciclo->cursos[cursoIndex - 1].alumnos[alumnoIndex - 1].apellido);
            printf("DNI: %d\n", ciclo->cursos[cursoIndex - 1].alumnos[alumnoIndex - 1].dni);
            printf("Condicion: %c\n", ciclo->cursos[cursoIndex - 1].alumnos[alumnoIndex - 1].condicional.cond);
            break;
    }
    case 2:
    {
        for (int i = 0; i < ciclo->cantidad; i++) {
                for (int j = 0; j < ciclo->cursos[i].cant; j++) {
                    printf("Nombre: %s\n", ciclo->cursos[i].alumnos[j].nombre);
                    printf("Apellido: %s\n", ciclo->cursos[i].alumnos[j].apellido);
                    printf("DNI: %d\n", ciclo->cursos[i].alumnos[j].dni);
                    printf("Condicion: %c\n", ciclo->cursos[i].alumnos[j].condicional.cond);
                }
            }
            break;
    }
    case 3:
        return;
    default:
        printf("Opcion no valida\n");
        break;
    }
}
void estado(Anio *ciclo)
{
    int totalAlumnos = 0;
    int regulares = 0;
    int aprobados = 0;
    int promocionados = 0;
    for (int i = 0; i < ciclo->cantidad; i++)
    {
        for (int j = 0; j < ciclo->cursos[i].cant; j++)
        {
            totalAlumnos++;
            if (ciclo->cursos[i].alumnos[j].condicional.cond == 'R')
            {
                regulares++;
            }
            else if (ciclo->cursos[i].alumnos[j].condicional.cond == 'A')
            {
                aprobados++;
            }
            else if (ciclo->cursos[i].alumnos[j].condicional.cond == 'P')
            {
                promocionados++;
            }
        }
    }

    double porcentajeAprobados = (double)aprobados / totalAlumnos * 100;
    double porcentajePromocionados = (double)promocionados / totalAlumnos * 100;

    printf("Cantidad de alumnos inscriptos: %d\n", totalAlumnos);
    printf("Cantidad de alumnos regulares: %d\n", regulares);
    printf("Porcentaje de aprobacion: %.2f%%\n", porcentajeAprobados);
    printf("Porcentaje de promocionados: %.2f%%\n", porcentajePromocionados);
}
int main()
{
    bool flag = true;
    bool memoria = false;
    int val = 1, cantidad;
    Anio ciclo;
   
    bienvenida();
    do
    {
        menu();
        scanf("%d", &val);
        switch (val)
        {
        case 1:
             printf("Ingresar datos\n");

            if (memoria)
            {
                 printf("Ya no se pueden cargar mas alumnos\n");
            }
            else
            {
                ciclo.year = AA;
                    printf("Ingrese la cantidad de cursos: ");
                    scanf("%d", &cantidad);
                    darAlumno(cantidad, &ciclo);
            }
            break;
        case 2:
            printf("Mostrar datos\n");
                mostrarDatos(&ciclo);
            break;
        case 3:
            printf("estadisticas\n");
            estado(&ciclo);
            break;
		case 4:
			printf("Salir");
			flag=false;
        default:
            break;
        }

    } while (flag);

    return 0;
}
