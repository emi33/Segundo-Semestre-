#include<stdio.h>
#include<conio.h>
float fc(float a, int b, char c);
int main(){
    float n1=5.5;
    int n2=4.0;
    char le;
    printf("n1 :%d",n2);
    printf("n2 :%f",n1);
    printf("\nel resultado es: %f:", fc(n1,n2,le));//esta linea que agregamos es la correcta
    printf ("\nel resultado es %f:", fc(n2,n1,le));// esta linea tambien da resultado pero redondea el valor a 9 
    getch();
    return 0;
}
float fc(float a, int b, char c){
    c='k';
    printf("\nn1 :%f",a);
    printf("\nn2 :%d",b);
    float d=a+b;
    return a+b;
}
