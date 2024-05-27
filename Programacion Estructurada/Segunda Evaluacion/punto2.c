#include <stdio.h>
#include<conio.h>
int main(void){
    int a=10, b;
    while (a>0)
    {
        b=a-1;
        printf("el resultado es %i ",b);// muestra los valores de 9 a 0
        a=a-1; 
    }
    getch();
    return 0;
    
}