#include <stdio.h>
#include <iostream>
int main()
{
	char a;
	int num;
    // escribir valor
	std::cout <<  "Introduce un numero: "<< std::endl;
	std::cin.get(a);

    for (int i = 65; i < 91; i++)
    {
        int s = i; // A valor en codigo ascii
        char car = char(s);
        //printf("%c", car);
        if (car == a)
        {
			std::cout<< a <<std::endl;
            printf("letra correcta posicion: ");
			std::cout<< i <<std::endl;
        }
    }
	
	for (int i = 97; i< 123; i++){
		int s = i; // La ó en código ASCII
		char car = char(s);
		//printf("%c", car);
		if (car == a)
		{
			std::cout<< a <<std::endl;
			printf("letra correcta posicion: ");
			std::cout<< i <<std::endl;
		}
	}

    return 0;
}
