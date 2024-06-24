/*Adjunte un archivo  binario con los siguientes datos:
Cod_Alu: tipo int, código del alumno que será igual a su DNI
Ape_Alu: tipo char; contiene el  apellido del alumno
Fecha: tipo int,  fecha en que se ingresa el dato en el archivo. El formato deberá ser el siguiente: DDMMAA
El nombre del archivo debe ser "egi.dat"
Deberá usar una estructura de datos (struct) para resolver dicho ejercicio.*/
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
struct Alumno{
    int Cod_Alu;
    char Ape_Alu[10];
    int Fecha;
};

int main(){

    FILE *dat;
    dat=fopen("egi.dat","wb");
    struct Alumno estudiante;
    estudiante.Cod_Alu=42209888;
    strcpy(estudiante.Ape_Alu,"Choque");
    estudiante.Fecha=240624;
    if (dat==NULL)
    {
        return 0;
    }
    fwrite(&estudiante, sizeof(estudiante),1,dat);
    fclose(dat);
   //leer estructura ingresada
    dat=fopen("egi.dat","rb");
    if (dat==NULL)
    {
        return 0;
    }
    while (fread(&estudiante, sizeof(estudiante), 1, dat)) {
        printf("%i %s %i\n", estudiante.Cod_Alu, estudiante.Ape_Alu, estudiante.Fecha);
    }
    
    fclose(dat);
    getch();
    return 0;
}