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

