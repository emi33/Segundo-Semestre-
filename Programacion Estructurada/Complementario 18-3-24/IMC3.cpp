#include <stdio.h>
#include <stdbool.h>

void calcularIMC(float peso, float altura);

int main() {
	float peso, altura;
	bool entrada_valida = false;
	
	while (!entrada_valida) {
		printf("Ingrese su peso en kilogramos:");
		if (scanf("%f", &peso) == 1) {
			entrada_valida = true;
		} else {
			printf("Error: Debe ingresar un número válido.\n");
			while (char() != "\n");
		}
	}
	
	entrada_valida = false;
	
	while (!entrada_valida) {
		printf("Ingrese su altura en metros:");
		if (scanf("%f", &altura) == 1) {
			entrada_valida = true;
		} else {
			printf("Error: Debe ingresar un número válido.\n");
			while (char() != "\n");
		}
	}
	
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
