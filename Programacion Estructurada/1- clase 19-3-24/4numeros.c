// ingresar 4 numeros y calcular menor, mayor y promedio
#include <stdio.h>
#include <conio.h>
void writenum(char palabra[4][10], int numeros[4], double *promedio)
{
    int suma = 0, contador = 0;
    for (int i = 0; i < 4; i++)
    {
        printf("Ingrese el %s numero: ", palabra[i]);
        scanf("%d", &numeros[i]);
        suma += numeros[i];
        contador++;
    }
    *promedio = (double)suma / 4;
}
void mayormenor(int numeros[4], int *mayor, int *menor)
{
    for (int i = 1; i < 4; ++i)
    {
        int key = numeros[i];
        int j = i - 1;

        while (j >= 0 && numeros[j] < key)
        {
            numeros[j + 1] = numeros[j];
            j = j - 1;
        }
        numeros[j + 1] = key;
    }
    for (int i = 0; i < 4; i++)
    {

        printf("NUEVO ARREGLO: %d\n", numeros[i]);
    }
    *mayor = numeros[0];
    *menor = numeros[3];
}
int main()
{
    int numeros[4];
    int mayor = 0, menor = 0;
    double promedio;
    char palabra[4][10] = {{"primer"}, {"segundo"}, {"tercero"}, {"cuarto"}};
    writenum(palabra, numeros, &promedio);
    mayormenor(numeros, &mayor, &menor);
    for (int i = 0; i < 4; i++)
    {
        printf("%s: %d\n", palabra[i], numeros[i]);
    }
    printf("Calculo promedio: %f\n", promedio);
    printf("numero mayor: %d\n", mayor);
    printf("numero menor: %d\n", menor);
    getch();
    return 0;
}