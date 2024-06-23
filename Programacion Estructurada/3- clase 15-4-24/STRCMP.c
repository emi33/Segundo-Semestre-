//usar strcmp, escribir dos cadenas. determinar si son iguales, mayores o menores;
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main(){
    char cadena1[10];
    char cadena2[10];
    printf("escriba la cadena 1: ");
    scanf("%s", &cadena1);
    printf("escriba la cadena 2: ");
    scanf("%s", &cadena2);
    int val=strcmp(cadena1,cadena2);
    if( val < 0 )  {
		printf( "%s menor que %s",cadena1,cadena2 );
	}
	else if( val > 0 )  {
		printf( "%s mayor que %s",cadena1,cadena2 );
	}
	else  {
		printf( "%s igual a %s",cadena1,cadena2 );
	}
    getch();
    return 0;
}