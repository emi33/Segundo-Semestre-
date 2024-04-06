#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include <string>
#include <chrono>
#include <cstdlib>
#include <thread>
#include <Windows.h>
int bienvenida();
void menu(int reduccion, const std::string arr[]);
bool val = false, flag = true;
int main()
{
    bienvenida();
    int opMenu = -1;
    std::string numeros[6] = {"0- Salir", "1- Ingresar Complejos", "2- Suma", "3- Resta", "4- Multiplicar", "Eliga su opción(0-5)"};
    while (opMenu != 0)
    {
        printf("Calculos Complejos\n");

        if (flag = false)
        {
            menu(2, numeros);
            scanf("%d", &opMenu);
            if (opMenu == 1)
            {
                // leer complejos menu reducido
                printf("luego");
            }
            else
            {
                if (opMenu != 0)
                {
                    printf("no valida");
                }
            }
        }
        else
        {
            menu(6, numeros);
            scanf("%d", &opMenu);
            // menu completo
            switch (opMenu)
            {
            case 0:
                break;
            case 1:
                printf("luego");
            case 2:
                printf("sumar luego");
            case 3:
                printf("restar luego");
            case 4:
                printf("multiplicar luego");
            case 5:
                printf("dividir luego");
            default:
                printf("opcion no valida");
            }
        }
    }

    return 0;
}

void menu(int reduccion, const std::string arr[])
{
    for (int i = 0; i < reduccion; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}
int bienvenida()
{
    std::cout << "---------------------------------------------------\n"
              << std::endl;
    std::cout << "---------------------------------------------------\n"
              << std::endl;
    std::cout << "---------------------------------------------------\n"
              << std::endl;
    std::cout << "---------------------------------------------------\n"
              << std::endl;
    std::cout << "-----------Bienvenido al Programa Menu-------------\n"
              << std::endl;
    std::cout << "---------------------------------------------------\n"
              << std::endl;
    std::cout << "---------------------------------------------------\n"
              << std::endl;
    std::cout << "---------------------------------------------------\n"
              << std::endl;
    std::cout << "---------------------------------------------------\n"
              << std::endl;
    Sleep(2000); // Needs #include <Windows.h>
    system("cls");
}

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
				printf("El resultado de la multiplicaci�n es: ");
				imprimirComplejo(resultado);
			} else {
				printf("Debe ingresar los numeros complejos primero.\n");
			}
			break;
		case 5:
			if (numerosIngresados) {
				resultado = dividirComplejos(num1, num2);
				printf("El resultado de la divisi�n es: ");
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
