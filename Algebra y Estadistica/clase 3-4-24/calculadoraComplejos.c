#include <stdio.h>
#include <stdbool.h>

typedef struct {
	double real;
	double imag;
} Complejo;

Complejo ingresarComplejo() {
	Complejo c;
	printf("Ingrese la parte real: ");
	scanf("%lf", &c.real);
	printf("Ingrese la parte imaginaria: ");
	scanf("%lf", &c.imag);
	return c;
}

void imprimirComplejo(Complejo c) {
	if (c.imag >= 0)
		printf("%.0f + %.0fi\n", c.real, c.imag);
	else
		printf("%.0f - %.0fi\n", c.real, -c.imag);
}

void imprimirComplejoDivision(Complejo c) {
	if (c.imag >= 0)
		printf("%.2f + %.2fi\n", c.real, c.imag);
	else
		printf("%.2f - %.2fi\n", c.real, -c.imag);
}

Complejo sumarComplejos(Complejo num1, Complejo num2) {
	Complejo resultado;
	resultado.real = num1.real + num2.real;
	resultado.imag = num1.imag + num2.imag;
	return resultado;
}

Complejo restarComplejos(Complejo num1, Complejo num2) {
	Complejo resultado;
	resultado.real = num1.real - num2.real;
	resultado.imag = num1.imag - num2.imag;
	return resultado;
}

Complejo multiplicarComplejos(Complejo num1, Complejo num2) {
	Complejo resultado;
	resultado.real = num1.real * num2.real - num1.imag * num2.imag;
	resultado.imag = num1.real * num2.imag + num1.imag * num2.real;
	return resultado;
}

Complejo dividirComplejos(Complejo num1, Complejo num2) {
	Complejo resultado;
	double divisor = num2.real * num2.real + num2.imag * num2.imag;
	resultado.real = (num1.real * num2.real + num1.imag * num2.imag) / divisor;
	resultado.imag = (num1.imag * num2.real - num1.real * num2.imag) / divisor;
	return resultado;
}

int main() {
	int opcion;
	Complejo num1, num2, resultado;
	bool numerosIngresados = false;
	
	do {
		printf("\nCalculadora de Numeros Complejos\n");
		if (!numerosIngresados) {
			printf("1. Ingresar complejos\n");
			printf("0. Salir\n");
		} else {
			printf("1. Cambiar numeros\n");
			printf("2. Sumar\n");
			printf("3. Restar\n");
			printf("4. Multiplicar\n");
			printf("5. Dividir\n");
			printf("0. Salir\n");
		}
		printf("Seleccione una opcion: ");
		scanf("%d", &opcion);
		
		switch(opcion) {
		case 1:
			printf("Ingrese el primer numero complejo:\n");
			num1 = ingresarComplejo();
			printf("Ingrese el segundo numero complejo:\n");
			num2 = ingresarComplejo();
			numerosIngresados = true;
			break;
		case 2:
			if (numerosIngresados) {
				resultado = sumarComplejos(num1, num2);
				printf("El resultado de la suma es: ");
				imprimirComplejo(resultado);
			} else {
				printf("Debe ingresar los numeros complejos primero.\n");
			}
			break;
		case 3:
			if (numerosIngresados) {
				resultado = restarComplejos(num1, num2);
				printf("El resultado de la resta es: ");
				imprimirComplejo(resultado);
			} else {
				printf("Debe ingresar los numeros complejos primero.\n");
			}
			break;
		case 4:
			if (numerosIngresados) {
				resultado = multiplicarComplejos(num1, num2);
				printf("El resultado de la multiplicación es: ");
				imprimirComplejo(resultado);
			} else {
				printf("Debe ingresar los numeros complejos primero.\n");
			}
			break;
		case 5:
			if (numerosIngresados) {
				resultado = dividirComplejos(num1, num2);
				printf("El resultado de la división es: ");
				imprimirComplejoDivision(resultado);
			} else {
				printf("Debe ingresar los numeros complejos primero.\n");
			}
			break;
		case 0:
			printf("Saliendo...\n");
			break;
		default:
			printf("Opcion no valida\n");
		}
	} while (opcion != 0);
	
	return 0;
}
