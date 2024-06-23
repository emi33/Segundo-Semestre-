//TNA: INGRESA UN NUMERO Y CALCULA EL TNA(70%) ANUAL Y MENSUAL
#include<stdio.h>
#include<conio.h>
float pedirtna(){
    return 0.7;
}
void mes(float deposito, float *mensual, float tna){
    *mensual=deposito*tna/365*30;
}
void anual(float deposito, float *fijo, float tna){
    *fijo=deposito*tna;
}
int main(){
    float tna, fijo=0, mensual=0, deposito;
    tna= pedirtna();
    printf("tna actual: %.2f % \n", tna*100);
    printf("ingrese un monto a calcular: ");
    scanf("%f", &deposito);
    mes(deposito, &mensual, tna);
    anual(deposito, &fijo, tna);
    printf("su total anual es: %.2f y su total mensual es %.2f", fijo, mensual);
    getch();
    return 0;
}