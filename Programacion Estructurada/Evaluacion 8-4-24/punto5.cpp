//Haga un programa en C que inicialice y cargue valores en un vector. Maximo 10 lineas de codigo.
#include <iostream>
int main()
{
	char vectores[5];
	for(int i = 0; i < 5; i++)
	{
		std::cout << "ingrese valor en la posicion " << i + 1 <<": " << std::endl;
		std::cin >> vectores[i];
	}
}
