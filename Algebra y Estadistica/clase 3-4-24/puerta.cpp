#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include <string>
#include <chrono>
#include <cstdlib>
#include <thread>
#include <Windows.h>
void bienvenida();
void menu(int reduccion, const std::string arr[]);
bool val = false, flag = true;
char string_a[200], string_b[200];

typedef struct
{
    double real;
    char sign;
    double imag;
} Complex;
Complex num1, num2, result;
Complex transformComplex(char z[])
{
    Complex c;
    double a, b;
    char s;
    bool flag_b = true;
    while (z != NULL && flag_b == true)
    {
        if (sscanf(z, "%d, %c, %di", &a, &s, &b) == 3)
        {
            if (s = '+'){
                c = {a,s,  b};
                flag_b = false;
            } else if (s='-')
            {
                c= {a,s,-b};
                flag_b = false;
            }else{
                fprintf(stderr, "Error de signos\n");
            }
        }
        else
        {
            fprintf(stderr, "No está escrito en la forma a+bi\n");
            fprintf(stderr, "Escribir nuevamente: \n");
            std::cin.getline(z, 200);
        }
        return c;
    }
}
void readComplex()
{
    printf("Ingrese el primer numero complejo en la forma a+bi:\n");
    std::cin.getline(string_a, 200);
    num1 = transformComplex(string_a);
    printf("Ingrese el segundo numero complejo en la forma a+bi:\n");
    std::cin.getline(string_b, 200);
    num2 = transformComplex(string_b);
};

int main()
{
    bienvenida();
    int opMenu = -1;
    std::string numeros[6] = {"0- Salir", "1- Ingresar Complejos", "2- Suma", "3- Resta", "4- Multiplicar", "5- Dividir"};

    while (opMenu != 0)
    {
        printf("-------------Calculos Complejos------------\n");
        if (flag)
        {
            menu(2, numeros);
            scanf("%d", &opMenu);
            if (opMenu == 1)
            {
                // leer complejos menu reducido
                printf("LEER COMPLEJOS EN MENU REDUCIDO\n");
                readComplex();
                flag = false;
            }
            else
            {
                if (opMenu != 0)
                {
                    printf("SALIR EN MENU REDUCIDO");
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
                printf("LUEGO IMAGINARIOS EN MENU COMPLETO");
                readComplex();
                break;
            case 2:
                printf("sumar luego");
                break;
            case 3:
                printf("restar luego");
                break;
            case 4:
                printf("multiplicar luego");
                break;
            case 5:
                printf("dividir luego");
                break;
            default:
                printf("opcion no valida");
                break;
            }
        }
        std::cout << "El numero 1 es: " << num1.real <<num1.sign<<num1.imag<<"i"  << std::endl;
       std::cout << "El numero 1 es: " << num2.real <<num2.sign<<num2.imag<<"i"  << std::endl;
        Sleep(2000); // Needs #include <Windows.h>
        system("cls");
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
void bienvenida()
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
