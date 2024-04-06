#include<stdio.h>
float dividir(float peso, float altura);
int main() {

	float peso, altura;
    bool val;
    do
    {
        val=false;
       scanf("%f", &peso);
	scanf("%f", &altura);
    if (peso>0 && altura >0)
    {
       val=true;
    }
    
    } while (val);
    
	

	float indice = dividir(peso, altura);
	printf("Su indice de masa corporal: %.2f",indice);
	return 0;
}

float dividir(float peso, float altura) {
	float imc = peso / (altura * altura);
	return imc;
}