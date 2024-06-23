//pedir tna, INGRESAR DINERO, CACULAR TOTAL ANUAL Y TOTAL MENSUAL
#include<stdio.h>
float tasaanual(float peso, float altura);

float pedirtna();
float tasaanual(float fjo) ;
float mensual(float valor); 
int main() {
    float tna, valor, fijo, men;

    tna=pedirtna();
    printf("TNA Actual: %.f % \n",tna*100);
    printf("ingrese la cantidad que desea depositar:");
    scanf("%f", &valor);
    fijo= tasaanual(valor);
    men= mensual(valor);
    printf("su total anual es: %.2f", fijo);
     printf("su total mensual es: %.2f", men);
}

float tasaanual(float fjo) {
	fjo += fjo*0.7;
	return fjo;
}
float mensual(float valor){
    float mes= valor + valor*0.7/365*30;
    return mes;
}
float pedirtna(){
    return 0.7;
}
