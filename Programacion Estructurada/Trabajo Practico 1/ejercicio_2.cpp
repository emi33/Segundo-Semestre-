/*Dado un vector con nombres de personas. Escribir código en
C que permita ordenar alfabéticamente (ascendente y descendente)
los elementos del vector*/
#include <iostream>
#include <cstring>
#include <Windows.h>
int main()
{
    bool flag;
    char names[10][100], aux[100];
    int i, j, k;
    for (i = 1; i <= 10; i++)
    {
        flag = true;
        while (flag)
        {
            k=0;
            std::cout << i << ". ";
            std::cin >> aux;
            std::size_t longitud = std::strlen(aux);
            
            if (aux[0] >= 'A' && aux[0] <= 'Z')
            {
                
                for (j=1;j<longitud;j++){ 
                    if (aux[j]>='a' &&aux[j]<='z'){
                        k++;
                        
                    }     
                }
                if ((longitud - k) == 1 ){
                    flag = false;
                    strcpy(names[i - 1], aux);
                } else {
                    printf("Error con las mayusculas. Primer letra solo en mayuscula. \n");
                }
                
            }
            else
            {
                printf("Error nombre mal ingresado. \n");
            }
        }
    }
    for (i = 0; i < 9; i++)//FOR PARA RECORRER LOS 10 NOMBRES
    {                                
        for (int j =  i + 1; j < 10; j++) //FOR PARA MOVER NOMBRE
        {
            if (strcmp(names[i], names[j]) >0)//compara primer elemento con los sig elementos del array
            {
                strcpy(aux, names[i]); // copiamos el nombre en la pos i a auxiliar
                strcpy(names[i], names[j]); // intercambiamos lugar de elementos
                strcpy(names[j], aux); //completamos intercambio
            }
        }   
    }
    std::cout << "Nombres ordenados de forma ascendente:\n";
    for (int i = 0; i < 10; i++)
    {
        std::cout << names[i] << std::endl;
    }
    for (i = 0; i < 9; i++)//FOR PARA RECORRER LOS 10 NOMBRES
    {                                
        for (int j =  i + 1; j < 10; j++) //FOR PARA MOVER NOMBRE
        {
            if (strcmp(names[i], names[j]) <0)//compara primer elemento con los sig elementos del array
            {
                strcpy(aux, names[i]); // copiamos el nombre en la pos i a auxiliar
                strcpy(names[i], names[j]); // intercambiamos lugar de elementos
                strcpy(names[j], aux); //completamos intercambio
            }
        }   
    }
    std::cout << "Nombres ordenados de forma descendente:\n";
    for (int i = 0; i < 10; i++)
    {
        std::cout << names[i] << std::endl;
    }
    system("pause");
}