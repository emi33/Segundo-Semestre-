//concatenar cadena hola y mundo
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main() {
    char cadena[5]={'H','O','L','A','\0'};
    char cadena2[6]={'m','u','n','d','o'};
    char cadena3[12];
    strcpy(cadena3, cadena);
    strcat(cadena3," ");
    strcat(cadena3,cadena2);
    
    printf("%s", cadena3);
    getch();
    return 0;
}