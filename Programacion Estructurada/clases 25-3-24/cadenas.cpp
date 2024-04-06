#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char cadena[5]= "HOLA";
    char cadena2[6] = {'M','U','N','D','O', '\0'}; //debemos agregar el cero al final de la cadena
    int L= strlen(cadena2); //longitud de una cadena
    printf("%s\n",cadena2);
    printf("%d\n", L);
    //cadena + cadena2= 'HOLAMUNDO'
    strcat(cadena, " "); //concatenar cadenas
    strcat(cadena, cadena2);
    printf("%s\n", cadena);
    int longc= strlen(cadena);
    printf("%d\n", longc);

}