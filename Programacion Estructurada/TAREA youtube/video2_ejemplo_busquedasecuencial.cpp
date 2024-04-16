//busqueda secuencial
#include <stdio.h>
#include <stdlib.h>

int busquedaSecuencial(int vector[], int dato);

int main(int argc, char *argv[]) {
	int vector[]={1,9,2,8,3,7,4,6,5,0};
	int x, result;
	printf("ingrese un numero del 0 al 9: ");
	scanf("%d", &x);
	result = busquedaSecuencial(vector,x);
	if (result!=-1){
		printf("el valor %d ingresado esta en la posicion %d . \n", x, result);
	} else {
		printf("el valor %d no se encontro en el vector. \n", x);
	}
	system("pause");
	
	return 0;
}
int busquedaSecuencial(int vector[], int dato){
	int i;
	for(i=0;i<=100;i++){
		if (vector[i]==dato){
			return i;
		}
		
	}
	return -1;
}
