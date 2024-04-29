#include <stdio.h>
#include <string.h>
#include <unistd.h>
typedef struct {
    int matematica;
    int fisica;
    int programacion;
} Nota;

void darNotas(struct Nota *notas){
    int n;
    printf("cargar nota matematica: ");
    scanf("%d", &(notas->matematica));
    printf("cargar nota fisica: ");
    scanf("%d", &(notas->fisica));
    printf("cargar nota programacion: ");
    scanf("%d", &(notas->programacion));
}
void mostrarNotas(struct Nota *notas){
    printf("mates:  %d\n", notas.matematica));
    printf("fis:  %d\n", &(notas.matematica));
    printf("program:  %d\n", &(notas->matematica));
}
int main(){
    Nota notas;
    darNotas(&notas);
    mostrarNotas(&notas); 
    printf("\n Matematica: %d", notas.matematica);
    printf("\n Fisica: %d", notas.fisica);
    printf("\n Programacion: %d", notas.programacion);
    sleep(5);
    return 0;
}