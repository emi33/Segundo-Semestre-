#include<stdio.h>
#include<string.h>
#include<conio.h>
#define LONGITUD 4
int main(){
    char contra[LONGITUD];
    int autenticado=0;
    printf("ingresa la contrasena: ");
    fgets(contra,LONGITUD,stdin);
    contra[strcspn(contra, "\n\r")]=0;
    if (strcmp(contra,"123")==0)
    {
        autenticado=1;
    }
    if (autenticado)
    {
        printf("bienvenido al programa");
    } else {
        printf("error al ingresar");
    }
    printf("despues de todo su auntenticacion es %d", autenticado);
    return 0;
}