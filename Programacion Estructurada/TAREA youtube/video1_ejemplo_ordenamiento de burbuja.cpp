//ordenamiento de burbuja
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int vector[]={8,5,2,6,12};
	int i,y,aux;
	int n=5;
	for (i=0;i<n-1;i++){
		for (y=0; y<n-i-1;y++){
			//comparacion de dos valores 
			if (vector[y]>vector[y+1]){
				aux=vector[y];
				vector[y]=vector[y+1];
				vector[y+1]=aux;
			}
		}
	}
	printf("vector ordenado \n");
	for (i=0;i<n;i++){
		printf("%d \n", vector[i]);
	}
	system("pause");
	
	return 0;	
}

