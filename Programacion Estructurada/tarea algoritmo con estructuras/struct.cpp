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
#include <iostream>
#include <cstring>
#include <limits>
#include <string>
#define MAX_ALUMNS 60
#define MAX_NAME_SUBJ 20
#define MAX_GRADES 15
#define MAX_SUBJECTS 30
#define MAX_NAME_LENGTH 25
using namespace std;
void menu()
{
    cout << "------------------------------------------------------------------------------------\n"
         << "-------------------------Bienvenido al programa Mis alumnos-------------------------\n"
         << "------El programa simula una aplicacion para cargar notas, materias y alumnos-------\n"
         << "-Debe cargar la cantidad de notas, la cantidad de materias y la cantidad de alumnos-\n"
         << "-----------------Luego, carga los datos necesarios para cada alumno-----------------\n"
         //<< "-----Recuerde que puede volver para atras si cree que se equivoco en algun dato-----\n"
         << "------------------------------------------------------------------------------------\n";
}
int* cantidades()
{
    bool flag;
    int aux = MAX_ALUMNS;
    int *cantidades = new int[3];
    char estructuras[3][10] = {"alumnos", "materias", "notas"};
    for (int i = 0; i < 3; i++)
    {
        flag = true;
        int a;
        do
        {
            cout << "digite su cantidad de " << estructuras[i] << "(menor que " << aux << "): ";
            cin >> a;
            if (a < aux && a > 0)
            {
                cantidades[i] = a;
                flag = false;
            }
            else
            {
                cout << "Entrada no valida. Intente de nuevo." << endl;
            }
        } while (flag);
        aux = aux / 2;
    }
 
    return cantidades;
}
char** asignaturas(int mat)
{
    char **asignaturas = new char *[mat];
    cin.ignore();
    for (int i = 0; i < mat; i++)
    {
        //fflush(stdin);
        asignaturas[i] = new char[MAX_NAME_SUBJ];
        cout << "Ingresa la materia " << i + 1 << ":\n";
        cin.getline(asignaturas[i], 25);
    }
    return asignaturas;
}
// estructura notas
struct nota
{
    int valor;
};
// estructura materias
struct materia
{
    char nombre[MAX_NAME_SUBJ];
    struct nota notas[MAX_GRADES];
};
// estructura alumnos
struct alumno
{
    char *nombre;
    char *apellido;
    int edad;
    int dni;
    struct materia materias[MAX_SUBJECTS];
};
int main()
{
    // bienvenida al programa y descripcion de como funciona
    menu();
    system("pause");
    // cargar cantidad de alumnos, materias y notas
    int *valores = cantidades();
    // mostrar cantidad alumnos, materias notas;
    cout << "cantidad alumnos, materias y notas en ese orden\n";
    for (int i = 0; i < 3; i++)
    {
        cout << valores[i] << "\n";
    }
    // cargar todas las materias
    char **temp = asignaturas(valores[1]);
    //  Mostrar las materias almacenadas en temp
    for (int i = 0; i < valores[1]; ++i)
    {
        cout << "Materia " << i + 1 << ": " << temp[i] << endl;
    }
    // boton de recargar en caso de error(pendiente)

    // cargar alumno y sus notas
    alumno alumnos[MAX_ALUMNS];
    for (int i = 0; i < valores[0]; i++)
    {
        fflush(stdin);
        alumnos[i].nombre = new char[MAX_NAME_LENGTH];
        printf("Nombre del alumno %d: ", i + 1);
        cin.getline(alumnos[i].nombre, MAX_NAME_LENGTH);

        alumnos[i].apellido = new char[MAX_NAME_LENGTH];
        printf("Apellido del alumno %d: ", i + 1);
        cin.getline(alumnos[i].apellido, MAX_NAME_LENGTH);

        printf("Edad del alumno %d: ", i + 1);
        cin >> alumnos[i].edad;
        printf("DNI del alumno %d: ", i + 1);
        cin >> alumnos[i].dni;
        for (int j = 0; j < valores[1]; j++)
        {
            fflush(stdin);
            strcpy(alumnos[i].materias[j].nombre, temp[j]);
            printf("Materia %s: ", alumnos[i].materias[j].nombre);
            printf("Notas del alumno %s %s:\n", alumnos[i].nombre, alumnos[i].apellido);
            for (int k = 0; k < valores[2]; k++)
            {
                fflush(stdin);
                cout << "Ingrese nota " << k + 1 << ": ";
                cin >> alumnos[i].materias[j].notas[k].valor;
            }
        }
    }
    // mostrar todos los alumnos, notas de cada materia
    for (int i = 0; i < valores[0]; i++)
    {
        cout << "Alumno " << i + 1 << ":\n"
             << "   Nombre: " << alumnos[i].nombre << "\n"
             << "   Apellido: " << alumnos[i].apellido << "\n"
             << "   Edad: " << alumnos[i].edad << "\n"
             << "   DNI: " << alumnos[i].dni << "\n";
        for (int j = 0; j < valores[1]; j++)
        {
            cout << "   Materia: " << j + 1 << ":\n "
                 << "      Asignatura: " << alumnos[i].materias[j].nombre << "\n";
            for (int k = 0; k < valores[2]; k++)
            {
                cout << "         Nota " << k + 1 << ": " << alumnos[i].materias[j].notas[k].valor << "\n";
            }
        }
    }

    // Deallocate memory
    for (int i = 0; i < valores[0]; ++i)
    {
        delete[] alumnos[i].nombre;
        delete[] alumnos[i].apellido;
    }
    for (int i = 0; i < valores[1]; ++i)
    {
        delete[] temp[i];
    }
    
    delete[] valores;
    delete[] temp;

    // mostrar solo nombre de alumnos
    // elegir un alumno y mostra sus datos
    //  finalizar con boton de cancelar y reiniciar con boton de reiniciar
    system("pause");
    return 0;
}