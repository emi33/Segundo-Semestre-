// Guardar artÃ­culos y cantidades vendidas de dicho artÃ­culo.

// Cada artÃ­culo se diferencia por un cÃ³digo de artÃ­culo con valores enteros de 1 a 15.

// Una vez cargadas todas las ventas dar el artÃ­culo mÃ¡s vendido
#include <stdio.h>
#include <string.h>
int main()
{
	int art[5][2] = {

		{1, 10},

		{2, 200},

		{3, 19},

		{4, 22},

		{5, 32}}; // primera columna es codigo de articulo y segunda columna es cantidad vendida, se pueden ingresar mas articulos

	int mayor, i, vendido;

	mayor = art[1][2];

	for (i = 0; i < 5; i++)
	{

		if (art[i][1] > mayor)
		{

			mayor = art[i][1];

			vendido = art[i][0];
		}
	}
	printf("El articulo con mas ventas es %d con %d cantidades vendidas", vendido, mayor);
}
