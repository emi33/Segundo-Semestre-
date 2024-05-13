#include <stdio.h>
struct persona {
    char nombre[50];
    int edad;
};
struct rodaje {
    char lugar[256];
    float presupuesto;
};
struct pelicula {
    struct persona director;
    struct persona actor1;
    struct persona actor2;
    struct rodaje datos;
};
struct fraccion {
    int num;
    int den;
};
void producto (struct fraccion f1, struct fraccion *result, struct fraccion f2){
    (*result).num = f1.num * f2.num;
    (*result).den= f1.num * f2.den;
}
int main(void){
    struct pelicula mi_pelicula;
    strcpy(mi_pelicula.director.nombre, "almodovar");
    printf("%s\n",mi_pelicula.director.nombre);
    struct fraccion a={2,5}, b={3,5}, prod;
    producto(a,&prod,b);
    int algo[10]={1,2,3,4,5,6,7,8,9,10};
    for (int i = 0; i <= 10; i++)
    {
        printf("%i", algo[i]);
    }
    
    return 0;
}