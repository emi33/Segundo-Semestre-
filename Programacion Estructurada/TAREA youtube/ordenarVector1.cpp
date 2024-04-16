#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//recibimos un vector de enteros desordenado y lo ordenamos de menor a mayor
int main (int argc, char *argv[]){
	int vector[]={99,800,15,3,15,800,6,800,0};
	//99,800,15,3,15,800,6,800,0 primera vuelta del primer for
	int longitud, j,aux, i,mayor,posicion,n;
	longitud=8;
	n=0;
	printf("vector desordenado \n");
	for (i=0;i<=longitud;i++){
		printf("%d \n", vector[i]);
	}
	for (i=0; i<=longitud;i++){
		posicion=0;
		mayor = vector[0];
		for (j=0; j<=longitud-n; j++){
			//std::cout<<"vectors en posicion "<<j<< ": " << vector[j]<< std::endl;
			if (mayor<vector[j]){
				mayor=vector[j];//5
				posicion= j;//3
			}
		}
		aux = vector[longitud-n];
		vector[longitud-n]= mayor;
		vector[posicion]=aux;
		n++;
	}
	printf("vector ordenado \n");
	for (i=0;i<=longitud;i++){
		printf("%d \n", vector[i]);
	}
	system("pause");
	return 0;
}
