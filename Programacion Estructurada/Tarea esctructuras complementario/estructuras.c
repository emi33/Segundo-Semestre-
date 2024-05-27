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
#include <stdbool.h>
#include <ctype.h>
#include <conio.h>
struct Condicion
{
    char cond; // aprobado, regular, noRegular, recursante, libre
    int notas[3];
    int final; // no cargado=0
    float promedio;
};
struct Materia
{
    char nombre[30];
    struct Condicion condiciones;
};
struct Alumno
{
    char nombre[20];
    char apellido[20];
    char dni[9];
    struct Materia materias[4];
};
int cantidad = 0;
const char cursos[4][30] = {"Programacion Estructurada", "Logica Matematica", "Comprension de Textos", "Arquitectura"};
void bienvenida()
{
    printf("----------------------------------------------------------\n");
    printf("--------Bienvenido al programa Mis alumnos---------------\n");
    printf("---El programa simula una aplicacion para cargar alumnos--\n");
    printf("----------------------------------------------------------\n");
}
void menu()
{
    printf("----------------------------------------------------------\n");
    printf("-------------------------Menu-----------------------------\n");
    printf("(1)-Ingresar datos\n");
    printf("(2)-Mostrar datos por alumno\n");
    printf("(3)-Estadisticas\n");
    printf("(4)-Salir\n");
    printf("----------------------------------------------------------\n");
}
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
            }
            else
            {
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
            printf("Ingrese un numero valido del 000 al 100: ");
        }
    }
    return nume;
}

