#include<stdio.h>
#include<conio.h>
int main(){
    int fibo=0;
    int suma=0;
    int auxiliar=0;
    int sig=1;
    int i=0;
    float promedio=0.0;
    for (i = 0; i < 14; i++)
    {
        suma = sig+fibo;//0+1/2
        fibo=sig;//1/
        sig = suma;//1/
        promedio =(float)suma/i;
        printf("suma numero %d : %d\n", i+1,suma);
        printf("promedio hasta aca:%f\n",promedio);
    }
    
    
    
    getch();
    return 0;
}
