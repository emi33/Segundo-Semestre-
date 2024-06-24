#include<stdio.h>
int main() {
int n=3;//
char datos[3][20]={"nombre","apellido","hora"};
char ingresar[3][20]={"Emiliano","Choque","1040"};
FILE *archivo;
archivo=fopen("primero.txt","w");
if (archivo==NULL){
printf("no puedo abrir archivo");
return 0;//
}
for (int i=0;i<n;i++){
printf("INGRESo %s", datos[i]);
fprintf(archivo, "%s\n", ingresar[i]);//
}
fclose(archivo);
return 0;
}
