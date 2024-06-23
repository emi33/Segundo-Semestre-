//ingresa un array en minuscula y lo transforma a mayuscula
#include<stdio.h>
#include<conio.h>
int main() {
    char mayus[10];
    printf("escribe una palabra en minuscula");
    scanf("%s",&mayus);
    printf("palabra: %s", mayus);
    for (int i = 0; i < 10; i++)
    {
        mayus[i]=mayus[i]-32;
    }
    printf("palabra en MINUSCULA: %s",mayus);
    getch();
    return 0;
}