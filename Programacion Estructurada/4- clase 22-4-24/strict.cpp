#include <stdio.h>
#include <iostream>
#include <cstring>
#include <Windows.h>
#include <iomanip>
#include <string.h>
struct alumno
{
    char nombre[10];
    char apellido[10];
    int edad;
    char direccion[10];
    int notas[4];
    float promedio;
};

int main()
{
    alumno alumno[100];
    char aux[10], aux2[10], aux3[10];
    int a;
    bool flag=true;
    int val, i, j, k;
    j = 0;
    do
    {
        a = 0;
        std::cout << "alumno " << j + 1 << ": " << std::endl;
        printf("ingrese nombre: ");
        std::cin >> aux;
        printf("ingrese apellido: ");
        std::cin >> aux2;
        printf("edad: ");
        std::cin >> alumno[j].edad;
        printf("direccion: ");
        std::cin >> aux3;
        printf("ingrese todas las notas: ");
        for (i = 0; i < 4; i++)
        {
			std::cout << "nota " << i+1 << ": " <<std::endl;
			std::cin >> alumno[j].notas[i];
            a = a + alumno[j].notas[i];
        }
        alumno[j].promedio = (float)a / 4;
        strcpy(alumno[j].nombre, aux);
        strcpy(alumno[j].apellido, aux2);
        strcpy(alumno[j].direccion, aux3);
        std::cout << "quiere ingresar otro alumno? 1- si 2- no " << std::endl;
        std::cin >> val;
        if (val == 2)
        {
            flag = false;
        }

        j++;
    } while (flag);
    for (k = 0; k < 10; k++)
    {
        std::cout << alumno[k].nombre << std::endl;
        std::cout << alumno[k].apellido << std::endl;
        std::cout << alumno[k].edad << std::endl;
        std::cout << alumno[k].direccion << std::endl;
        for (int i = 0; i < 4; i++)
        {
            std::cout << "nota " << i+1 << ": " <<std::endl;
            std::cout << alumno[k].notas[i] << std::endl;
        }
		std::cout << std::setprecision(1) << alumno[k].promedio << std::endl;
    }

    system("pause");
    return 0;
}
