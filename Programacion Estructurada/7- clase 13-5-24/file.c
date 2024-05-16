#include<stdio.h>
#include <conio.h>

int main(){
    //LEER
    FILE *archivo;
    char texto[100];
    archivo= fopen("datos.txt", "r"); // r= modo de apertura, datos.txt = nombre del archivo
    // fopen devuelve un puntero y lo tengo que guardar en un tipo puntero.
    if (archivo == NULL)
    {
        printf("Error");
        return 1;
    }
    fgets(texto, 100, archivo); //si es por teclado se escribre fgets(texto,100, stdin);
    printf("el contenido es: %s", texto);
    fclose(archivo); //buena practica cerrar archivos
    //FUNCIONES CONOCIDAS: fprintf fscanf swrite frcad
    //funcion fputs
    FILE *a;
    a= fopen("datos2.txt", "w+"); // r= modo de apertura, datos.txt = nombre del archivo
    // fopen devuelve un puntero y lo tengo que guardar en un tipo puntero.
    if (a == NULL)
    {
        printf("Error");
        return 1;
    }
    fputs("Hello World!\n", a);
    fputs("segunda linea\n", a);
    fputs("tercera linea\n", a);
    rewind(a);
    char linea[100];
    // printf("\n el contenido escrito es: %s", tex); //error ARREGLAR!!
    fgets(linea, 100,a);
    while (!feof(a)){ //end of file
        printf(linea);
        fgets(linea, 100, a);
    }
    fclose(a);
    getch();
    return 0;
}