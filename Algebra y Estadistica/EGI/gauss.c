#include<stdio.h>
#include<conio.h>
int main(){
    int fibo=0;
    int suma=0;
    int suma2=0;
    int auxiliar=0;
    int sig=1;
    int i=0;
    double contador=1.0;
    double promedio=0.0;
    for (i = 0; i < 14; i++)
    {
        suma=sig+fibo;//1/2
        fibo=sig;//1/
        sig = suma;//1/
        contador++;
        suma2+=fibo;
        promedio =(double)suma2/contador;
        printf("suma numero %d : %d\n", i+1, suma);
        printf("promedio hasta aca: %f\n", promedio);
    }
    getch();
    return 0;
}
