#include <stdio.h>
#include <conio.h>
#include <string.h>

#define LONGITUD 10
int programa()
{
    FILE *v;
    v = fopen("vocales.txt", "w+");
    char cad[200];
    int x;
    // fopen devuelve un puntero y lo tengo que guardar en un tipo puntero.
    if (v == NULL)
    {
        printf("Error");
        return 1;
    }
    printf("escribir algo(si escribe 1 el programa se :");
    do
    {
        fgets(cad, 200, stdin);
        cad[strcspn(cad, "\r\n")] = 0;
        
        fputs(cad, v);
        if (cad=="1"){
            break;
        }
    } while (1);
    fclose(v);
    fopen("vocales.txt","r");

    if (v == NULL)
    {
        printf("Error");
        return 1;
    }
    rewind(v);
     int suma = 0;
    do
    {
        // Taking input single character at a time
        char c = fgetc(v);
       
        if (c==65 || c==69 || c==73 || c==79 || c==85 || c==97 || c==101 || c==105 || c==111 || c==117){
            suma++;
        }
        // Checking for end of file
        if (feof(v)){
            break;
        }
        printf("%c", c);
    } while (1);
    printf("\n suma: %d", suma);
    fclose(v);
    getch();
    return 0;
}
int main()
{
    // ingresar usuario
    char user[] = "emiliano";
    char password[] = "123456789";
    char cadena[LONGITUD];
    int autenticado = 0;
    printf("Ingresa la contraseña:\n");

    fgets(cadena, LONGITUD, stdin);
    cadena[strcspn(cadena, "\r\n")] = 0;

    if (strcmp(cadena, password) == 0)
    {
        autenticado = 1;
    }
    if (autenticado)
    {
        printf("Bienvenido al programa %s \n", user);
        programa();
    }
    else
    {
        printf("Acceso denegado");
    }

    return 0;
}