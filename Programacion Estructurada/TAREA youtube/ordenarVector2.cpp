//VECTOR DE CARACTERES --aunque incluye numeros--
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
int main (int argc, char *argv[]){
	char vector[]="3665"; //se pueden probar con letras y numeros
	int longitud,i,j,posicion,n;	
	char car, aux, mayor; //auxiliares para guardar caracteres
	longitud=3; //sizeof de vector sin contar el ultimo valor /0 porque nos salen errores. tiene que coincidir
	printf("vector desordenado \n");
	for (i=0;i<=longitud;i++){
		std::cout<< vector[i]<< std::endl;
	}
	n=0;//auxiliar para restar elementos de un array
	for (i=0;i<=longitud;i++){//primer for en donde leemos cada elemento 0 - 3
		posicion=0;
		mayor = vector[0];
		for (j=0; j<=longitud-n; j++){//for para obtener el mayor valor de una determinada longitud de elementos
			if (mayor<vector[j]){
				mayor=vector[j];
				posicion= j;
				//std::cout<<"posicion: "<< posicion<< std::endl;
			}
		}
		//std::cout<<"mayor: "<< mayor<< std::endl;
		aux = vector[longitud-n];//5
		//std::cout<<"auxiliar: "<< aux << std::endl;
		vector[longitud-n]= mayor;//6
		//std::cout<<"ultimo: "<< vector[longitud-n]<< std::endl;
		vector[posicion]=aux;
		//std::cout<<"vector cambiado: "<< vector[posicion]<< std::endl;
		n++;
	} 
	printf("vector ordenado \n");
	for (i=0;i<=longitud;i++){
		std::cout<< vector[i]<< std::endl;
	}
	system("pause");
	return 0;
}
