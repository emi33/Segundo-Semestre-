//indice de masa corporal, ingrese su peso y altura y calcule indice de masa corporal
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
float dividir(float peso, float altura);
int main()
{
    float peso, altura;
    bool val=true;
    do
    {
        printf("ingrese su peso: ");
        scanf("%f", &peso);
        printf("ingrese su altura: ");
        scanf("%f", &altura);
        if (peso > 0 && altura > 0)
        {
            val = false;
        }
    } while (val);
    float indice = dividir(peso, altura);
    printf("Su indice de masa corporal: %.2f", indice);
    getch();
    return 0;
}

float dividir(float peso, float altura)
{
    float imc = peso / (altura * altura / (100 * 100));
    return imc;
}