#include <stdio.h>
#include<conio.h>
#include <string.h>

int main() {

  int i;

 char cadena[5] = {'H','o','l','a','\0'};

  printf("%d",strlen(cadena));

  for(i=0; i<strlen(cadena); i++){

      printf("%c",cadena[i]);
      }
  getch();
  return 0;

}