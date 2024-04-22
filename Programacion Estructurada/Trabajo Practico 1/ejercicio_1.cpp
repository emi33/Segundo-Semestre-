/*Escribir código en lenguaje C que convierta una cadena de textos a mayúsculas o minúsculas 
según corresponda. Ejemplo: Para la cadena de entrada  "hola", si elijo la opción convertir 
a mayúsculas la salida del programa debe mostrar "HOLA". Para la cadena de entrada  "HOLA", 
si elijo la opción convertir a minúsculas La salida del programa debe mostrar "hola" .
Se debe contemplar también el caso en que solo deseamos la primer letra de la cadena en 
mayúsculas (Tipo Oración)*/
#include <stdio.h>
#include <Windows.h>

void menu()
{
    printf("convertir texto a: \n");
    printf("1- Mayusculas\n");
    printf("2- Minusculas\n");
    printf("3- Tipo Oracion\n");
}
char *mayusminus(char *texto, char num)
{
    int i = 0;
    bool flag=true;
    switch (num)
    {
    case '1':
        while (texto[i] != '\0')
        {
            if (texto[i] >= 'a' && texto[i] <= 'z')
            {
                texto[i] = texto[i] - 32; // Convertir a mayúsculas
            }
            i++;
        }
        break;
    case '2':
        while (texto[i] != '\0')
        {
            if (texto[i] >= 'A' && texto[i] <= 'Z')
            {
                texto[i] = texto[i] + 32; // Convertir a MINUSCULAS
            }
            i++; 
        }
        break;
    case '3':
        while (flag)
        {
            if (texto[i] >= 'a' && texto[i] <= 'z'){
            texto[i] = texto[i] - 32;
            flag=false;
            }
            i++;
        }
        break;
    }
    
    return texto;
}
int main()
{
    char *texto = new char[60];
    char *modificado = new char[60];
    char n;
    bool flag = false;
    printf("escribe un texto: ");
    scanf("%99[^\n]", texto);
    printf("You entered: %s\n", texto);
    
    do
    {
        menu();
        scanf(" %c", &n);
        switch (n)
        {
        case '1':

            printf("excelente! convertimos todo a mayusculas");
            modificado= mayusminus(texto, n);
            printf("Texto en mayusculas: %s\n", modificado);
            break;
        case '2':
            printf("excelente! convertimos todo a minusculas");
            modificado= mayusminus(texto, n);
            printf("Texto en minusculas: %s\n", modificado );
            break;
        case '3':
            printf("excelente! convertimos primer letra a mayuscula");
            modificado= mayusminus(texto, n);
            printf("Primer letra mayuscula: %s\n", modificado);
            break;
        default:
            printf("error en valor ingresado. Intente nuevamente");
            flag = true;
            break;
        }
    } while (flag);

    system("pause");
    return 0;
}