//busquedabinaria
#include <stdio.h>
#include <stdlib.h>

int busquedaBinaria(int vector[], int n, int dato);
int main (int argc, char *argv[]){
	
	int vector[]={1,4,6,8,9,10,15,16,18,19,22};
	int n=11; //cantidad de elementos del vector;
	int dato, result;
	printf("ingrese el valor a buscar: ");
	scanf("%d",&dato);
	result= busquedaBinaria(vector, n, dato);
	if (result!=-1){
		printf("el valor buscado %d esta en la posicion %d del vector.\n", dato,result);
	}
	else{
		printf("el valor buscado %d no se encuentra en el vector.\n", dato);
	}
	system("pause");
	return 0;
}
	
int busquedaBinaria(int vector[], int n, int dato){
	int sup, inf, centro;
	inf=0;
	sup=n-1;
	while (inf<=sup){
		centro=((sup-inf)/2)+inf;
		if (dato==vector[centro]){
			return centro;
		}
		if (dato<vector[centro]){
			sup=centro -1;
		}
		else{
			inf=centro +1;
		}
	}
	return -1;
}
