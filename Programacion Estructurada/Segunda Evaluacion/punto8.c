/*Escriba código en c  para que 
cuente las líneas de un archivo 
de texto. Suponga que ya ha sido 
creado y que existe en la carpeta 
adecuada. Use la función fgetc.*/
#include<stdio.h>
#include<conio.h>
int main(){
    FILE *archivo;
    int i=1;
    archivo= fopen("prueba.txt", "r");
    //char c=fgetc(archivo);
    //printf("%c",c);
    do
    {
        char c=fgetc(archivo);
        if (c=='\n')
        {
            i++;
        }
        
       if (!feof(archivo)==0)
       {
        printf("fin del texto.");
        break;
       }
       
    } while (1);
    
    printf("cantidad de lineas: %d", i);
    fclose(archivo);
    getch();
    return 0;
}