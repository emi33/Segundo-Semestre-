#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include <string>
#include <chrono>
#include <cstdlib>
#include <thread>
#include <Windows.h>
#include <sstream>
bool val = false, flag = true;
std::string string_a, string_b;
typedef struct {
	double real;
	double imag;
} Complex;
Complex num1, num2, result;
void bienvenida()
{
    std::cout << "---------------------------------------------------"
              << std::endl;
    std::cout << "---------------------------------------------------"
              << std::endl;
    std::cout << "---------------------------------------------------"
              << std::endl;
    std::cout << "---------------------------------------------------"
              << std::endl;
    std::cout << "-----------Bienvenido al Programa Menu-------------"
              << std::endl;
    std::cout << "---------------------------------------------------"
              << std::endl;
    std::cout << "---------------------------------------------------"
              << std::endl;
    std::cout << "---------------------------------------------------"
              << std::endl;
    std::cout << "---------------------------------------------------"
              << std::endl;
    Sleep(2000); // Needs #include <Windows.h>
    system("cls");
};
void menu(int reduccion, const std::string arr[])
{
    for (int i = 0; i < reduccion; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
};

int printComplex(Complex numero)
{
    char sign;
    if (numero.imag < 0)
    {
        sign = '-';
    }
    else
    {
        sign = '+';
    }

    std::cout << numero.real << " " << sign << " " << std::abs(numero.imag) << "i" << std::endl;
    return 0;
};
bool esDouble(const std::string &str)
{
    std::istringstream iss(str);
    double resultado;
    return iss >> resultado && iss.eof();
};
Complex transformComplex(std::string z)
{
    Complex c;
    double a, b;
    bool flag_b;
    char s;
    flag_b = true;
    while (flag_b) 
    {
        size_t pos = z.find_first_of("+-");

        if (pos != std::string::npos)
        {
            s = z[pos];
            // Si se encontró un signo "+ o "-", cortar la cadena y mostrar las partes
            std::string primera_parte = z.substr(0, pos);
            std::string segunda_parte = z.substr(pos + 1, z.size() - pos - 2);
            if (esDouble(primera_parte) && esDouble(segunda_parte))
            {
                std::cout << "La cadena representa un número double válido." << std::endl;
                
                flag_b = false;
                a = std::stod(primera_parte);
                b = std::stod(segunda_parte);
                if (s == '-')
                {
                    b = -b;
                }
            }
            else
            {
                std::cout << "La cadena no representa un número double válido." << std::endl;
                std::getline(std::cin, z);
            }
            std::cout << "Primera parte: " << primera_parte 
            << "Segunda Parte "<< segunda_parte  << std::endl;
            Sleep(2000);
        }
        else
        {
            // Si no se encontró un signo "+ o "-", mostrar el mensaje
            std::cout << "No se encontró ningún signo '+' o '-' en la cadena." << std::endl;
            std::getline(std::cin, z);
        }
    }
    c.real = a;
    c.imag = b;
    return c;
};
int readComplex()
{
    std::string valora,valorb;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese el primer numero complejo en la forma a+bi:" << std::endl;
    std::getline(std::cin, string_a);
    valora= string_a;
    num1 = transformComplex(valora);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese el segundo numero complejo en la forma a+bi:" << std::endl;
    std::getline(std::cin, string_b);
    valorb= string_b;
    num2 = transformComplex(valorb);
    return 0;
};
int main()
{
    bienvenida();
    int opMenu = -1;
    std::string numeros[6] = {"0- Salir", "1- Ingresar Complejos", "2- Suma", "3- Resta", "4- Multiplicar", "5- Dividir"};

    while (opMenu != 0)
    {
        std::cout << "----------------------Calculos Complejos---------------------" << std::endl;
        if (flag)
        {
            menu(2, numeros);
            scanf("%d", &opMenu);
            if (opMenu == 1)
            {
                // leer complejos menu reducido
                std::cout << "----------------------leer complejos menu reducido---------------------" << std::endl;
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
        std::cout << "PRIMER NUMERO " << std::endl;
        printComplex(num1);
        std::cout << "SEGUNDO NUMERO " << std::endl;
        printComplex(num2);
        Sleep(65000); // Needs #include <Windows.h>
        system("cls");
    }
    return 0;
};