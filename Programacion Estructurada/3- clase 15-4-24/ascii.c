//escribir una letra minuscula o mayuscula y te devuelve su valor en ascii
#include<stdio.h>
#include<conio.h>
int main(){
    char letra;
    printf("escribe una letra: ");
    scanf("%c",&letra);
    for (int i = 65; i < 91; i++)
    {
        if (letra==i)
        {
            printf("letra correcta posicion: %d", i);
        }
    }
    for (int i = 97; i< 123; i++)
    {
        if (letra==i)
        {
            printf("letra correcta posicion: %d", i);
        }
    }
    getch();
    return 0;
}