#include <stdio.h>

#define LONGITUD 4



int main() {

 char cadena[LONGITUD];

 int autenticado = 0; // 1 es que sÃ­, 0 que no

 printf("Ingresa la contraseña:\n");

 fgets(cadena, LONGITUD, stdin); 

 cadena[strcspn(cadena, "\r\n")] = 0;

  if (strcmp(cadena, "123") == 0) {

  autenticado = 1;

 }

 if (autenticado)

   printf("Bienvenido al programa");

 else

   printf("Acceso denegado");

 printf("\nAl final de todo, el valor que tiene 'autenticado' es: %d", autenticado);

}
