#include <stdio.h>
#include <conio.h>

int main() {
    long long int suma;
    suma=0.0;
    long double promedio;
    promedio = 0.0;
    int contador = 0;
    for (long long int i = 256; i < 3425625; i++) {
        suma += i;
        contador++;
    }
    printf("El resultado de la suma es %lli\n", suma);
    promedio = suma / contador;
    printf("El resultado del promedio es %llf\n", promedio);
    getch();
    return 0;
}