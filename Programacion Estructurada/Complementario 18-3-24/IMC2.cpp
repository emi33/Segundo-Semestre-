#include <stdio.h>

void calcularIMC(float peso, float altura);

int main() {
	float peso, altura;
	
	printf("Ingrese su peso en kilogramos: ");
	scanf("%f", &peso);
	printf("Ingrese su altura en metros: ");
	scanf("%f", &altura);
	
	calcularIMC(peso, altura);
	
	return 0;
}

void calcularIMC(float peso, float altura) {
	
	if (peso && altura != 0) {
		float imc = peso / (altura * altura);
		printf("Su índice de masa corporal es: %.2f\n", imc);
	} else {
		printf("Error");
	}
	
	
	
	
}