void mostrarDatos(struct Alumno *alumnos)
{
    int val;
    printf("(1)-Buscar alumno\n");
    printf("(2)-Mostrar todos\n");
    printf("(3)-Salir\n");
    do
    {
        val = verificarnum();
        switch (val)
        {
        case 1:
        {
            int alumnoIndex;
            for (int n = 0; n < cantidad; n++)
            {
                printf("\n%d- %s %s", n + 1, alumnos[n].nombre, alumnos[n].apellido);
            }
            printf("selecciona un alumno: ");
            do
            {
                alumnoIndex = verificarnum() - 1;
                if (alumnoIndex <= cantidad)
                {
                    printf("\nNombre:%s %s", alumnos[alumnoIndex].nombre, alumnos[alumnoIndex].apellido);
                    printf("\nDni:%s", alumnos[alumnoIndex].dni);
                    for (int o = 0; o < 4; o++)
                    {
                        printf("\n%d- %s ", o, alumnos[alumnoIndex].materias[o].nombre);
                        printf("\nCondicion: %c ", alumnos[alumnoIndex].materias[o].condiciones.cond);
                        for (int p = 0; p < 3; p++)
                        {
                            printf("\nnota de parcial %d: %d ", p + 1, alumnos[alumnoIndex].materias[o].condiciones.notas[p]);
                        }
                        printf("\nPromedio: %f ", alumnos[alumnoIndex].materias[o].condiciones.promedio);
                        printf("\nNota final: %d ", alumnos[alumnoIndex].materias[o].condiciones.final);
                    }
                    break;
                }
                else
                {
                    printf("elige un numero valido");
                }
            } while (1);
            break;
        }
        case 2:
        {
            for (int q = 0; q < cantidad; q++)
            {
                printf("\nNombre:%s %s", alumnos[q].nombre, alumnos[q].apellido);
                printf("\nDni:%s", alumnos[q].dni);
                for (int j = 0; j < 4; j++)
                {
                    printf("\n%d- %s ", j + 1, alumnos[q].materias[j].nombre);
                    printf("\nCondicion: %c ", alumnos[q].materias[j].condiciones.cond);
                    for (int p = 0; p < 3; p++)
                    {
                        printf("\nnota de parcial %d: %d ", p + 1, alumnos[q].materias[j].condiciones.notas[p]);
                    }
                    printf("\nPromedio: %f ", alumnos[q].materias[j].condiciones.promedio);
                    printf("\nNota final: %d ", alumnos[q].materias[j].condiciones.final);
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
    } while (1);
}
void estado(struct Alumno *alumnos)
{
    int totalAlumnos = 0;
    int regulares = 0;
    int aprobados = 0;
    int promocionados = 0;
    int libres = 0;
    for (int i = 0; i < cantidad; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            
            if (alumnos[i].materias[j].condiciones.cond == 'R')
            {
                regulares++;
            }
            else if (alumnos[i].materias[j].condiciones.cond == 'A')
            {
                aprobados++;
            }
            else if (alumnos[i].materias[j].condiciones.cond == 'P')
            {
                promocionados++;
            }
            else if (alumnos[i].materias[j].condiciones.cond == 'L')
            {
                libres++;
            }
        }
		totalAlumnos=cantidad;
        double porcentajeAprobados = (double)aprobados / totalAlumnos * 100;
        double porcentajePromocionados = (double)promocionados / totalAlumnos * 100;

        printf("Cantidad de alumnos inscriptos: %d\n", totalAlumnos);
        printf("Cantidad de alumnos regulares: %d\n", regulares);
        printf("Porcentaje de aprobacion: %.2f%%\n", porcentajeAprobados);
        printf("Porcentaje de promocionados: %.2f%%\n", porcentajePromocionados);
    }
}
int main()
{
    bool flag = true;
    bool memoria = false;
    int val = 1;
    int j=0, parcial;
    char nomb[20], ape[20], dni[9];
    struct Alumno alumnos[100];
    bienvenida();
    do
    {
        menu();
		val=verificarnum();
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
               
                for (int i = 0; i < 100; i++)
                {
					printf("Cargar alumno %d: \n", i + 1);
					cantidad = i + 1;
                    printf("Nombre del alumno %d: ", i + 1);
                    fgets(nomb, 20, stdin);
                    nomb[strcspn(nomb, "\r\n")] = 0;
                    strcpy(alumnos[i].nombre, nomb);
                    printf("Apellido del alumno %d: ", i + 1);
                    fgets(ape, 20, stdin);
                    ape[strcspn(ape, "\r\n")] = 0;
                    strcpy(alumnos[i].apellido, ape);
                    printf("DNI del alumno %d: ", i + 1);
                    fgets(dni, 20, stdin);
                    dni[strcspn(dni, "\r\n")] = 0;
                    strcpy(alumnos[i].apellido, dni); // crean switch para dni
                    printf("Cargar materias de alumno %d: ", i + 1);
                    char temp[4][30];
                    for (int k = 0; k < 4; k++)
                    {
                        strcpy(temp[k], cursos[k]);
                    }

                    int mats = 4;
                    int seleccion;
                    int suma, multi;
                    while (mats > 0)
                    {
                        printf("Materias disponibles:\n");
                        for (int l = 0; l < 4; l++)
                        {
                            printf("%d. %s\n", l + 1, temp[l]);
                        }
                        printf("Seleccione una materia para eliminar (1-4):"); //%d, MATSELECT
                        seleccion = verificarnum();

                        if (seleccion < 1 || seleccion > 4 || temp[seleccion - 1][0] == 'x')
                        {
                            printf("Seleccion invalida. Intente de nuevo.\n");
                        }
                        else
                        {
                            printf("Eliminando materia: %s\n", temp[seleccion-1]);
							char algo[30];
							strcpy(algo, temp[seleccion-1]);
                            strcpy(alumnos[i].materias[j].nombre, algo);
                            temp[seleccion - 1][0] = 'x'; // Eliminar la materia poniendo el primer carácter a 'x',  modificar para que se modifique el ultimo char
                            printf("Condiciones del alumno");
                            suma = 0;
                            multi = 1;
                            for (int m = 0; m < 3; m++)
                            {
                                printf("Ingrese nota %d(si aun no rindio examen, coloque 0): ", m + 1);
                                parcial = verificarnum();
                                alumnos[i].materias[j].condiciones.notas[m] = parcial;
                                suma = suma + parcial;
                                multi = multi * parcial;
                            }
                            alumnos[i].materias[j].condiciones.promedio = (float)suma / 3;
                            float promedio = alumnos[i].materias[j].condiciones.promedio;

                            if (promedio > 70 && multi != 0)
                            {
                                printf("Ingrese nota final(si aun no rinde ingrese 0): ");
                                parcial = verificarnum();
                                alumnos[i].materias[j].condiciones.final = parcial;
                                if (alumnos[i].materias[j].condiciones.final > 70)
                                {
                                    alumnos[i].materias[j].condiciones.cond = 'A';
                                }
                                else if (alumnos[i].materias[j].condiciones.final < 70 && alumnos[i].materias[j].condiciones.final >= 0)
                                {
                                    alumnos[i].materias[j].condiciones.cond = 'R';
                                }
                            }
                            else if (promedio < 70 && promedio >= 0)
                            {
                                alumnos[i].materias[j].condiciones.final = 0;
                                alumnos[i].materias[j].condiciones.cond = 'L';
                            }
                            else if (multi == 0 && promedio == 0)
                            {
                                parcial = verificarnum();
                                alumnos[i].materias[j].condiciones.final = parcial;
                                if (alumnos[i].materias[j].condiciones.final > 70)
                                {
                                    alumnos[i].materias[j].condiciones.cond = 'P';
                                }
                                else
                                {
                                    alumnos[i].materias[j].condiciones.cond = 'L';
                                }
                            }
                            mats--;
                        }
						j++;
                        printf("\n");
                    }
                    printf("\nIngrese 0 para dejar de agregar alumnos o cualquier otro numero para continuar: ");
                    val = verificarnum();
                    if (val == 0)
                    {
                       
                        break;
                    }
						
                }
            }
            break;
        case 2:
            printf("Mostrar datos\n");
            mostrarDatos(alumnos);
            break;
        case 3:
            printf("estadisticas\n");
            estado(alumnos);
            break;
        case 4:
            printf("Salir");
            flag = false;
        default:
            break;
        }

    } while (flag);
    getch();
    return 0;
}
