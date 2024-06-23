#include <stdio.h>
#include <string.h>
#define LONGITUD 4
#include <iostream>
int main()
{
  char cadena[LONGITUD];
  int autenticado = 0; // 1 es que sí, 0 que no
  printf("Ingresa la contrase�a:\n");
  fgets(cadena, LONGITUD, stdin);
  cadena[strcspn(cadena, "\r\n")] = 0;
  if (strcmp(cadena, "123") == 0)
  {
    autenticado = 1;
  }
  if (autenticado)
  {
    printf("Bienvenido al programa");
    std::cout << cadena << std::endl;
  }
  else
  {
    printf("Acceso denegado");
    std::cout << cadena << std::endl;
  }
  printf("\nAl final de todo, el valor que tiene 'autenticado' es: %d", autenticado);
}
